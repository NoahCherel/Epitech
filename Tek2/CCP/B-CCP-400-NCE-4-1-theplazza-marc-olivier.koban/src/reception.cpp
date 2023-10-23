/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** reception
*/

#include "../inc/plazza.hpp"

Reception::Reception(int CookingTimeMult, int nbOfKitchenCooks, int time) : CookingTimeMult_(CookingTimeMult), numKitchenCooksPerKitchen_(nbOfKitchenCooks), TimePizza_(time) {}
Reception::~Reception() { delete sharedMemory_; }

void Reception::Input_handling()
{
    initializeSharedMemory();
    while (true) {
        std::string input = readInput();
        if (input.empty()) throw ErrorHandling("Invalid input");
        if (input == "status") ShowKitchenStatus();
        else if (input == "exit") break;
        else
        {
            handlePizzas(input);
            PIzzaOrderToKitchen();
        }
        input.erase();
    }
}

void Reception::initializeSharedMemory()
{
    sharedMemory_ = new SharedMemoryThread();
    SharedMemoryThroughtThread_ = MemSharedGet();
}

std::string Reception::readInput()
{
    std::string input;
    std::getline(std::cin, input);
    return input;
}

void Reception::handlePizzas(std::string &input)
{
    static std::regex const parser("^([a-zA-Z]+)\\s{1}(S|M|L|XL|XXL)\\s{1}x(\\d+)$");
    std::string separator = ";";
    std::istringstream iss(input);
    std::string order;
    try {
        while (std::getline(iss, order, ';')) {
            size_t start = order.find_first_not_of(" \t");
            size_t end = order.find_last_not_of(" \t");
            if (start != std::string::npos && end != std::string::npos) {
                order = order.substr(start, end - start + 1);
                std::smatch match;
                if (std::regex_search(order, match, parser)) {
                    std::string name = match[1];
                    std::string OrderSize = match[2];
                    int quantity = std::stoi(match[3]);
                    SetupOrder(name, OrderSize, quantity);
                } else {
                    throw std::runtime_error("'" + order + "' : Wrong Syntax!");
                }
            }
        }
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

void Reception::SetupOrder(std::string OrderType, std::string OrderSize, int nb)
{
    std::map<std::string, Type> typeMap = {
        {"regina", Type::Regina},
        {"margarita", Type::Margarita},
        {"americana", Type::Americana},
        {"fantasia", Type::Fantasia}
    };

    std::map<std::string, Size> sizeMap = {
        {"S", Size::S},
        {"M", Size::M},
        {"L", Size::L},
        {"XL", Size::XL},
        {"XXL", Size::XXL}
    };

    if (nb <= 0)
        throw ErrorHandling(std::to_string(nb) + " : " + "Wrong Quantity!");

    auto typeIt = typeMap.find(OrderType);
    if (typeIt == typeMap.end())
        throw ErrorHandling("'" + OrderType + "' : " + "Wrong Name!");

    auto sizeIt = sizeMap.find(OrderSize);
    Size newSize = (sizeIt != sizeMap.end()) ? sizeIt->second : Size::XXL;

    for (int i = 0; i < nb; i++) {
        PlazzaClass* pizza = new PlazzaClass(typeIt->second, newSize);
        _orders.push_back(pizza);
    }
}

void Reception::ShowKitchenStatus() const noexcept
{
    std::cout << "Kitchens Status :" << std::endl;

    for (int i = 0; i < 100; i++) {
        std::unique_lock<std::mutex> Ingredients_mutex(SharedMemoryThroughtThread_->mutex);
        const auto& kitchenStatus = SharedMemoryThroughtThread_->kitchenStatus[i];

        if (kitchenStatus[0] != -1) {
            std::cout << "KitchenClass nb " << i + 1 << " : " << std::endl;
            std::cout << "Cooks Active [" << numKitchenCooksPerKitchen_ - kitchenStatus[0] << "/" << numKitchenCooksPerKitchen_ << "]" << std::endl;

            const std::string ingredients[] = {
                "dough", "tomato", "gruyere", "ham", "mushrooms",
                "steak", "eggplant", "goat cheese", "chief love"
            };

            for (int j = 1; j < std::size(kitchenStatus); j++) {
                std::cout << ingredients[j - 1] << ": " << kitchenStatus[j] << std::endl;
            }
        }

        Ingredients_mutex.unlock();
    }
}

void Reception::PIzzaOrderToKitchen() noexcept
{
    while (!_orders.empty()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        int kitchen = findAvailableKitchen();
        if (kitchen != -1) {
            PizzaToBuf(kitchen, _orders.back());
            _orders.pop_back();
        } else {
            startNewKitchen();
        }
    }
}

int Reception::findAvailableKitchen() const noexcept
{
    for (int i = numKitchenCooksPerKitchen_; i > 0; i--) {
        int kitchen = AvailableCook(i);
        if (kitchen != -1) {
            return kitchen;
        }
    }
    return -1;
}

void Reception::startNewKitchen() noexcept
{
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork has failed");
        return;
    }
    if (pid == 0) {
        int kitchen = FindAvailableKitchen();
        if (kitchen != -1) {
            KitchenClass k(kitchen, CookingTimeMult_, numKitchenCooksPerKitchen_, TimePizza_);
            k.Start();
        }
        exit(0);
    }
    int stack = 0;
    waitpid(pid, &stack, WNOHANG);
}

void Reception::PizzaToBuf(int kitchen, PlazzaClass *pizzaOrder)
{
    ipcBuffer_.pizza.OrderSize = pizzaOrder->getPizzaSize();
    ipcBuffer_.pizza.OrderType = pizzaOrder->getPizzaType();
    ipcBuffer_.mtype = kitchen + 1;
    if (msgsnd(sharedMemory_->getMessageQueueId(), &ipcBuffer_, sizeof(PlazzaClass), IPC_NOWAIT) < 0)
        throw ErrorHandling("Message to message queue has failed");
}

int Reception::AvailableCook(int nbOfKitchenCooks) const noexcept
{
    std::vector<int> availableKitchens;

    for (int i = 0; i < 100; i++) {
        std::unique_lock<std::mutex> mutex(SharedMemoryThroughtThread_->mutex);
        if (SharedMemoryThroughtThread_->kitchenStatus[i][0] == nbOfKitchenCooks)
            availableKitchens.push_back(i);
        mutex.unlock();
    }
    if (!availableKitchens.empty())
        return availableKitchens[0];

    return -1;
}

int Reception::FindAvailableKitchen() const noexcept
{
    std::vector<int> availableKitchens;
    
    for (int i = 0; i < 100; i++) {
        if (isKitchenAvailable(i)) {
            availableKitchens.push_back(i);
        }
    }
    
    if (!availableKitchens.empty()) {
        return availableKitchens.front();
    }
    
    return -1;
}

bool Reception::isKitchenAvailable(int kitchenIndex) const noexcept
{
    std::unique_lock<std::mutex> mutex(SharedMemoryThroughtThread_->mutex);
    return SharedMemoryThroughtThread_->kitchenStatus[kitchenIndex][0] == -1;
}

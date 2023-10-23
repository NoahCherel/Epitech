/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** kitchen
*/

#include "../inc/plazza.hpp"

bool isRunning;

KitchenClass::KitchenClass(int nb, int cookingTimeMult, int nbOfKitchenCooks, int time) 
    : _nb(nb), CookingTimeMult_(cookingTimeMult), numKitchenCooksPerKitchen_(nbOfKitchenCooks), TimePizza_(time)
{
    std::cout << "Kitchen " << _nb << " has been created" << std::endl;
    initializeSharedMemory();
    createMessageQueue();
    isRunning = true;
}

KitchenClass::~KitchenClass()
{
    for (auto cook : cooks_) {
        delete cook;
    }

    for (int i = 0; i < numKitchenCooksPerKitchen_; i++) {
        pthread_cancel(KitchenThread[i]);
    }
    delete[] KitchenThread;
}

void KitchenClass::initializeSharedMemory()
{
    SharedMemoryThroughtThread_ = MemSharedGet();
    std::lock_guard<std::mutex> mutex(SharedMemoryThroughtThread_->mutex);
    SharedMemoryThroughtThread_->kitchenStatus[_nb][0] = numKitchenCooksPerKitchen_;
}

void KitchenClass::createMessageQueue()
{
    key_t key = ftok("/etc/bashrc", 'B');
    if ((msgQueueID_ = msgget(key, 0666)) < 0)
        throw ErrorHandling("Message queue has failed");
}

void KitchenClass::InitCooks() noexcept
{
    KitchenThread = new pthread_t[numKitchenCooksPerKitchen_];
    int i = 0;
    while (i < numKitchenCooksPerKitchen_) {
        KitchenCook *cook = new KitchenCook;
        cook->setActiveOrder(false);
        cooks_.push_back(cook);
        PizzaThreadArgs *args = new PizzaThreadArgs(cook, SharedMemoryThroughtThread_, i, _nb, CookingTimeMult_, TimePizza_);
        pthread_create(&KitchenThread[i], nullptr, Thread_Handler, (void*)args);
        i++;
    }
}

void KitchenClass::Start() noexcept
{
    InitCooks();
    auto chrono = std::chrono::steady_clock::now(), Timer_Stop = std::chrono::steady_clock::now();
    while (true) {
        // Update kitchen status every TimePizza_ milliseconds
        if (std::chrono::steady_clock::now() - chrono >= std::chrono::milliseconds(TimePizza_)) {
            std::unique_lock<std::mutex> mutex(SharedMemoryThroughtThread_->mutex);
            for (int i = 1; i <= 9; i++) {
                if (SharedMemoryThroughtThread_->kitchenStatus[_nb][i] < 5) {
                    SharedMemoryThroughtThread_->kitchenStatus[_nb][i]++;
                }
            }
            mutex.unlock();
            chrono = std::chrono::steady_clock::now();
        }
        // Check if the kitchen has been idle for more than 5 seconds
        if (std::chrono::steady_clock::now() - Timer_Stop >= std::chrono::seconds(5)) {
            std::unique_lock<std::mutex> mutex(SharedMemoryThroughtThread_->mutex);
            if (SharedMemoryThroughtThread_->kitchenStatus[_nb][0] == numKitchenCooksPerKitchen_) {
                // Set kitchen status to "killed"
                SharedMemoryThroughtThread_->kitchenStatus[_nb][0] = -1;
                for (int i = 1; i <= 9; i++) {
                    SharedMemoryThroughtThread_->kitchenStatus[_nb][i] = 5;
                }
                mutex.unlock();

                // Stop kitchen and exit thread
                std::cout << "kitchen  " << _nb << "has been killed" << std::endl;
                isRunning = false;
                for (int i = 0; i < numKitchenCooksPerKitchen_; i++) {
                    pthread_join(KitchenThread[i], NULL);
                }
                raise(SIGTERM);
            }
            mutex.unlock();
            Timer_Stop = std::chrono::steady_clock::now();
        }

        // Process incoming messages
        if (msgrcv(msgQueueID_, &Msg_, sizeof(PlazzaClass), _nb + 1, MSG_NOERROR | IPC_NOWAIT) > 0) {
            Process();
        }
    }
}

void KitchenClass::Process() noexcept
{
    for (int i = 0; i < numKitchenCooksPerKitchen_; i++) {
        if (cooks_[i]->hasActiveOrder())
            continue;
        std::unique_lock<std::mutex> mutex(SharedMemoryThroughtThread_->mutex);
        if (SharedMemoryThroughtThread_->kitchenStatus[_nb][0] > 0) {
            std::cout << "KitchenClass n°" << _nb << " : " << "1 cook is now busy" << " (" << SharedMemoryThroughtThread_->kitchenStatus[_nb][0] - 1 << " remaining)" << std::endl;
            SharedMemoryThroughtThread_->kitchenStatus[_nb][0] -= 1;
            PlazzaClass *pizza = new PlazzaClass(Msg_.pizza.OrderType, Msg_.pizza.OrderSize);
            cooks_[i]->setPizza(pizza);
            cooks_[i]->setActiveOrder(true);
        }
        mutex.unlock();
        break;
    }
}

void* Thread_Handler(void* args) {
    PizzaThreadArgs* threadArgs = static_cast<PizzaThreadArgs*>(args);

    while (isRunning) {
        if (threadArgs->cook->hasActiveOrder()) {
            CookPizza(threadArgs);
        } else {
            std::this_thread::yield();
        }
    }

    std::cout << "A Cook has been killed.\n" << std::endl;
    return nullptr;
}

void LogFile(PizzaThreadArgs* Args, const std::string& OrderType) noexcept {
    std::ofstream Log("log.txt", std::ios::app);
    Args->cook->setActiveOrder(false);
    const char* sizeString = nullptr;
    switch (Args->cook->getPizza()->getPizzaSize()) {
        case Size::S:
            sizeString = "S";
            break;
        case Size::M:
            sizeString = "M";
            break;
        case Size::L:
            sizeString = "L";
            break;
        case Size::XL:
            sizeString = "XL";
            break;
        case Size::XXL:
            sizeString = "XXL";
            break;
    }
    if (sizeString != nullptr) {
        std::string logMessage = "A Kitchen Cooked 1 pizza " + OrderType + " with Size " + sizeString + "\n";
        std::cout << "=> " << logMessage << std::endl;
        Log << logMessage << std::endl;
    }
    Log.close();
    std::cout << "KitchenClass n°" << Args->id << " : " << "1 cook is now available" << std::endl;
}

void decrementIngredients(PizzaThreadArgs *Args, const std::vector<int>& indices)
{
    for (int index : indices) {
        Args->sharedMemory->kitchenStatus[Args->id][index] -= 1;
    }
}

void incrementPizzaCount(PizzaThreadArgs *Args)
{
    Args->sharedMemory->kitchenStatus[Args->id][0] += 1;
}

void CookPizza(PizzaThreadArgs *Args) noexcept
{
    bool canCook = false;

    switch (Args->cook->getPizza()->getPizzaType()) {
        case Type::Margarita:
            canCook = (Args->sharedMemory->kitchenStatus[Args->id][1] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][2] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][3] > 0);

            if (canCook) {
                std::this_thread::sleep_for(std::chrono::seconds(1 * Args->CookingTimeMult));
                decrementIngredients(Args, {1, 2, 3});
                incrementPizzaCount(Args);
                LogFile(Args, "Margarita");
            }
            break;

        case Type::Regina:
            canCook = (Args->sharedMemory->kitchenStatus[Args->id][1] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][2] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][3] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][4] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][5] > 0);

            if (canCook) {
                std::this_thread::sleep_for(std::chrono::seconds(2 * Args->CookingTimeMult));
                decrementIngredients(Args, {1, 2, 3, 4, 5});
                incrementPizzaCount(Args);
                LogFile(Args, "Regina");
            }
            break;

        case Type::Americana:
            canCook = (Args->sharedMemory->kitchenStatus[Args->id][1] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][2] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][3] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][6] > 0);

            if (canCook) {
                std::this_thread::sleep_for(std::chrono::seconds(2 * Args->CookingTimeMult));
                decrementIngredients(Args, {1, 2, 3, 6});
                incrementPizzaCount(Args);
                LogFile(Args, "Americana");
            }
            break;

        case Type::Fantasia:
            canCook = (Args->sharedMemory->kitchenStatus[Args->id][1] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][2] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][7] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][8] > 0
                       && Args->sharedMemory->kitchenStatus[Args->id][9] > 0);

            if (canCook) {
                std::this_thread::sleep_for(std::chrono::seconds(4 * Args->CookingTimeMult));
                decrementIngredients(Args, {1, 2, 7, 8, 9});
                incrementPizzaCount(Args);
                LogFile(Args, "Fantasia");
            }
            break;

        default:
            break;
    }
}

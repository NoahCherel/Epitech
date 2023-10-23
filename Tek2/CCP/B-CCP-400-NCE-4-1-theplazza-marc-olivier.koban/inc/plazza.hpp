/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** plazza
*/

#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <mutex>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <sstream>
#include <thread>
#include <fstream>
#include <pthread.h>
#include <signal.h>
#include <array>
#include <map>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <tuple>
#include <iostream>
#include <regex>
#include <chrono>
#include <unistd.h>
#include <sys/wait.h>
#include "utils.hpp"

class PlazzaClass
{
public:
    PlazzaClass(Type OrderType, Size OrderSize) noexcept : data(std::make_pair(OrderType, OrderSize)) {}
    Type getPizzaType() const noexcept { return data.first; }
    void setPizzaType(Type OrderType) noexcept { data.first = OrderType; }
    Size getPizzaSize() const noexcept { return data.second; }
    void setPizzaSize(Size OrderSize) noexcept { data.second = OrderSize; }

private:
    std::pair<Type, Size> data;
};

struct Restaurant
{
    std::array<std::array<int, 5>, 100> kitchenStatus;
    std::mutex mutex;
};

class SharedMemoryThread
{
public:
    SharedMemoryThread()
    {
        InitMemShare();
        initializeKitchenStatus();
        createMessageQueue();
    }
    ~SharedMemoryThread()
    {
        removeMessageQueue();
        removeSharedMemory();
    }
    int getMessageQueueId() const noexcept
    {
        return msgQueueID_;
    }

private:
    void initializeKitchenStatus()
    {
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                SharedMemoryThroughtThread_->kitchenStatus[i][j] = 5;
            }
            SharedMemoryThroughtThread_->kitchenStatus[i][0] = -1;
        }
    }
    void createMessageQueue()
    {
        key_t key = ftok("/etc/bashrc", 'B');
        if ((msgQueueID_ = msgget(key, IPC_CREAT | 0666)) < 0)
            throw ErrorHandling("msgget failed");
    }
    void removeMessageQueue() { msgctl(msgQueueID_, IPC_RMID, NULL); }
    void InitMemShare()
    {
        key_t key = ftok("/etc/bashrc", 'A');
        if ((sharedMemoryId = shmget(key, sizeof(Restaurant), IPC_CREAT | 0666)) < 0)
        {
            throw ErrorHandling("Shared Memory has failed");
        }
        if ((SharedMemoryThroughtThread_ = (Restaurant *)shmat(sharedMemoryId, NULL, 0)) == (Restaurant *)-1) {
            throw ErrorHandling("Attach Shared Memory has failed");
        }
    }
    void removeSharedMemory() { shmctl(sharedMemoryId, IPC_RMID, NULL); }
    Restaurant *SharedMemoryThroughtThread_;
    int sharedMemoryId, msgQueueID_;
};

class KitchenCook
{
public:
    KitchenCook() : PizzaOrder_(false), Pizza_(nullptr) {}
    ~KitchenCook() = default;
    bool hasActiveOrder() const noexcept { return PizzaOrder_; }
    void setActiveOrder(bool activeOrder) noexcept { PizzaOrder_ = activeOrder; }
    void setPizza(PlazzaClass* pizza) noexcept { Pizza_ = pizza; }
    PlazzaClass* getPizza() const noexcept { return Pizza_; 
}
private:
    bool PizzaOrder_;
    PlazzaClass* Pizza_;
};

struct PizzaThreadArgs
{
    KitchenCook *cook;
    Restaurant *sharedMemory;
    int nb, id, CookingTimeMult, time;
    PizzaThreadArgs(KitchenCook *cook, Restaurant *sharedMemory, int nb, int id, int CookingTimeMult, int time) : cook(cook), sharedMemory(sharedMemory), nb(nb), id(id), CookingTimeMult(CookingTimeMult), time(time) {}
};

class KitchenClass
{
public:
    KitchenClass(int nb, int CookingTimeMult, int nbOfKitchenCooks, int time);
    ~KitchenClass() noexcept;
    void InitCooks() noexcept;
    void Start() noexcept;
    void Process() noexcept;
    void initializeSharedMemory();
    void createMessageQueue();

private:
    std::vector<KitchenCook *> cooks_;
    pthread_t *KitchenThread;
    Restaurant *SharedMemoryThroughtThread_;
    MessageWithOrder Msg_;
    int msgQueueID_, _nb, CookingTimeMult_, numKitchenCooksPerKitchen_, TimePizza_;
};

class Reception
{
public:
    Reception(int CookingTimeMult, int nbOfKitchenCooks, int time);
    ~Reception();
    void PIzzaOrderToKitchen() noexcept;
    void PizzaToBuf(int kitchen, PlazzaClass *pizza);
    int AvailableCook(int nbOfKitchenCooks) const noexcept;
    int FindAvailableKitchen() const noexcept;
    void Input_handling();
    void ShowKitchenStatus() const noexcept;
    void handlePizzas(std::string &input);
    void SetupOrder(std::string OrderType, std::string OrderSize, int nb);
    std::string readInput();
    void initializeSharedMemory();
    int findAvailableKitchen() const noexcept;
    void startNewKitchen() noexcept;
    bool isKitchenAvailable(int kitchenIndex) const noexcept;

private:
    std::vector<PlazzaClass *> _orders;
    SharedMemoryThread *sharedMemory_;
    Restaurant *SharedMemoryThroughtThread_;
    MessageWithOrder ipcBuffer_;
    int CookingTimeMult_, numKitchenCooksPerKitchen_, TimePizza_;
};

void *Thread_Handler(void *nb);
void CookPizza(PizzaThreadArgs *Args) noexcept;
void LogFile(PizzaThreadArgs *Args, const std::string &OrderType) noexcept;
Restaurant *MemSharedGet();
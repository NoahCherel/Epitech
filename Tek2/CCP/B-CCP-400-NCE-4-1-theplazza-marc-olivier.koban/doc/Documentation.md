**Documentation du projet Plazza**

## Compilation
- make re
- make clean
- make fclean

## Auteurs
- Noah Cherel
- Nathan Tranchant
- Marc-Olivier Koban

## Interfaces utilisées
```cpp
class PlazzaClass {
    public:
        PlazzaClass(Type OrderType, Size OrderSize) noexcept : data(std::make_pair(OrderType, OrderSize)) {}
        Type getPizzaType() const noexcept { return data.first; }
        void setPizzaType(Type OrderType) noexcept { data.first = OrderType; }
        Size getPizzaSize() const noexcept { return data.second; }
        void setPizzaSize(Size OrderSize) noexcept { data.second = OrderSize; }

    private:
        std::pair<Type, Size> data;
};

class SharedMemoryThread {
	public:
		SharedMemoryThread()
		~SharedMemoryThread()
		int getMessageQueueId() const noexcept

	private:
		void initializeKitchenStatus()
		void createMessageQueue()
		void removeMessageQueue()
		void InitMemShare()
		void removeSharedMemory()
		Restaurant *SharedMemoryThroughtThread_;
		int sharedMemoryId, msgQueueID_;
};

class KitchenCook {
	public:
		KitchenCook() : PizzaOrder_(false), Pizza_(nullptr) {}
		~KitchenCook() = default;
		bool hasActiveOrder()
		void setActiveOrder(bool activeOrder)
		void setPizza(PlazzaClass* pizza)
		PlazzaClass* getPizza()
	}
	private:
		bool PizzaOrder_;
		PlazzaClass* Pizza_;
};

struct PizzaThreadArgs {
    itchenCook *cook;
    Restaurant *sharedMemory;
    int nb, id, CookingTimeMult, time;
    PizzaThreadArgs(KitchenCook *cook, Restaurant *sharedMemory, int nb, int id, int CookingTimeMult, int time)
};

class KitchenClass {
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

class Reception {
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
```

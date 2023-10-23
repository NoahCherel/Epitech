/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main
*/

#include "../inc/plazza.hpp"

Restaurant* MemSharedGet()
{
    key_t key = ftok("/etc/bashrc", 'A');
    int shmid = shmget(key, sizeof(Restaurant), 0666);
    
    if (shmid < 0) {
        throw ErrorHandling("Shared Memory has failed");
    }
    
    void* sharedMemory = shmat(shmid, nullptr, 0);
    if (sharedMemory == (void*)-1) {
        throw ErrorHandling("Attach Shared Memory has failed");
    }
    
    return static_cast<Restaurant*>(sharedMemory);
}

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " cooks_per_kitchen num_kitchens restockTimePizza_" << std::endl;
        return 84;
    }

    int cooksPerKitchen = std::stoi(argv[1]);
    int numKitchens = std::stoi(argv[2]);
    int restockTime = std::stoi(argv[3]);

    std::unique_ptr<Reception>
    reception = std::make_unique<Reception>(cooksPerKitchen, numKitchens, restockTime);
    reception->Input_handling();
    return 0;
}

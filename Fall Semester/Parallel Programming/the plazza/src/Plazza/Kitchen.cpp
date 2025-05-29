/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/


#include <cstring>
#include <unistd.h>
#include <iostream>
#include "Kitchen.hpp"

Plazza::DeltaTime::DeltaTime()
{
    this->afk = std::time(0);
    this->afk_c = std::time(0);
    this->ingredientsRegen = std::time(0);
    this->ingredientsRegen_c = std::time(0);
}

static void *KitchenRead(void *k)
{
    Plazza::Kitchen *kitchen = static_cast<Plazza::Kitchen *>(k);

    while (1) {
        Plazza::header_t type;
        ssize_t bytesRead = read(kitchen->childFd, &type, sizeof(type));

        if (type.kitchenId != kitchen->kitchenId) {
            std::cout << "Kitchen id send: " << type.kitchenId << " Expected :" << kitchen->kitchenId << std::endl;
            read(kitchen->childFd, NULL, type.bodySize);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            continue;
        }
        if (type.type == Plazza::MessageType::statusRequest) {
            Plazza::statusAnswer_t tmp;
            tmp.cookOccupied = kitchen->cookOccupied;
            
            std::memset(tmp.ingredients, 0, sizeof(tmp.ingredients));
            char* endptr;
            int result;

            for (auto &i: kitchen->ingredients) {
                std::strcat(tmp.ingredients, std::to_string(i.first).c_str());
                std::strcat(tmp.ingredients, "=");
                std::strcat(tmp.ingredients, std::to_string(i.second).c_str());
                std::strcat(tmp.ingredients, " | ");
            }

            tmp.header.type = Plazza::MessageType::statusAnswer;
            tmp.header.bodySize = sizeof(tmp) - sizeof(tmp.header);
            tmp.header.kitchenId = kitchen->kitchenId;

            
            write(kitchen->parentFd, &tmp, sizeof(tmp));
            kitchen->time.resetAFKTime();
        }
    }
}

Plazza::Kitchen::Kitchen(Option &option, int cfd, int pfd, int id, std::string name, int cookingTime, int orderId) : option(option), childFd(cfd), parentFd(pfd), kitchenId(id), cookingTime(cookingTime), orderId(orderId), pizzaName(name)
{
    this->pid = fork();

    if (this->pid == -1) {
        std::cout << "Error while forking" << std::endl;
        return;
    }

    if (this->pid == 0) {
        this->ingredients[Dough] = 5;
        this->ingredients[Tomato] = 5;
        this->ingredients[Gruyere] = 5;
        this->ingredients[Ham] = 5;
        this->ingredients[Mushrooms] = 5;
        this->ingredients[Steak] = 5;
        this->ingredients[Eggplant] = 5;
        this->ingredients[GoatCheese] = 5;
        this->ingredients[ChiefLove] = 5;

        this->time = DeltaTime();
        pthread_create(&this->thread, NULL, KitchenRead, this);
        std::cout << "[LOG KITCHEN] Kitchen: " << this->kitchenId << " is running" << std::endl;
        while (this->time.afk_c - this->time.afk < this->cookingTime * this->option.cookingTime) {
            this->time.updateAFKTime();
        }
        std::cout << "[LOG KITCHEN] Pizza: " << this->pizzaName << " has been cooked" << std::endl;
        std::cout << "[LOG KITCHEN] Kitchen: " << this->kitchenId << " is closing" << std::endl;
        
        Plazza::header_t tmp;
    
        tmp.bodySize = 0;
        tmp.kitchenId = this->kitchenId;
        tmp.type = MessageType::kitchenClosing;
        write(this->parentFd, &tmp, sizeof(tmp));
    }
}

Plazza::Kitchen::~Kitchen()
{}

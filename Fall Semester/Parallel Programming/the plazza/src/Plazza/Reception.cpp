/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include <thread>
#include <string>
#include <fcntl.h> 
#include <cstring>
#include <iostream>
#include <unistd.h> 
#include <sys/stat.h> 
#include <sys/types.h>
#include "Reception.hpp"


Plazza::Reception::Reception(Option &option, PIZZALIST &pizzaList)
    : option(option), pizzaList(pizzaList) {}

Plazza::Reception::~Reception(void)
{
    pthread_cancel(this->thread);
}

///////////////////////////////////////////////////////////

std::vector<Plazza::Order> &Plazza::Reception::getOrders(void) noexcept
{
    return (this->orders);
}

[[nodiscard]] const KITCHEN &Plazza::Reception::getKitchen(void) const noexcept
{
    return (this->kitchens);
}

///////////////////////////////////////////////////////////

static Plazza::Kitchen *getMostAvailableKitchen(Plazza::Reception *reception)
{
    for (auto &i: reception->getKitchen()) {}
    return (nullptr);
}

static void *KitchenManagment(void *r)
{
    Plazza::Reception *reception = static_cast<Plazza::Reception *>(r);
 
    while (1) {
        Plazza::header_t header;
        ssize_t bytesRead = read(reception->parentFd, &header, sizeof(header));

        if (header.type == Plazza::MessageType::statusAnswer) {

            Plazza::statusAnswer_t tmp;

            read(reception->parentFd, (&tmp.cookOccupied), sizeof(tmp.cookOccupied));
            read(reception->parentFd, (&tmp.ingredients), sizeof(tmp.ingredients));

            std::cout << "[LOG RECEPTION] Status Kitchen: [ | " << tmp.cookOccupied;
            std::cout << " | " << tmp.ingredients << "]" << std::endl;
        } else if (header.type == Plazza::MessageType::pizzaDone) {
            std::cout << "[LOG RECEPTION] Pizza done cooking" << std::endl;
        } else if (header.type == Plazza::MessageType::kitchenClosing) {
            std::cout << "[LOG RECEPTION] Closing Kitchen" << std::endl;
        }
    }
}

int Plazza::Reception::findAKitchen(void)
{
    int id = -1;

    //for (auto &i: this->activeKitchenId) {
    //    Plazza::header_t tmp;
//
    //    tmp.type = Plazza::MessageType::statusRequest;
    //    tmp.bodySize = 0;
    //    tmp.kitchenId = i;
    //    write(this->childFd, &tmp, sizeof(tmp));
//
    //    Plazza::header_t header;
    //    ssize_t bytesRead = read(this->parentFd, &header, sizeof(header));
//
    //    if (header.type == Plazza::MessageType::statusAnswer) {
//
    //        Plazza::statusAnswer_t tmp;
//
    //        read(this->parentFd, (&tmp.cookOccupied), sizeof(tmp.cookOccupied));
    //        read(this->parentFd, (&tmp.ingredients), sizeof(tmp.ingredients));
//
    //        if (tmp.cookOccupied == 0) {
    //            return (i);
    //        }
    //    }
    //}
    return (id);
}

void Plazza::Reception::assignOrderToKitchen(PIZZAORDER &order)
{
    int idk = findAKitchen();

    if (idk == -1) {
        Kitchen k(this->option, this->childFd, this->parentFd, this->kitchenNumber, order.first.getFirst().getName(), order.first.getFirst().getCookingTime(), order.second);

        this->activeKitchenId.emplace_back(this->kitchenNumber++);
        order.first.setFourth(true);
    }

    //Plazza::order_t tmp;
    //tmp.order.first.setFirst(order.first.getFirst());
    //tmp.order.first.setSecond(order.first.getSecond());
    //tmp.order.first.setThird(order.first.getThird());
    //tmp.order.first.setFourth(order.first.getFourth());
    //tmp.orderId = order.second;
    //tmp.header.type = MessageType::order;
    //tmp.header.bodySize = sizeof(1);
    // k.addOrder(order);
}


static bool checkOrder(Plazza::Order &order)
{
    for (auto &i: order.getOrder()) {
        if (i.first.getFourth() == false) {
            return (false);
        }
    }
    return (true);
}

static void KitchenRun(Plazza::Reception *reception)
{
    pthread_t threadLocal;

    pthread_create(&threadLocal, NULL, KitchenManagment, reception);
    while (reception->stop != true) {
        reception->mutex.lock();
        for (auto &i: reception->getOrders()) {
            for (auto &j: i.getOrder()) {
                if (j.first.getThird() != true) {
                    j.first.setThird(true);
                    reception->assignOrderToKitchen(j);
                }
            }
        }
        reception->mutex.unlock();
        //for (auto &i: reception->getOrders()) {
        //    if (checkOrder(i) == true) {
        //        std::cout << "Order " << i.getId() << std::endl;
        //    }
        //}
    }
}

static void *ReceptionRun(void *r)
{
    Plazza::Reception *reception = static_cast<Plazza::Reception *>(r);
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line == "exit") {
            reception->stop = true;
            return (NULL);
        } else if (line == "status") {
            Plazza::header_t tmp;

            tmp.type = Plazza::MessageType::statusRequest;
            tmp.bodySize = 0;
            tmp.kitchenId = -1;


            for (auto &i: reception->activeKitchenId) {
                tmp.kitchenId = i;
                write(reception->childFd, &tmp, sizeof(tmp));
                std::this_thread::sleep_for(std::chrono::seconds(1));
            }
        } else {
            reception->mutex.lock();
            if (reception->parseInput(line) == false) {
                reception->mutex.unlock();
                continue;
            }
            reception->mutex.unlock();
        }
    }
    return (NULL);
}

void Plazza::Reception::Run(void)
{
    mkfifo(FIFO_PARENT, 0666);
    mkfifo(FIFO_CHILD, 0666);

    this->parentFd = open(FIFO_PARENT, 0666);
    this->childFd = open(FIFO_CHILD, 0666);

    pthread_create(&this->thread, NULL, ReceptionRun, this);
    KitchenRun(this);

    unlink(FIFO_PARENT);
    unlink(FIFO_CHILD);
}

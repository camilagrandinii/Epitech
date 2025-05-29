/*
** EPITECH PROJECT, 2024
** THE PLAZZA
** File description:
** Logging Events
*/

#include "EventsLogging.hpp"
#include "Plazza.hpp"

void printIngredients() {
    std::cout << "\nIngredients and quantities:\n";
    for (int i = Dough; i <= ChiefLove; ++i) {
        std::cout << IngredientsToString(static_cast<Ingredients>(i)) << ": " << (i + 1) << std::endl;
    }
}

void printOrder(const Plazza::PizzaOrder &order)
{
    if (!order.getPizzaPtr().get()->getPizzaName().empty()) {
        std::cout << "PIZZA: " << order.getPizzaPtr().get()->getPizzaName() << " " << std::endl;
        std::cout << "SIZE: " << order.getPizzaSize() << std::endl;
    } else {
        std::cout << "No pizza assigned\n";
    }
    std::cout << "READY: " << (order.getPizzaStatus() ? "YES" : "NO") << std::endl;
}

void Plazza::PlazzaLogger::logPizzaReady(time_t currentTime, const Plazza::PizzaOrder &order)
{
    std::cout << "[Order READY] - " << currentTime << std::endl;
    printOrder(order);
}

void Plazza::PlazzaLogger::logCreatedNewKitchen(Plazza::Kitchen kitchen)
{
    std::cout << "[Kitchen CREATED]\n" <<
    "ID: " << kitchen.getStatus().get()->getKitchenId() << "\nNumber of Orders: " << kitchen.getOrders().size();
}

void Plazza::PlazzaLogger::logDeletedKitchen(Plazza::Kitchen kitchen)
{
    std::cout << "[Kitchen DELETED]\n" <<
    "ID: " << kitchen.getStatus().get()->getKitchenId();
}

void Plazza::PlazzaLogger::logCookDoingPizza(Cook cooker, const Plazza::PizzaOrder &order)
{
    std::cout << "[Cook " << "{" << cooker.getId() << "}" << " STARTED new ORDER]";
    printOrder(order);
}

void Plazza::PlazzaLogger::logClientOrder(time_t currentTime, const Plazza::PizzaOrder &order)
{
    std::cout << "[Order OVERVIEW] - " << currentTime << "\n";
    printOrder(order);
}

void Plazza::PlazzaLogger::logProgramStarted()
{
    std::cout << "\nThe Plazza is UP and RUNNING!!!\n";
}

/*
** EPITECH PROJECT, 2024
** The Plazza
** File description:
** Testing the Message Queue
*/

#include "ICP.hpp"
#include <criterion/criterion.h>

// Test sending and receiving a PizzaOrder
Test(MessageQueue, send_receive_pizza_order)
{
    Plazza::MessageQueue messageQueue;
    std::vector<Ingredients> ingredients;
    Plazza::IPizza *tmp;
    auto tmpPizzaList = std::make_shared<std::vector<std::unique_ptr<Plazza::IPizza>>>();

    ingredients = { Dough, Tomato, Gruyere };
    tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("margarita", ingredients, 1));
    ingredients = { Dough, Tomato, Gruyere, Ham, Mushrooms };
    tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("regina", ingredients, 2));
    ingredients = { Dough, Tomato, Gruyere, Steak };
    tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("americana", ingredients, 2));
    ingredients = { Dough, Tomato, Eggplant, GoatCheese, ChiefLove };
    tmpPizzaList->push_back(std::make_unique<Plazza::APizza>("fantasia", ingredients, 4));

    tmp = getPizza(tmpPizzaList, "margarita");
    Plazza::PizzaOrder pizzaOrder(*tmp, M);

    // Send the PizzaOrder
    messageQueue << pizzaOrder;
    // Receive the PizzaOrder
    std::unique_ptr<Plazza::PizzaOrder> receivedPizzaOrder;
    messageQueue >> receivedPizzaOrder;

    cr_assert_eq(pizzaOrder, receivedPizzaOrder);
}

// Test sending and receiving a Status
Test(MessageQueue, send_receive_status)
{
    Plazza::MessageQueue messageQueue;
    struct Options options;
    Plazza::Status receivedStatus;

    options.multiplierCooking = 2;
    options.cooksNumber = 5;
    options.regenerationTime = 10;
    // Create a Status
    Plazza::Status status(options, 1, 1);

    // Send the Status
    messageQueue << status;
    // Receive the Status
    messageQueue >> receivedStatus;

    cr_assert_eq(status, receivedStatus);
}

// Test sending and receiving a status request
Test(MessageQueue, send_receive_status_request)
{
    Plazza::MessageQueue messageQueue;

    // Send a status request
    std::string request = "status";
    messageQueue << request;

    // Receive the status request
    std::string receivedRequest;
    receivedRequest = messageQueue >> receivedRequest;

    cr_assert_eq(request, receivedRequest);
}

// Test if the queue has a message
Test(MessageQueue, has_message)
{
    Plazza::MessageQueue messageQueue;

    // Ensure initially there's no message
    cr_assert_not(messageQueue.hasMessage());

    // Send a message
    std::string messageText = "Test message";
    messageQueue.sendMessage(1, messageText);

    // Check if the queue has a message
    cr_assert(messageQueue.hasMessage());
}

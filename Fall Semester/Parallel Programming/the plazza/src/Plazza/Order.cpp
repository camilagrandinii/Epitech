/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "Order.hpp"

Plazza::Order::Order(std::vector<PIZZAORDER> &order, int id)
    : order(order), id(id) {}

int Plazza::Order::getId(void) const noexcept
{
    return (this->id);
}

bool Plazza::Order::getIsOrderReady(void) const noexcept
{
    return (this->isOrderReady);
}

std::vector<PIZZAORDER> &Plazza::Order::getOrder(void) noexcept
{
    return (this->order);
}

#include "IngredientControl.hpp"

const int Plazza::IngredientControl::getQuantity()
{
    return (this->quantity);
}

const void Plazza::IngredientControl::consumeIngredient()
{
    (this->quantity-=1);
}

const void Plazza::IngredientControl::setQuantity(int quantity)
{
    (this->quantity=quantity);
}

Semaphore Plazza::IngredientControl::getSemaphore()
{
    return (this->semaphore);
}

Plazza::Mutex Plazza::IngredientControl::getMutex()
{
    return (this->mutex);
}
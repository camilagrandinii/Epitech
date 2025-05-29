/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef INGREDIENT_CONTROL_HPP
    #define INGREDIENT_CONTROL_HPP

    #include "Plazza.hpp"
    #include "Semaphore.hpp"
    #include "Mutex.hpp"

namespace Plazza
{
    class IngredientControl {
        private:
            int quantity;
            Semaphore semaphore;
            Mutex mutex;
        public:
            IngredientControl() = default;
            ~IngredientControl() = default;
            [[nodiscard]] const int getQuantity();
            [[nodiscard]] Semaphore getSemaphore();
            Plazza::Mutex getMutex();
            const void setQuantity(int quantity);
            const void consumeIngredient();
    };
}

#endif /* INGREDIENT_CONTROL_HPP */

/*
** EPITECH PROJECT, 2024
** The Plazza
** File description:
** Cooker Header File
*/

#ifndef COOK_HPP
    #define COOK_HPP

    #include <condition_variable>
    #include <functional>
    #include <mutex>
    #include <queue>
    #include <thread>
    #include <vector>
    #include <map>
    #include "Plazza.hpp"
    #include "Semaphore.hpp"
    #include "Kitchen.hpp"
    #include "PizzaOrder.hpp"

namespace Plazza
{
    class Cook {
        private:
            std::thread thread;
            Kitchen *kitchen;
            bool stop;
            void cook();
        public:
            Cook(Kitchen* kitchen);
            ~Cook();
            
            void start();
            void join();
            bool consumeIngredients(std::vector<Ingredients> ingredient);
            void processOrder(Plazza::PizzaOrder *order);
    };
}

#endif /* COOK_HPP */

/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef COOK_HPP
    #define COOK_HPP

    #include "Order.hpp"
    #include "Plazza.hpp"

namespace Plazza {
    class Cook {
        private:
            pthread_t thread;
            Option option;
            PIZZAORDER order;
        public:
            Cook(Option &option, pthread_t &thread);
            ~Cook();
    };
    
}

#endif /* COOK_HPP */

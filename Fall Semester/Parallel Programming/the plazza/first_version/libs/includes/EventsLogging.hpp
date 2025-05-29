#ifndef EVENTS_LOGGING_HPP
    #define EVENTS_LOGGING_HPP

    #include <iostream>
    #include "Pizza.hpp"
    #include "Cooker.hpp"
    #include "Order.hpp"
    #include "Kitchen.hpp"
    #include "Pizza.hpp"

namespace Plazza
{
    class PlazzaLogger {
        public:
            void logProgramStarted();
            void logClientOrder(time_t currentTime, const Plazza::PizzaOrder &order);
            void logPizzaReady(time_t currentTime, const Plazza::PizzaOrder &order);            void logCreatedNewKitchen(Kitchen kitchen);
            void logDeletedKitchen(Kitchen kitchen);
            void logCookDoingPizza(Cook cooker, const Plazza::PizzaOrder &order);
        private:
        protected:
    };
}

#endif /* EVENTS_LOGGING_HPP */

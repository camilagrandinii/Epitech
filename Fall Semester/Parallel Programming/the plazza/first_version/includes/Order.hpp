/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef ORDER_HPP
    #define ORDER_HPP

    #include <vector>
    #include <memory>
    #include "Pizza.hpp"
    #include "PizzaOrder.hpp"

namespace Plazza
{
    class Order {
        private:
            int id = rand();
            bool isOrderReady = false;
            std::vector<std::unique_ptr<PizzaOrder>> orders;
        public:
            inline Order() {};
            ~Order() = default;
            [[nodiscard]] int getId(void) const noexcept;
            [[nodiscard]] const std::vector<std::unique_ptr<PizzaOrder>> &getOrders(void) const noexcept;
            [[nodiscard]] bool getOrderStatus(void) const noexcept;
            void setOrderStatus(void) noexcept;
            void addPizzaToOrder(PizzaOrder &&order);
            bool checkAllPizzaStatus(void) noexcept;
    };
}

#endif /* ORDER_HPP */

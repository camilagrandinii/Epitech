/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef ORDER_HPP
    #define ORDER_HPP

    #include "QuadrUplet.hpp"

    #define PIZZAORDER std::pair<QuadrUplet<Plazza::APizza, PizzaSize, bool, bool>, int>

namespace Plazza
{
    /**
     * @class Order
     * @brief Represents a pizza order.
     */
    class Order {
        private:
            int id;          ///< Unique identifier for the order.
            bool isOrderReady = false;        ///< Indicates whether the order is ready.
            std::vector<PIZZAORDER> order;    ///< List of pizzas in the order.

        public:
            /**
             * @brief Default constructor for the Order class.
             */
            Order(std::vector<PIZZAORDER> &order, int id);

            /**
             * @brief Default destructor for the Order class.
             */
            ~Order() = default;

            /**
             * @brief Gets the ID of the order.
             * @return The ID of the order.
             */
            [[nodiscard]] int getId(void) const noexcept;

            /**
             * @brief Checks if the order is ready.
             * @return True if the order is ready, false otherwise.
             */
            [[nodiscard]] bool getIsOrderReady(void) const noexcept;

            /**
             * @brief Gets the list of pizzas in the order.
             * @return A constant reference to the vector of pizzas in the order.
             */
            [[nodiscard]] std::vector<PIZZAORDER> &getOrder(void) noexcept;
    };    
}

#endif /* ORDER_HPP */

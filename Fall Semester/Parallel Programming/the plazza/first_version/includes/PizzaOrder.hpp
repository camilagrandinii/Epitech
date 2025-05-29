/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef PIZZAORDER_HPP
    #define PIZZAORDER_HPP

    #include <vector>
    #include <memory>
    #include "Pizza.hpp"

namespace Plazza
{
    class PizzaOrder {
        private:
            std::unique_ptr<IPizza> pizza;
            PizzaSize pizzaSize;
            bool isPizzaReady = false;
            std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> pizzaList;
        public:
            PizzaOrder(const IPizza &pizza, PizzaSize pizzaSize);
            PizzaOrder() = default;
            PizzaOrder(const IPizza &pizza, PizzaSize pizzaSize,
                std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> pizzaList);
            PizzaOrder(const PizzaOrder &other) = delete;
            PizzaOrder(PizzaOrder &&other);
            ~PizzaOrder() = default;
            [[nodiscard]] const std::unique_ptr<IPizza> &getPizzaPtr(void) const noexcept;
            [[nodiscard]] PizzaSize getPizzaSize(void) const noexcept;
            [[nodiscard]] bool getPizzaStatus(void) const noexcept;
            void setPizzaStatus(void) noexcept;
            std::string serialize();
            Plazza::PizzaOrder deserialize(const std::string &data);
            bool operator==(const std::unique_ptr<Plazza::PizzaOrder> &otherPtr) const noexcept;
    };
}

#endif /* PIZZAORDER_HPP */

/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef RECEPTION_HPP
    #define RECEPTION_HPP

    #include <vector>
    #include "Order.hpp"
    #include "Plazza.hpp"
    #include "Kitchen.hpp"
    #include "PizzaOrder.hpp"
    #include "ProcessKitchen.hpp"

namespace Plazza
{
    class Reception {
        private:
            Options opt;
            std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> pizzaList;
            std::vector<std::unique_ptr<Order>> orders;
            std::vector<std::unique_ptr<ProcessKitchen>> processKitchens;
        public:
            Reception(Options const &opt, const std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> &pizzaList);
            ~Reception() = default;
            void Run(void);
            [[nodiscard]] bool parseInput(const std::string &input, Order &orders);
            void getStatus(void) const;
            const std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> &getPizzaList(void) const noexcept;
            std::vector<std::unique_ptr<Status>> getStatusOfAllKitchens(void);
            int getMostAvailableKitchen(void);
    };
        
}

#endif //RECEPTION_HPP

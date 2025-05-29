/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef KITCHEN_HPP
    #define KITCHEN_HPP

    #include <map>
    #include "ICP.hpp"
    #include "Status.hpp"
    #include "DeltaTime.hpp"
    #include "IngredientControl.hpp"

namespace Plazza
{
    class Kitchen {
        private:
            std::unique_ptr<Status> status;
            std::vector<std::unique_ptr<PizzaOrder>> orders;
            std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> pizzaList;
            DeltaTime deltaTime;
            Plazza::DeltaTime regenTimer;
            const double inactivityLimit = 5.0;
            Plazza::MessageQueue& messageQueue;

            std::vector<std::unique_ptr<Cook>> cooks;
            Plazza::Mutex ordersMutex;
            std::condition_variable condition;
            bool stop;
        public:
            Kitchen(Options opt, const std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> &pizzaList, long kitchenId, Plazza::MessageQueue& messageQueue);
            Kitchen(Kitchen &other);
            Kitchen(Kitchen &&other);
            ~Kitchen();

            [[nodiscard]] const Options &getOpt(void) const noexcept;
            [[nodiscard]] const int getKitchenId(void) const noexcept;

            std::mutex& getOrdersMutex(void);
            std::condition_variable& getCondition(void);

            const std::vector<std::unique_ptr<Plazza::PizzaOrder>>& getOrders() const noexcept;
            [[nodiscard]] const std::shared_ptr<std::vector<std::unique_ptr<IPizza>>> &getPizzaList(void) const noexcept;
            const std::unique_ptr<Status> &getStatus(void) const noexcept;
            Plazza::MessageQueue& getMessageQueue();

            void Run();
            void addOrder(std::unique_ptr<PizzaOrder> order);
    };
}

#endif /* KITCHEN_HPP */

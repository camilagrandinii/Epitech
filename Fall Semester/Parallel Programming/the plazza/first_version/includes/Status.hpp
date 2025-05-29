#ifndef STATUS_HPP
    #define STATUS_HPP

    #include <map>
    #include <vector>
    #include <utility>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include "Order.hpp"
    #include "Cooker.hpp"
    #include "Plazza.hpp"

namespace Plazza
{
    class Status {
        private:
            long kitchenId;
            Options opt;
            int nbFreePizzaSlots;
            std::map<Ingredients, IngredientControl> ingredientsStock;
        public:
            Status() = default;
            Status(Options opt, long kitchenId, int nbFreePizzaSlots);
            Status(Status &other);
            Status(Status &&other);
            ~Status() = default;

            [[nodiscard]] long getKitchenId() const noexcept;
            [[nodiscard]] int getNbFreePizzaSlots() const noexcept;
            [[nodiscard]] const std::map<Ingredients, IngredientControl> &getIngredientsStock() const noexcept;
            [[nodiscard]] const Options &getOptions() const noexcept;

            void print();
            void consumeIngredient(Ingredients ingName, int quantConsumed);

            [[nodiscard]] std::string serialize() const;
            [[nodiscard]] Status deserialize(const std::string& data);

            [[nodiscard]] Status &operator=(const Status &other) noexcept;
            [[nodiscard]] Status &operator=(Status &&other) noexcept;

            [[nodiscard]] Status &operator=(const std::unique_ptr<Status> other) noexcept;

            bool operator==(const Plazza::Status &other) const noexcept;
    };
}

#endif /* STATUS_HPP */

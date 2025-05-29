/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/


#ifndef PIZZA_HPP
    #define PIZZA_HPP

    #include <vector>
    #include <string>
    #include <memory>
    #include "Plazza.hpp"

namespace Plazza
{
    class IPizza {
        public:
            virtual ~IPizza() = default;
            virtual std::string getPizzaName() const = 0;
            virtual std::vector<Ingredients> getIngredient() const = 0;
            virtual int getCookingTime() const = 0;
            virtual std::string pizzaToString() const = 0;
    };

    class APizza : public IPizza {
        private:
            std::string name;
            std::vector<Ingredients> ingredients;
            int cookingTime;
        public:
            APizza(PizzaName name, std::vector<Ingredients> ingredients, int cookingTime);
            APizza(std::string name, std::vector<Ingredients> ingredients, int cookingTime);
            APizza(const IPizza &other);
            [[nodiscard]] int getCookingTime(void) const noexcept;
            [[nodiscard]] std::string getPizzaName(void) const noexcept;
            [[nodiscard]] std::string pizzaToString(void) const noexcept;
            [[nodiscard]] std::vector<Ingredients> getIngredient(void) const noexcept;
    };

    [[nodiscard]] static inline constexpr bool operator==(IPizza const &a, IPizza const &b) noexcept
    {
        return (std::addressof(a) == std::addressof(b));
    }
}

Plazza::IPizza *getPizza(const std::shared_ptr<std::vector<std::unique_ptr<Plazza::IPizza>>> &pizzaList, const std::string &pizzaName);

#endif /* PIZZA_HPP */

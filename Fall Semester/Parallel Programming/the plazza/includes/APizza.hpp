/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef APIZZA_HPP
    #define APIZZA_HPP

    #include "IPizza.hpp"

namespace Plazza
{
    /**
    * @class APizza
    * @brief Abstract base class representing a Pizza.
    */
    class APizza : public IPizza {
        private:
            std::string name;                      ///< Name of the pizza.
            std::vector<Ingredients> ingredients;  ///< Ingredients used in the pizza.
            int cookingTime;                       ///< Cooking time of the pizza.
        public:
            /**
             * @brief Constructs an APizza object.
             * @param name The name of the pizza.
             * @param ingredients The ingredients used in the pizza.
             * @param cookingTime The cooking time for the pizza.
             */
            APizza(std::string name, std::vector<Ingredients> ingredients, int cookingTime);

            /**
             * @brief Copy constructor for APizza.
             * @param other The APizza object to copy from.
             */
            APizza(const APizza &other);

            /**
             * @brief Destruct an APizza object.
            */
            ~APizza() = default;

            ////////////////////////////////////////////////////////////////////////////////

            /**
             * @brief Gets the cooking time of the pizza.
             * @return The cooking time of the pizza.
             */
            [[nodiscard]] int getCookingTime(void) const noexcept;

            /**
             * @brief Gets the name of the pizza.
             * @return The name of the pizza.
             */
            [[nodiscard]] std::string getName(void) const noexcept;

            /**
             * @brief Gets the ingredients of the pizza.
             * @return A vector of ingredients used in the pizza.
             */
            [[nodiscard]] std::vector<Ingredients> getIngredients(void) const noexcept;

            APizza &operator=(const APizza &other);
    };
}

#endif /* APIZZA_HPP */

/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef IPIZZA_HPP
    #define IPIZZA_HPP

    #include <vector>
    #include <string>
    #include <cstdlib>

enum PizzaType {
    Regina = 1,
    Margarita = 2,
    Americana = 4,
    Fantasia = 8
};

inline const char *BasicPizzaNameStr[] = {
    "regina",
    "margarita",
    "americana",
    "fantasia"
};


enum PizzaSize {
    S = 1,
    M = 2,
    L = 4,
    XL = 8,
    XXL = 16
};

inline const char *PizzaSizeStr[] = {
    "S",
    "M",
    "L",
    "XL",
    "XXL"
};


enum Ingredients {
    Dough = 1,
    Tomato = 2,
    Gruyere = 4,
    Ham = 8,
    Mushrooms = 16,
    Steak = 32,
    Eggplant = 64,
    GoatCheese = 128,
    ChiefLove = 256
};

inline const char *PizzaIngredientsStr[] = {
    "Dough",
    "Tomato",
    "Gruyere",
    "Ham",
    "Mushrooms",
    "Steak",
    "Eggplant",
    "GoatCheese",
    "ChiefLove"
};


namespace Plazza
{
    class IPizza {
        public:
            virtual ~IPizza() = default;
            virtual int getCookingTime() const = 0;
            virtual std::string getName() const = 0;
            virtual std::vector<Ingredients> getIngredients() const = 0;
    };
}

#endif /* IPIZZA_HPP */

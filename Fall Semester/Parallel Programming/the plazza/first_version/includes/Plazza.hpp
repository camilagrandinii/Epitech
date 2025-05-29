/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef PLAZZA_HPP
    #define PLAZZA_HPP

    #include <cmath>

    #define FAILURE 84

    #define ENUM_MACRO_PIZZA_NAME(name, v1, a1, v2, a2, v3, a3, v4, a4)\
    enum name { v1 = a1, v2 = a2, v3 = a3, v4 = a4 };\
    inline const char *name##Strings[] = { #v1, #v2, #v3, #v4 };\
    template<typename T>\
    [[nodiscard]] inline constexpr const char *name##ToString(T value) noexcept { return (name##Strings[static_cast<int>(std::log2(static_cast<int>(value)))]); }

ENUM_MACRO_PIZZA_NAME(PizzaName, Regina, 1, Margarita, 2, Americana, 4, Fantasia, 8);

    #define ENUM_MACRO_INGREDIENT(name, v1, a1, v2, a2, v3, a3, v4, a4, v5, a5, v6, a6, v7, a7, v8, a8, v9, a9)\
    enum name { v1 = a1, v2 = a2, v3 = a3, v4 = a4, v5 = a5, v6 = a6, v7 = a7, v8 = a8, v9 = a9 };\
    inline const char *name##Strings[] = { #v1, #v2, #v3, #v4, #v5, #v6, #v7, #v8, #v9 };\
    template<typename T>\
    [[nodiscard]] inline constexpr const char *name##ToString(T value) noexcept { return (name##Strings[static_cast<int>((value - 1))]); } 

ENUM_MACRO_INGREDIENT(Ingredients, Dough, 1, Tomato, 2, Gruyere, 3, Ham, 4, Mushrooms, 5, Steak, 6, Eggplant, 7, GoatCheese, 8, ChiefLove, 9)

    #define ENUM_MACRO_PIZZA_SIZE(name, v1, a1, v2, a2, v3, a3, v4, a4, v5, a5)\
    enum name { v1 = a1, v2 = a2, v3 = a3, v4 = a4, v5 = a5 };\
    inline const char *name##Strings[] = { #v1, #v2, #v3, #v4, #v5 };\
    template<typename T>\
    [[nodiscard]] inline constexpr const char *name##ToString(T value) noexcept { return (name##Strings[static_cast<int>(std::log2(static_cast<int>(value)))]); }

ENUM_MACRO_PIZZA_SIZE(PizzaSize, S, 1, M, 2, L, 4, XL, 8, XXL, 16)

struct Options {
    int multiplierCooking;
    int cooksNumber;
    int regenerationTime;
};

#endif /* PLAZZA_HPP */

/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef QUADRUPLET_HPP
    #define QUADRUPLET_HPP

    #include "APizza.hpp"

/**
 * @brief A template class to hold four values of different types.
 * @tparam T1 The type of the first value.
 * @tparam T2 The type of the second value.
 * @tparam T3 The type of the third value.
 * @tparam T4 The type of the fourth value.
 */
template<typename T1, typename T2, typename T3, typename T4>
class QuadrUplet {
    private:
        T1 v1; ///< The first value.
        T2 v2; ///< The second value.
        T3 v3; ///< The third value.
        T4 v4; ///< The fourth value.

    public:
        /**
         * @brief Default constructor.
         */
        QuadrUplet() = default;

        /**
         * @brief Constructs a QuadrUplet object with four values.
         * @param v1 The first value.
         * @param v2 The second value.
         * @param v3 The third value.
         * @param v4 The fourth value.
         */
        QuadrUplet(T1 v1, T2 v2, T3 v3, T4 v4);

        /**
         * @brief Copy constructor
         * @param other
         */
        QuadrUplet(const QuadrUplet& other)
            : v1(other.v1), v2(other.v2), v3(other.v3), v4(other.v4) {}

        ~QuadrUplet() = default;

        /**
         * @brief Gets the first value.
         * @return The first value.
         */
        [[nodiscard]] const T1 &getFirst(void) const noexcept;

        /**
         * @brief Gets the second value.
         * @return The second value.
         */
        [[nodiscard]] const T2 &getSecond(void) const noexcept;

        /**
         * @brief Gets the third value.
         * @return The third value.
         */
        [[nodiscard]] const T3 &getThird(void) const noexcept;

        /**
         * @brief Gets the fourth value.
         * @return The fourth value.
         */
        [[nodiscard]] const T4 &getFourth(void) const noexcept;

        /**
         * @brief Sets the first value.
         * @param value The new first value.
         */
        void setFirst(T1 value) noexcept;

        /**
         * @brief Sets the second value.
         * @param value The new second value.
         */
        void setSecond(T2 value) noexcept;

        /**
         * @brief Sets the third value.
         * @param value The new third value.
         */
        void setThird(T3 value) noexcept;

        /**
         * @brief Sets the fourth value.
         * @param value The new fourth value.
         */
        void setFourth(T4 value) noexcept;

        /**
         * @brief Overloads the assignment operator.
         * @param other The other QuadrUplet to assign from.
         * @return A reference to this QuadrUplet.
         */
        QuadrUplet &operator=(const QuadrUplet &other) noexcept {
            if (this != &other) {
                v1 = other.v1;
                v2 = other.v2;
                v3 = other.v3;
                v4 = other.v4;
            }
            return *this;
        }

        /**
         * @brief Overloads the assignment operator for move semantics.
         * @param other The other QuadrUplet to move from.
         * @return A reference to this QuadrUplet.
         */
        QuadrUplet &operator=(QuadrUplet &&other) noexcept {
            if (this != &other) {
                v1 = std::move(other.v1);
                v2 = std::move(other.v2);
                v3 = std::move(other.v3);
                v4 = std::move(other.v4);
            }
            return *this;
        }
};

template class QuadrUplet<Plazza::APizza, PizzaSize, bool, bool>;

#endif /* QUADRUPLET_HPP */

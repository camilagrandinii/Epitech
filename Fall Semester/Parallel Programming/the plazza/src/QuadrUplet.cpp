/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "QuadrUplet.hpp"

template<typename T1, typename T2, typename T3, typename T4>
QuadrUplet<T1, T2, T3, T4>::QuadrUplet(T1 v1, T2 v2, T3 v3, T4 v4)
    : v1(v1), v2(v2), v3(v3), v4(v4) {}

///////////////////////////////////////////////////////////

template<typename T1, typename T2, typename T3, typename T4>
const T1 &QuadrUplet<T1, T2, T3, T4>::getFirst() const noexcept
{
    return (this->v1);
}

template<typename T1, typename T2, typename T3, typename T4>
const T2 &QuadrUplet<T1, T2, T3, T4>::getSecond() const noexcept
{
    return (this->v2);
}

template<typename T1, typename T2, typename T3, typename T4>
const T3 &QuadrUplet<T1, T2, T3, T4>::getThird() const noexcept
{
    return (this->v3);
}

template<typename T1, typename T2, typename T3, typename T4>
const T4 &QuadrUplet<T1, T2, T3, T4>::getFourth() const noexcept
{
    return (this->v4);
}

template<typename T1, typename T2, typename T3, typename T4>
void QuadrUplet<T1, T2, T3, T4>::setFirst(T1 value) noexcept
{
    this->v1 = value;
}

template<typename T1, typename T2, typename T3, typename T4>
void QuadrUplet<T1, T2, T3, T4>::setSecond(T2 value) noexcept
{
    this->v2 = value;
}

template<typename T1, typename T2, typename T3, typename T4>
void QuadrUplet<T1, T2, T3, T4>::setThird(T3 value) noexcept
{
    this->v3 = value;
}

template<typename T1, typename T2, typename T3, typename T4>
void QuadrUplet<T1, T2, T3, T4>::setFourth(T4 value) noexcept
{
    this->v4 = value;
}

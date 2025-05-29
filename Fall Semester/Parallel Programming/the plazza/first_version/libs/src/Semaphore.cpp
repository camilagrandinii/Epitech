/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#include "Semaphore.hpp"

void Semaphore::Post(Semaphore &sem)
{
    sem.size = 1;
}

void Semaphore::Wait(Semaphore &sem)
{
    while (sem.size != 1);
    sem.size = 0;
}

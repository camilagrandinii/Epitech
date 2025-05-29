/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef SEMAPHORE_HPP
    #define SEMAPHORE_HPP

    #include <semaphore.h>
    #include <cstdint>

class Semaphore {
    public:
        Semaphore() = default;
        ~Semaphore() = default;
        void Post(Semaphore &);
        void Wait(Semaphore &);

    private:
        uint8_t size = 0;
};

#endif /* SEMAPHORE_HPP */

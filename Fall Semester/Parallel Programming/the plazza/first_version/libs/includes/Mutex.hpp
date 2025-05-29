/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef MUTEX_HPP
    #define MUTEX_HPP
   
    #include <mutex>

namespace Plazza
{
    class Mutex {
        private:
            std::mutex mutex;
        public:
            Mutex() = default;
            ~Mutex() = default;
            const void lock();
            const void unlock();
            std::mutex& getMutex();
    };
}

#endif /* MUTEX_HPP */

#include "Mutex.hpp"

const void Plazza::Mutex::lock()
{
    mutex.lock();
}

const void Plazza::Mutex::unlock()
{
    mutex.unlock();
}

std::mutex& Plazza::Mutex::getMutex()
{
    return mutex;
}
#include "DeltaTime.hpp"

Plazza::DeltaTime::DeltaTime()
{
    this->timeSecond = std::chrono::high_resolution_clock::now();
}

double Plazza::DeltaTime::getDeltaTime()
{
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> delta = end - timeSecond;
    this->timeSecond = end;
    return (delta.count());
}

void Plazza::DeltaTime::reset()
{
    this->timeSecond = std::chrono::high_resolution_clock::now();
}
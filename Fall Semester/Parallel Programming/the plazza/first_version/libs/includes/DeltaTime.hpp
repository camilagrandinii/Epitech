#ifndef DELTA_TIME_HPP
    #define DELTA_TIME_HPP
    #include <chrono>

namespace Plazza {
    class DeltaTime {
        private:
            std::chrono::high_resolution_clock::time_point timeSecond;

        public:
            DeltaTime();
            double getDeltaTime();
            void reset();
    };
}

#endif
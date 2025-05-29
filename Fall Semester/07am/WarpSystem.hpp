#ifndef WARPSYSTEM_FILE
#define WARPSYSTEM_FILE

namespace WarpSystem{
    class QuantumReactor{
        private:
            bool _stability;

        public:
            QuantumReactor();
            bool isStable();
            void setStability(bool stability){ _stability = stability; };
    };

    class Core{
        public:
            Core(WarpSystem::QuantumReactor *coreReactor);
            QuantumReactor *_coreReactor;
            QuantumReactor* checkReactor();
    };
}

#endif
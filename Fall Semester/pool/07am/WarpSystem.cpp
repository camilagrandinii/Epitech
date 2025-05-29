#include "WarpSystem.hpp"

WarpSystem::QuantumReactor::QuantumReactor(): _stability(true){};
bool WarpSystem::QuantumReactor::isStable(){ return QuantumReactor::_stability; };
WarpSystem::Core::Core(QuantumReactor *quantumReactor): _coreReactor(quantumReactor){};
WarpSystem::QuantumReactor* WarpSystem::Core::checkReactor(){
    return Core::_coreReactor;
}
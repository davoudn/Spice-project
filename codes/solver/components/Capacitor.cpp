#include "Capacitor.hpp"
#include "Resistor.hpp"
#include "CurrentSource.hpp"


template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::integrate ()  
{
           double tmp{0.0};
           for (int i{1}; i < Integrator.size(); i++){
                tmp += this->I[this->itLast + 1 - i] * Integrator.CorrectorWeighs[i];
           }
           I_cs->Current = -tmp / (this->DelT * Integrator.CorrectorWeighs[0]) - R_eq->G* this->V[ItLast];
}

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::setupComponent ()
{
        this->V.clear();
        this->I.clear();
        R_eq->G = C/(this->DelT * Integrator.CorrectorWeighs[0]);
        return;
}

template <typename INTEGRATOR>
bool Capacitor<INTEGRATOR>:: checkComponent ()
{
        return true;
}


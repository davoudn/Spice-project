#pragma once 
#include "ComplexComponent.hpp"
#include "Utility.hpp"
#include "Capacitor.hpp"
#include "Resistor.hpp"
#include "CurrentSource.hpp"


template <typename INTEGRATOR>
struct Capacitor : public ComplexComponent {
    public:
    Capacitor(DParams argparams, map_ptr_t argnodemap);
    
    void Integrate() override;
    void SetupComponent () override;
    bool CheckComponent() override;
    private:
        double c    = 0.f;
        double v0   = 0.f;

        INTEGRATOR integrator;
        double initial_v;
};


template <typename INTEGRATOR>
Capacitor<INTEGRATOR>::Capacitor(DParams argparams, map_ptr_t argnodemap):ComplexComponent(argparams, argnodemap)
{
              c        = this->params.get<float>("C");
              v0       = this->params.get<float>("V0");
              del_tau     = this->params.get<float>("DelT");
}
template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::Integrate ()  
{
           double tmp{0.0};
           for (int i{1}; i < integrator.Nw; i++){
                tmp += currents[ItLast + 1 - i] * integrator.CorrectorWeighs[i];
           }
           current_cs->current = -tmp / (this->del_tau * integrator.CorrectorWeighs[0]) - resistor_eq->g* this->voltages[ItLast];
}

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::SetupComponent ()
{
        this->voltages.clear();
        this->currents.clear();
        resistor_eq->g = c/(this->del_tau * integrator.CorrectorWeighs[0]);
        return;
}

template <typename INTEGRATOR>
bool Capacitor<INTEGRATOR>:: CheckComponent ()
{
        return true;
}



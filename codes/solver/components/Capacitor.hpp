#pragma once 
#include "ComplexComponent.hpp"
#include "../Utility.hpp"
#include "Capacitor.hpp"
#include "Resistor.hpp"
#include "CurrentSource.hpp"


template <typename INTEGRATOR>
struct Capacitor : public ComplexComponent {
    public:
    Capacitor(DParams argparams, map_ptr_t argnodemap);
    
    void integrate() override;
    void setupComponent () override;
    bool checkComponent() override;
    private:
        double C    = 0.f;
        double V0   = 0.f;
        double DelT = 0.f;

        INTEGRATOR Integrator;
        double InitialV;
};


template <typename INTEGRATOR>
Capacitor<INTEGRATOR>::Capacitor(DParams argparams, map_ptr_t argnodemap):ComplexComponent(argparams, argnodemap)
{
        if (this->Params.get<float>("C"))
              C        = this->Params.get<float>("C").value();
        if (this->Params.get<float>("V0"))
              V0       = this->Params.get<float>("V0").value();
        if (this->Params.get<float>("DelT"))
              DelT     = this->Params.get<float>("DelT").value();
}
template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::integrate ()  
{
           double tmp{0.0};
           for (int i{1}; i < Integrator.Nw; i++){
                tmp += I[ItLast + 1 - i] * Integrator.CorrectorWeighs[i];
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



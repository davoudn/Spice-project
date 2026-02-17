#pragma once 

#include "ComplexComponent.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"
#include "../Utility.hpp"

#include<cmath>

struct Resistor;
struct CurrentSource;

template <typename INTEGRATOR>
struct CPE: public ComplexComponent {
    public:
    CPE(DParams argparams, map_ptr_t argnodemap);
    
    void integrate() override;
    void setupComponent () override;
    bool checkComponent() override;
            double C = 0.0, Alpha = 0.0 , Gamma = 0.0, InvGamma = 0.0, V0 = 0.0, DelT = 0.0;

    private:
        INTEGRATOR Integrator;
};

template <typename INTEGRATOR>
CPE<INTEGRATOR>::CPE(DParams argparams, map_ptr_t argnodemap):ComplexComponent(argparams, argnodemap)
{
              Alpha    = this->Params.get<float>("Alpha").value();
              C        = this->Params.get<float>("C").value();
              V0       = this->Params.get<float>("V0").value();
              DelT     = this->Params.get<float>("DelT").value();
              Gamma    = std::tgamma(Alpha);
              InvGamma = std::tgamma(Alpha);
              Integrator.Init(Alpha, DelT);
}

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::integrate()  
{
           double sum{0.0};
           int k = this->I.size();
           for (int i{0}; i < k; i++){
                sum += this->I[i] * Integrator.corrector(i,k);
           }
           I_cs->Current = - V0 * Gamma * C / Integrator.corrector(k,k) - sum / Integrator.corrector(k,k) ;
           R_eq->G = Gamma * C / Integrator.corrector(k,k);
}

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::setupComponent ()
{
        this->V.clear();
        this->I.clear();
        this->Geq = Gamma * C / Integrator.corrector(1,1); // be carefull //
        return;
}

template <typename INTEGRATOR>
bool CPE<INTEGRATOR>::checkComponent (){
        return true;
}
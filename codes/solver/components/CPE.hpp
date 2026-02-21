#pragma once 

#include "ComplexComponent.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"
#include "Utility.hpp"

#include<cmath>

struct Resistor;
struct CurrentSource;

template <typename INTEGRATOR>
struct CPE: public ComplexComponent {
    public:
    CPE(DParams argparams, map_ptr_t argnodemap);
    
    void Integrate() override;
    void SetupComponent () override;
    bool CheckComponent() override;
    double c = 0.0, alpha = 0.0 , gamma = 0.0, inv_gamma = 0.0, v0 = 0.0, del_tau = 0.0;

    private:
        INTEGRATOR integrator;
};

template <typename INTEGRATOR>
CPE<INTEGRATOR>::CPE(DParams argparams, map_ptr_t argnodemap):ComplexComponent(argparams, argnodemap)
{
              alpha     = this->params.get<float>("Alpha");
              c         = this->params.get<float>("C");
              v0        = this->params.get<float>("V0");
              del_tau   = this->params.get<float>("DelT");
              gamma     = std::tgamma(alpha);
              inv_gamma = 1.0/std::tgamma(alpha);
              integrator.Init(alpha, del_tau);
}

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::Integrate()  
{
           double sum{0.0};
           int k = this->currents.size();
           for (int i{0}; i < k; i++){
                sum += this->currents[i] * integrator.corrector(i,k);
           }
           current_cs->current = - v0 * gamma * c / integrator.corrector(k,k) - sum / integrator.corrector(k,k) ;
           resistor_eq->g = gamma * c / integrator.corrector(1,1);
}

/// @brief 
/// @tparam INTEGRATOR 
template <typename INTEGRATOR>
void CPE<INTEGRATOR>::SetupComponent ()
{
        this->voltages.clear();
        this->currents.clear();
        return;
}

template <typename INTEGRATOR>
bool CPE<INTEGRATOR>::CheckComponent (){
        return true;
}
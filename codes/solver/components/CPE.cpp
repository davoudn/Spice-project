#include "CPE.hpp"
#include "CurrentSource.hpp"
#include "Resistor.hpp"

template <typename INTEGRATOR>
CPE<INTEGRATOR>::CPE(DParams argparams, DMap<std::string> argnodemap):ComplexComponent(argparams, argnodemap)
{
              Alpha    = this->Params.get<float>("Alpha");
              C        = this->Params.get<float>("C");
              V0       = this->Params.get<float>("V0");
              DelT     = this->Params.get<float>("DelT");
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
                sum += this->I[i] * Integrator(i,k);
           }
           I_cs->Current = - V0 * Gamma * C / Integrator(k,k) - sum / Integrator(k,k) ;
           R_eq->G = Gamma * C / Integrator(k,k);
}

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::setupComponent ()
{
        this->V.clear();
        this->I.clear();
        this->Geq = Gamma * C / Integrator(1,1); // be carefull //
        return;
}

template <typename INTEGRATOR>
bool CPE<INTEGRATOR>::checkComponent (){
        return true;
}




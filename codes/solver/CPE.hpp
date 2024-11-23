#include "BaseComponent.hpp"
#include "Integrators.hpp"

template <typename INTEGRATOR>
struct CPE : public BaseComponent {
    public:
    CPE(DParams _Params){
              Init(_Params);
	      SetupComponent();
              Alpha    = this->Params.Get<float>("Alpha");
              C        = this->Params.Get<float>("C");
              V0       = this->Params.Get<float>("V0");
              DelT     = this->Params.Get<float>("DelT");
              Gamma    = std::tgamma(Alpha);
              InvGamma = std::tgamma(Alpha);
              Integrator.Init(Alpha, DelT);
    }
    
    void Integrate() override;
    void SetupComponent () override;
    bool CheckComponent() override;
    private:
        Weights<INTEGRATOR> Integrator;
        double C = 0.0, Alpha = 0.0 , Gamma = 0.0, InvGamma = 0.0, V0 = 0.0, DelT = 0.0;
};

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::Integrate()  {
           double sum{0.0};
           int k = this->I.size();
           for (int i{0}; i < k; i++){
                sum += this->I[i] * Integrator(i,k);
           }
           this->Ieq = - V0 * Gamma * C / Integrator(k,k) - sum / Integrator(k,k) ;
           this->Geq = Gamma * C / Integrator(k,k);
}

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::SetupComponent (){
        this->V.clear();
        this->I.clear();
        this->Geq = Gamma * C / Integrator(1,1); // be carefull //
        return;
}

template <typename INTEGRATOR>
bool CPE<INTEGRATOR>::CheckComponent (){
        return;
}

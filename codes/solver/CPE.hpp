#include "BaseComponent.hpp"
#include "Integrators.hpp"

template <typename INTEGRATOR>
struct CPE : public BaseComponent {
    public:
    CPE(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
	      setupComponent();
              Alpha    = this->Params.get<float>("Alpha");
              C        = this->Params.get<float>("C");
              V0       = this->Params.get<float>("V0");
              DelT     = this->Params.get<float>("DelT");
              Gamma    = std::tgamma(Alpha);
              InvGamma = std::tgamma(Alpha);
              Integrator.Init(Alpha, DelT);
    }
    
    void integrate() override;
    void setupComponent () override;
    bool checkComponent() override;
            double C = 0.0, Alpha = 0.0 , Gamma = 0.0, InvGamma = 0.0, V0 = 0.0, DelT = 0.0;

    private:
        Weights<INTEGRATOR> Integrator;
};

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::integrate()  
{
           double sum{0.0};
           int k = this->I.size();
           for (int i{0}; i < k; i++){
                sum += this->I[i] * Integrator(i,k);
           }
           this->Ieq = - V0 * Gamma * C / Integrator(k,k) - sum / Integrator(k,k) ;
           this->Geq = Gamma * C / Integrator(k,k);
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

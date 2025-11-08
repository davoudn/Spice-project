#include "BaseComponent.hpp"


template <typename INTEGRATOR>
struct Capacitor : public BaseComponent {
    public:
    Capacitor(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
              C        = this->Params.Get<float>("C");
              V0       = this->Params.Get<float>("V0");
              DelT     = this->Params.Get<float>("DelT");
	      SetupComponent();
    }
    
    void Integrate() override;
    void SetupComponent () override;
    bool CheckComponent() override;
    private:
        double_t C = 0.f;
        double_t V0= 0.f;
        double_t DelT= 0.f;

        INTEGRATOR Integrator;
        double InitialV;
};

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::Integrate ()  
{
           double tmp{0.0};
           for (int i{1}; i < Integrator.Size(); i++){
                tmp += this->I[this->itLast + 1 - i] * Integrator.CorrectorWeighs[i];
           }
           this->Ieq = -tmp / (this->DelT * Integrator.CorrectorWeighs[0]) - Geq * this->V[ItLast];
}

template <typename INTEGRATOR>
void Capacitor<INTEGRATOR>::SetupComponent ()
{
        this->V.clear();
        this->I.clear();
        this->Geq = C/(this->DelT * Integrator.CorrectorWeighs[0]);
        return;
}

template <typename INTEGRATOR>
bool Capacitor<INTEGRATOR>:: CheckComponent ()
{
        return true;
}

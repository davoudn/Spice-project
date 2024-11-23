#include "BaseComponent.hpp"

template <typename INTEGRATOR>
struct CPE : public BaseComponent {
    public:
    CPE(std::map<std::string, std::string>& _P){
              Init(_P);
	      SetupComponent();
    }
    
    void Integrate() override;
    void SetupComponent () override;
    bool CheckComponent() override;
    private:
        INTEGRATOR integrator;
        double InitialV;
};

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::Integrate()  {
           double tmp{0.0};
           for (int i{1}; i < integrator::Nw; i++){
                tmp += this->I[this->itLast + 1 - i] * integrator::CorrectorWeighs[i];
           }
       //    this->Ieq = -tmp / (this->DelT * integrator::CorrectorWeighs[0]) - Geq * this->V[itLast];
}

template <typename INTEGRATOR>
void CPE<INTEGRATOR>::SetupComponent (){
        this->V.clear();
        this->I.clear();
    //    this->Geq = std::stof(this->params["C"])/(this->DelT * integrator::CorrectorWeighs[0]);
        return;
}

template <typename INTEGRATOR>
bool CPE<INTEGRATOR>::CheckComponent (){
        return;
}

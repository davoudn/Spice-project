#include "BaseComponent.hpp"


template <typename INTEGRATOR>
struct Resistor : public BaseComponent {
    public:
    Resistor(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
        this->Geq = 1.0/this->Params.get<float>("R");
    }
    inline void integrate() override {
           // do nothing
    }
    private:
     INTEGRATOR integrator;

};
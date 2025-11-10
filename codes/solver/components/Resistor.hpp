#include "BaseComponent.hpp"


struct Resistor : public BaseComponent {
    public:
    Resistor(DParams argparams, DMap<std::string> argnodemap):BaseComponent(argparams, argnodemap){
        G = 1.0/argparams.get<float>("R");
    }
    
    double G = 0.f;
    

};
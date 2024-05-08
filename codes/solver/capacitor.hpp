#include "basecomponent.hpp"


template <typename INTEGRATOR>
struct Capacitor : public BaseComponent {
    Capacitor(){

    }
    private:
     INTEGRATOR integrator;

};
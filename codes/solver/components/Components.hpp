#pragma once 
#include "ComplexComponent.hpp"
#include "BaseComponent.hpp"
#include "Resistor.hpp"
#include "CPE.hpp"
#include "Capacitor.hpp"
#include "VoltageSource.hpp"
#include "Integrators.hpp"

namespace Components 
{

BaseComponent* Make(DParams& argp, map_ptr_t nodesmap);

template <typename T>
T* Cast(BaseComponent* c){
        T* t = nullptr;
        if (T::componentClass == ComponentClass::Basic) {
           t = dynamic_cast<T*>(c);
        }
        if (T::componentClass == ComponentClass::Complex){
           auto t0 = dynamic_cast<ComplexComponent*>(c);
           if (t0){
                t = dynamic_cast<T*>(t0);
           }
        }
        return t;
}
}
 

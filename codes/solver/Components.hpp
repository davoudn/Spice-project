#pragma once 
#include <string>
#include "ComplexComponent.hpp"
template <typename T>
class DMap;

class DParams;

namespace Components {
template <typename INTEGRATOR>
BaseComponent* Make(DParams params, DMap<std::string> argnodemap);

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
 

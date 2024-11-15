#include "Capacitor.hpp"
#include "Resistor.hpp"


template <typename INTEGRATOR>
BaseComponent* Make(std::map<std::string, std::string>&& _P){

        if( _P["Type"] == "Capacitor" ){
		return new Capacitor<INTEGRATOR>(_P);
	}

	if( _P["Type"] == "Capacitor" ){
                return new Resistor<INTEGRATOR>(_P);
        }

	if( _P["Type"] == "CPE" ){
                return new Capacitor<INTEGRATOR>(_P);
        }

	if( _P["Type"] == "Inductor" ){
                return new Capacitor<INTEGRATOR>(_P);
        }

        return nullptr;
}

 

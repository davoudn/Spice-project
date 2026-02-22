#pragma once

#include "CurrentSource.hpp"
#include "Utility.hpp"
#include <vector>
#include <memory>

class Resistor;
class CurrentSource;

struct ComplexComponent : public BaseComponent {

ComplexComponent(DParams argarams, map_ptr_t nodesmap);
virtual ~ComplexComponent();
virtual void Integrate();
virtual void SetupComponent (){};
virtual bool CheckComponent (){return true;};
virtual void Populate(double dv) override; 

Resistor* GetEquivalentResistor();
CurrentSource* GetEquivalentCurrentSource();

protected:
std::unique_ptr<Resistor> resistor_eq = nullptr;
std::unique_ptr<CurrentSource> current_cs = nullptr;



	
};
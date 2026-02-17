#pragma once
#include "../Utility.hpp"
#include <cstdint>
#include <vector>
#include <map>
#include <string>
// this is just for the constraction of acctual components 
// r1 n1 n2 10k
/* general
lable
npos
nneg
type
*/
// resistor resistance
// capacitor capacitance
// inductor inductance
// cpe     capacitance, alpha




//////////////////////////////////////////////////////////

struct BaseComponent {
public:

    void Init(DParams& argarams, map_ptr_t nodesmap){
	     Params = argarams;
	     PosNET = nodesmap->get(argarams.get<std::string>("PosNET").value()).value(); 
		 NegNET = nodesmap->get(argarams.get<std::string>("NegNET").value()).value(); 
		 Type   = argarams.get<std::string>("Type").value();
		 Label  = argarams.get<std::string>("Label").value(); 
		 Name   = argarams.get<std::string>("name").value();
		 DelT   = argarams.get<double>("DelT").value();
    }

    BaseComponent() = delete;
    BaseComponent(DParams argarams, map_ptr_t nodesmap);
	
	virtual ~BaseComponent();

	uint32_t PosNET = 0, NegNET = 0;
	std::string Label, Type, Name;
	std::vector<double> V;
	std::vector<double> I;
	int ItLast;
   	double Ieq, Geq, DelT;
	// this would be populated in the acctual drived class. 
	DParams Params;
    static ComponentClass componentClass;
	virtual void populate(double dv);
};

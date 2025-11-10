#pragma once
#include "Utility.hpp"
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


struct DummyStruct{
std::map<std::string, std::string> params;
};

//////////////////////////////////////////////////////////

struct BaseComponent {
public:

    void Init(DParams& argarams, DMap<std::string> nodesmap){
	     Params = argarams;
	     PosNET = nodesmap.get(argarams.get<std::string>("PosNET")); 
		 NegNET = nodesmap.get(argarams.get<std::string>("NegNET")); 
		 Type   = argarams.get<std::string>("Type");
		 Label  = argarams.get<std::string>("Label"); 
		 Name   = argarams.get<std::string>("name");
		 DelT   = argarams.get<double>("DelT");
    }

    BaseComponent() = delete;
    BaseComponent(DParams argarams, DMap<std::string> nodesmap);
	
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

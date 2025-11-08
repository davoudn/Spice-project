#pragma once
#include <vector>
#include <map>
#include <string>
#include "Utility.hpp"
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

    void Init(DParams& argarams){
	     Params = argarams;
	     PosNET = argarams.Get<int>("PosNET"); 
		 NegNET = argarams.Get<int>("NegNET"); 
		 Type   = argarams.Get<std::string>("Type");
		 Label  = argarams.Get<std::string>("Label"); 
		 Name   = argarams.Get<std::string>("name");
		 DelT   = argarams.Get<int>("DelT");
    }

    BaseComponent() = delete;
    BaseComponent(DParams argarams, DMap<std::string> nodesmap){
		 Params = argarams;
	     PosNET = nodesmap.Get(argarams.Get<std::string>("PosNET")); 
		 NegNET = nodesmap.Get(argarams.Get<std::string>("NegNET")); 
		 Type   = argarams.Get<std::string>("Type");
		 Label  = argarams.Get<std::string>("Label"); 
		 Name   = argarams.Get<std::string>("name");
		 DelT   = argarams.Get<int>("DelT");
	}
	int PosNET = 0, NegNET = 0;
	std::string Label, Type, Name;
	std::vector<double> V;
	std::vector<double> I;
	int ItLast;
   	double Ieq, Geq, DelT;
	// this would be populated in the acctual drived class. 
	DParams Params;

public:
	virtual void Integrate() {};
	void Populate(double dv) 
	{
		V.push_back(dv);
		auto i = Ieq + dv * Geq;
		I.push_back(i);
	}
	virtual void SetupComponent (double _del_t);
	virtual bool CheckComponent ();
};


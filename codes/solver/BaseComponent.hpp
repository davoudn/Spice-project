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

    void Init(DParams _Params){
	     Params = _Params;
	     PosNET = _Params.Get<int>("PosNET"); 
		 NegNET = _Params.Get<int>("NegNET"); 
		 Type   = _Params.Get<std::string>("Type");
		 Label  = _Params.Get<std::string>("Label"); 
		 Name   = _Params.Get<std::string>("name");
		 DelT   = _Params.Get<int>("DelT");
    }

    BaseComponent(){}

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


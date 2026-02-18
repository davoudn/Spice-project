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
	     params = argarams;
	     pos_net = nodesmap->get(argarams.get<std::string>("PosNET")); 
		 neg_net = nodesmap->get(argarams.get<std::string>("NegNET")); 
		 type   = argarams.get<std::string>("type");
		 name   = argarams.get<std::string>("name");
		 del_tau   = argarams.get<double>("DelT");
    }

    BaseComponent() = delete;
    BaseComponent(DParams argarams, map_ptr_t nodesmap);
	
	virtual ~BaseComponent();

	uint32_t pos_net = 0, neg_net = 0;
	std::string label, type, name;
	std::vector<double> voltages;
	std::vector<double> currents;
	int ItLast;
   	double i_eq, g_eq, del_tau;
	// this would be populated in the acctual drived class. 
	DParams params;
    static ComponentClass componentClass;
	virtual void Populate(double dv) = 0;
};

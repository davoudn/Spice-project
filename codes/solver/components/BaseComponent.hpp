#pragma once
#include "Utility.hpp"
#include <cstdint>
#include <vector>
#include <map>
#include <string>
// this is just for the construction of actual components 
// r1 n1 n2 10k
/* general
label
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
	     params_ = argarams;
	     pos_net_ = nodesmap->Get(argarams.Get<std::string>("PosNET")); 
		 neg_net_ = nodesmap->Get(argarams.Get<std::string>("NegNET")); 
		 type_   = argarams.Get<std::string>("type");
		 name_   = argarams.Get<std::string>("name");
		 del_tau_   = argarams.Get<double>("DelT");
    }

    BaseComponent() = delete;
    BaseComponent(DParams argarams, map_ptr_t nodesmap);
	
	virtual ~BaseComponent();

	uint32_t pos_net_ = 0, neg_net_ = 0;
	std::string label_, type_, name_;
	std::vector<double> voltages_;
	std::vector<double> currents_;
	int it_last_;
   	double i_eq_, g_eq_, del_tau_;
	// this would be populated in the actual derived class. 
	DParams params_;
    static ComponentClass componentClass;
	virtual void Populate(double dv) = 0;
};

#include "Circuit.hpp"
#include "components/Components.hpp"

#include <cstdint>
#include <memory>


//
void BaseCircuit::Allocate() 
{
	
		A.zeros(nDim, nDim); // arma
		X.zeros(nDim); // arma
		Z.zeros(nDim);  // arma
		//
		return;
}

void BaseCircuit::Init(std::vector<DParams>& argcomponents) 
{
	//
	 NodesMap = std::make_shared<map_t>();

     int c = 0;
     for (auto& x: argcomponents) {
        if ( NodesMap->add(x.get<std::string>("PosNET"), c) ){
        	c++;
		}
		if ( NodesMap->add(x.get<std::string>("NegNET"), c) ){
			c++;
		}
     }
	 for (auto & x: NodesMap->M) {
		std::cout << x.first << " " << x.second << "\n";
 	 }
     for (auto& x: argcomponents){
		try {
			auto c = Components::Make(x, NodesMap);
            Components.push_back(c);
		}
		catch(Components::MakeError& e){
      		std::cout << e.what() << "\n";
      		exit(0);
   		}
     }
     
     for (uint32_t it=0; it< Components.size(); it++ ){
         if (Components[it]->type == "VoltageSource"){
			VoltageSourceMap.push_back(it);
		 }
     }
     for (uint32_t it=0; it< Components.size(); it++ ){
         if (Components[it]->type == "CurrentSource" || Components[it]->componentClass == ComponentClass::Complex){
			CurrentSourceMap.push_back(it);
		 }
     }
     nDim = VoltageSourceMap.size() + NodesMap->size();
	 NumNodes = NodesMap->size();
     return;
}

void BaseCircuit::MakeAll() 
{
	Allocate();
    /*                                                 
     *********************  making A matrix  ***************************
    */
	for (uint32_t it=0; it< Components.size(); it++ )
	{
		 Resistor* resistor = nullptr;
		 if (Components[it]->type == "Resistor"){
			resistor = static_cast<Resistor*>(Components[it]);
		 }
		 if (Components[it]->componentClass == ComponentClass::Complex){
			resistor = Components::Cast<ComplexComponent>(Components[it])->resistor_eq;
		 }
         if (resistor){
		     // off diagonal
			 A(resistor->pos_net, resistor->neg_net) = -resistor->g;
			 A(resistor->neg_net, resistor->pos_net) = -resistor->g;
			 // diagonal
			 A(resistor->pos_net, resistor->pos_net)+=  resistor->g;
			 A(resistor->pos_net, resistor->pos_net)+=  resistor->g;
		 }
	}

    for (uint32_t id =0; id < VoltageSourceMap.size(); id++)
	{
					A(id + NumNodes, Components[VoltageSourceMap[id]]->pos_net) =+1;
					A(id + NumNodes, Components[VoltageSourceMap[id]]->neg_net) =-1;
					//
					A(Components[VoltageSourceMap[id]]->pos_net, id + NumNodes) =+1;
					A(Components[VoltageSourceMap[id]]->neg_net, id + NumNodes) =-1;
	}

    /* the end of A matrix construction block */
    /*
	************************** z matrix construction *****************************
    */
	double itmp{ 0.0 };
	for (uint32_t node{ 0 }; node < NumNodes; node++) 
	{
		for (uint32_t i{0}; i < CurrentSourceMap.size(); i++){
            int id = CurrentSourceMap[i]; 
			CurrentSource* I = nullptr;
			if (Components[id]->componentClass == ComponentClass::Basic) {
                I = Components::Cast<CurrentSource>(Components[id]);
			}
			if (Components[id]->componentClass == ComponentClass::Complex) {
                I = Components::Cast<ComplexComponent>(Components[id])->current_cs;
			}
			if (I){
				if ( Components[id]->pos_net == node ){
					itmp+= I->current;
				}
				if ( Components[id]->neg_net == node ){
					itmp-= I->current;
				}
			}
		}

		Z(node) = -itmp;
		itmp = 0.0;
	}
	for (uint32_t id=0; id < VoltageSourceMap.size(); id++){
		 Z(NumNodes + id) = static_cast<VoltageSource*>(Components[VoltageSourceMap[id]])->Voltage;
	}
    /*
     * ********************************************************************************
     * */
	return;
}

void BaseCircuit::populate() 
{
	for (auto comp : Components) {
		auto dv = X[comp->pos_net] - X[comp->neg_net];
		comp->Populate(dv);
	}
}

void BaseCircuit::integrate() 
{
	for (auto base : Components) {
		if (base->componentClass == ComponentClass::Complex){
            auto comp = Components::Cast<ComplexComponent>(base);
			if (comp){
               	comp->Integrate();
			}
		}
	}
}
void BaseCircuit::Solve_it() 
{
	X = arma::solve(A, Z);
	return;
}
void BaseCircuit::Solve() 
{
	for (uint32_t it=0; it < MaxIterations; it++) {
		integrate();
		Solve_it();
		populate();
	}
	return;
}

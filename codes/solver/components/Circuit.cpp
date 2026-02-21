#include "Circuit.hpp"
#include "components/Components.hpp"

#include <cstdint>
#include <memory>


//
void BaseCircuit::Allocate() 
{
	
		a_.zeros(n_dim_, n_dim_); // arma
		x_.zeros(n_dim_); // arma
		z_.zeros(n_dim_);  // arma
		//
		return;
}

void BaseCircuit::Init(std::vector<DParams>& argcomponents) 
{
	//
	 nodes_map_ = std::make_shared<map_t>();

     int c = 0;
     for (auto& x: argcomponents) {
        if ( nodes_map_->Add(x.Get<std::string>("PosNET"), c) ){
        	c++;
		}
		if ( nodes_map_->Add(x.Get<std::string>("NegNET"), c) ){
			c++;
		}
     }
	
     for (auto& x: argcomponents){
		try {
			auto c = Components::Make(x, nodes_map_);
            components_.push_back(c);
		}
		catch(Components::MakeError& e){
      		std::cout << e.what() << "\n";
      		exit(0);
   		}
     }
     
     for (uint32_t it=0; it< components_.size(); it++ ){
         if (components_[it]->type_ == "VoltageSource"){
			voltage_source_map_.push_back(it);
		 }
     }
     for (uint32_t it=0; it< components_.size(); it++ ){
         if (components_[it]->type_ == "CurrentSource" || components_[it]->componentClass == ComponentClass::Complex){
			current_source_map_.push_back(it);
		 }
     }
     n_dim_ = voltage_source_map_.size() + nodes_map_->Size();
	 num_nodes_ = nodes_map_->Size();
	 /* print out a report about the nodes/components etc */
	 for (auto & x: nodes_map_->m_) {
		std::cout << x.first << " " << x.second << "\n";
 	 }
     return;
}

void BaseCircuit::MakeAll() 
{
	Allocate();
    /*                                                 
     *********************  making A matrix  ***************************
    */
	for (uint32_t it=0; it< components_.size(); it++ )
	{
		 Resistor* resistor = nullptr;
		 if (components_[it]->type_ == "Resistor"){
			resistor = static_cast<Resistor*>(components_[it]);
		 }
		 if (components_[it]->componentClass == ComponentClass::Complex){
			resistor = Components::Cast<ComplexComponent>(components_[it])->resistor_eq;
		 }
         if (resistor){
		     // off diagonal
			 a_(resistor->pos_net_, resistor->neg_net_) = -resistor->g_;
			 a_(resistor->neg_net_, resistor->pos_net_) = -resistor->g_;
			 // diagonal
			 a_(resistor->pos_net_, resistor->pos_net_)+=  resistor->g_;
			 a_(resistor->pos_net_, resistor->pos_net_)+=  resistor->g_;
		 }
	}

    for (uint32_t id =0; id < voltage_source_map_.size(); id++)
	{
					a_(id + num_nodes_, components_[voltage_source_map_[id]]->pos_net_) =+1;
					a_(id + num_nodes_, components_[voltage_source_map_[id]]->neg_net_) =-1;
					//
					a_(components_[voltage_source_map_[id]]->pos_net_, id + num_nodes_) =+1;
					a_(components_[voltage_source_map_[id]]->neg_net_, id + num_nodes_) =-1;
	}

    /* the end of A matrix construction block */
    /*
	************************** z matrix construction *****************************
    */
	double itmp{ 0.0 };
	for (uint32_t node{ 0 }; node < num_nodes_; node++) 
	{
		for (uint32_t i{0}; i < current_source_map_.size(); i++){
            int id = current_source_map_[i]; 
			CurrentSource* I = nullptr;
			if (components_[id]->componentClass == ComponentClass::Basic) {
                I = Components::Cast<CurrentSource>(components_[id]);
			}
			if (components_[id]->componentClass == ComponentClass::Complex) {
                I = Components::Cast<ComplexComponent>(components_[id])->current_cs;
			}
			if (I){
				if ( components_[id]->pos_net_ == node ){
					itmp+= I->current_;
				}
				if ( components_[id]->neg_net_ == node ){
					itmp-= I->current_;
				}
			}
		}

		z_(node) = -itmp;
		itmp = 0.0;
	}
	for (uint32_t id=0; id < voltage_source_map_.size(); id++){
		 z_(num_nodes_ + id) = static_cast<VoltageSource*>(components_[voltage_source_map_[id]])->voltage_;
	}
    /*
     * ********************************************************************************
     * */
	return;
}

void BaseCircuit::Populate() 
{
	for (auto comp : components_) {
		auto dv = x_[comp->pos_net_] - x_[comp->neg_net_];
		comp->Populate(dv);
	}
}

void BaseCircuit::Integrate() 
{
	for (auto base : components_) {
		if (base->componentClass == ComponentClass::Complex){
            auto comp = Components::Cast<ComplexComponent>(base);
			if (comp){
               	comp->Integrate();
			}
		}
	}
}
void BaseCircuit::SolveIt() 
{
	x_ = arma::solve(a_, z_);
	return;
}
void BaseCircuit::Solve() 
{
	for (uint32_t it=0; it < max_iterations_; it++) {
		Integrate();
		SolveIt();
		Populate();
	}
	return;
}


#include "BaseComponent.hpp"

ComponentClass BaseComponent::componentClass =  ComponentClass::Basic;

BaseComponent::BaseComponent(DParams argarams, map_ptr_t nodesmap)
{
		 Init(argarams, nodesmap);
		 
}
	
BaseComponent::~BaseComponent()
{

}

void BaseComponent::populate(double dv)
{
		
}
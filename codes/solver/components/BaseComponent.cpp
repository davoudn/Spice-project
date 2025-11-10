
#include "BaseComponent.hpp"

ComponentClass BaseComponent::componentClass =  ComponentClass::Basic;

BaseComponent::BaseComponent(DParams argarams, DMap<std::string> nodesmap)
{
		 Init(argarams, nodesmap);
		 
}
	
BaseComponent::~BaseComponent()
{

}

void BaseComponent::populate(double dv)
{
		
}
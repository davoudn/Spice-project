class BaseComponent;

namespace Components {
template <typename INTEGRATOR>
BaseComponent* Make(std::map<std::string, std::string>&& _P);

}
 

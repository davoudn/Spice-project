#include <string>

class BaseComponent;
template <typename T>
class DMap;

class DParams;

namespace Components {
template <typename INTEGRATOR>
BaseComponent* Make(DParams params, DMap<std::string> argnodemap);

}
 

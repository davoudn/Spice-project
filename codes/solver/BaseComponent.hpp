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


struct DummyStruct{
std::map<std::string, std::string> params;
};

//////////////////////////////////////////////////////////

struct BaseComponent {
	BaseComponent(int _nodePos, int _nodeNeg, std::string _type, std::string _label): nodePos(_nodePos), nodeNeg(_nodeNeg), type(_type), label(_label) {}
	BaseComponent(int _nodePos, int _nodeNeg, std::string _type, std::string _label, int _id):nodePos(_nodePos), nodeNeg(_nodeNeg), type(_type), label(_label), id(_id) {}
    BaseComponent(){}
private:
	int nodePos, nodeNeg;
	std::string label, type;
	std::vector<double> V;
	std::vector<double> I;
	int id, it_last;

    double i_eq, g_eq, del_t;

	// this would be populated in the acctual drived class. 
	std::map<std::string, double> params;

public:
	virtual void integrate() {};
	void Populate(double dv) {
		V.push_back(dv);
		auto i = i_eq + dv * g_eq;
		I.push_back(i);
	};
	virtual void SetupComponent (double _del_t);
	virtual bool CheckComponent ();
};


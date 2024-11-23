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
public:

    void Init(std::map<std::string,std::string> _P){
	     PosNET=std::stoi(_P["PosNET"]); NegNET=std::stoi(_P["NegNET"]); Type=_P["Type"]; Label = _P["Label"]; Name = _P["name"];
	     Params = _P;
	     DelT   = std::stof(_P["DelT"]);
    }

    BaseComponent(){}

private:
	int PosNET = 0, NegNET = 0;
	std::string Label, Type, Name;
	std::vector<double> V;
	std::vector<double> I;
	int ItLast;
    	double Ieq, Geq, DelT;
	// this would be populated in the acctual drived class. 
	std::map<std::string, std:;string> Params;

public:
	virtual void Integrate() {};
	void Populate(double dv) {
		V.push_back(dv);
		auto i = i_eq + dv * g_eq;
		I.push_back(i);
	}
	virtual void SetupComponent (double _del_t);
	virtual bool CheckComponent ();
};


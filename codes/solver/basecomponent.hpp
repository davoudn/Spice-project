#include <vector>
#include <map>
#include <string>

struct Terminal {
	int nodeId;
	int signe;
};

struct SPICE {};
struct BaseComponent {
	BaseComponent(Terminal _t1, Terminal _t2, std::string _type, std::string _label):t1(_t1), t2(_t2), type(_type), label(_label) {}
	BaseComponent(Terminal _t1, Terminal _t2, std::string _type, std::string _label, int _id):t1(_t1), t2(_t2), type(_type), label(_label), id(_id) {}
	Terminal t1, t2;
	std::string label, type;
	std::map<std::string, double> params;
	std::vector<double> V;
	std::vector<double> I;
	int id, it_last;

    double i_eq, g_eq, del_t;

	virtual void integrate();
};


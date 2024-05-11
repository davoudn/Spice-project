
#include <vector>
#include <map>
#include <string>


struct BaseComponent {
	BaseComponent(int _nodePos, int _nodeNeg, std::string _type, std::string _label): nodePos(_nodePos), nodeNeg(_nodeNeg), type(_type), label(_label) {}
	BaseComponent(int _nodePos, int _nodeNeg, std::string _type, std::string _label, int _id):nodePos(_nodePos), nodeNeg(_nodeNeg), type(_type), label(_label)id(_id), id(_id) {}
private:
	int nodePos, nodeNeg;
	std::string label, type;
	std::map<std::string, double> params;
	std::vector<double> V;
	std::vector<double> I;
	int id, it_last;

    double i_eq, g_eq, del_t;
public:
	virtual void integrate() {};
	void Populate(double dv) {
		V.push_back(dv);
		auto i = i_eq + dv * g_eq;
		I.push_back(i);
	};
};


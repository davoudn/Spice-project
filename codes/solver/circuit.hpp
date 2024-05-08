#include "basecircuit.hpp"

class circuit {
private:
    std::vector<BaseComponent*> components;
    std::vector<BaseComponent*> transComponents;
    std::vector< std::vector<int> > translationTable;
    
    BaseCircuit baseCircuit;

    void PopulateTransComponents(){};
    void PopulateComponents(){};

    int nIterations;
public:
    void Translate();
    void Integrate();
    void Solve();
};


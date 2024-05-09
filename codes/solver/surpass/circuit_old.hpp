#include "basecircuit.hpp"

class circuit {
private:
    std::vector<BaseComponent*> components;
    std::vector<BaseComponent*> transComponents;
    std::vector< std::vector<int> > translationTable;
    
    BaseCircuit baseCircuit;

    void PopulateTransComponents();
    void PopulateComponents(){};
    void StaticSolve();
    void Translate();
    void Integrate();
    int nIterations;
public:
    void Solve();
};


#include "basecircuit.hpp"

class circuit {
private:
    std::vector<BaseComponent*> components;
    std::vector<BaseComponent*> transComponents;
    std::vector< std::vector<int> > translationTable;
    
    BaseCircuit baseCircuit;

    void populateTransComponents();
    void populateComponents(){};
    void StaticSolve();
    void Translate();
    void integrate();
    int nIterations;
public:
    void Solve();
};


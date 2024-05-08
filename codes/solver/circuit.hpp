#include "basecircuit.hpp"

class circuit {
private:
    std::vector<BaseComponent*> elements;
    std::vector<BaseComponent*> translatedElements;
    std::vector< std::vector<int> > translationTable;
    
    BaseCircuit baseCircuit;
public:
    void translate();
    void solve();
};


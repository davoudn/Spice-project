#include "circuit.hpp"


void circuit::Translate(){
    int tanslatedId{0};
  
    for (int id{0}; id < components.size(); id++){
        auto el = components[id];
        if ( el->type == "C" || el->type == "L" || el->type == "CPE"){
            transComponents.push_back(new BaseComponent(el->t1,el->t2, "IS", el->label+"I"));
            tanslatedId++;
            translationTable[id].push_back(tanslatedId);

            transComponents.push_back(new BaseComponent(el->t1,el->t2, "R", el->label+"R"));
            tanslatedId++;
            translationTable[id].push_back(tanslatedId);

        } else {
            transComponents.push_back(new BaseComponent(el->t1,el->t2, el->type, el->label));
            translationTable[id].push_back(tanslatedId);
            tanslatedId++;
        }
    }

    for (int id{0}; id < transComponents.size(); id++){
        transComponents[id]->id = id;
    }
    return;
}
void circuit::Integrate(){
  
    for (auto el : components){
        el->integrate();
    }
}

void circuit::StaticSolve(){
    baseCircuit.Init(transComponents);
    baseCircuit.Solve();
}

void circuit::Solve(){
    for (int it{0}; it < nIterations; it++){

        Integrate();
        PopulateTransComponents();
        StaticSolve();
        PopulateComponents();
  }
}
#include "circuit.hpp"


void circuit::Translate(){
    int tanslatedId{0};
  
    for (int id{0}; id < components.size(); id++){
        auto el = components[id];
        if ( el->type == "C" || el->type == "L" || el->type == "CPE"){
            transComponents.push_back(new BaseComponent(el->nodePos,el->nodeNeg, "IS", el->label+"I"));
            tanslatedId++;
            translationTable[id].push_back(tanslatedId);

            transComponents.push_back(new BaseComponent(el->nodePos, el->nodeNeg, "R", el->label+"R"));
            tanslatedId++;
            translationTable[id].push_back(tanslatedId);

        } else {
            transComponents.push_back(new BaseComponent(el->nodePos, el->nodeNeg, el->type, el->label));
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
    return;
}

void circuit::PopulateTransComponents() {
    for (int id{ 0 }; id < components.size(); id++) {
        for (int tid : translationTable[id]) {
            if (transComponents[tid]->type == "IS") {
                transComponents[tid]->i_eq = components[id]->i_eq;
            }
            if (transComponents[tid]->type == "R") {
                transComponents[tid]->g_eq = components[id]->g_eq;
            }
        }
    }
    return;
}

void circuit::PopulateComponents() {
    for (int id{ 0 }; id < components.size(); id++) {
        for (int tid : translationTable[id]) {
            if (transComponents[tid]->type != "R") {
                auto dv = baseCircuit.x[transComponents[tid]->nodePos] - baseCircuit.x[transComponents[tid]->nodeNeg];
                components[id]->Populate(dv);

            }



        }
    }

    return;
}



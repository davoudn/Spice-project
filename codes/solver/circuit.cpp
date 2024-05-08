#include "circuit.hpp"


void circuit::translate(){
    int tanslatedId{0};
  
    for (int id{0}; id < elements.size(); id++){
        auto el = elements[id];
        if ( el->type == "C" || el->type == "L" || el->type == "CPE"){
            translatedElements.push_back(new BaseComponent(el->t1,el->t2, "IS", el->label+"I"));
            tanslatedId++;
            translationTable[id].push_back(tanslatedId);

            translatedElements.push_back(new BaseComponent(el->t1,el->t2, "R", el->label+"R"));
            tanslatedId++;
            translationTable[id].push_back(tanslatedId);

        } else {
            translatedElements.push_back(new BaseComponent(el->t1,el->t2, el->type, el->label));
            translationTable[id].push_back(tanslatedId);
            tanslatedId++;
        }
    }

    for (int id{0}; id < elements.size(); id++){
        translatedElements[id]->id = id;
    }
    return;
}

void circuit::solve(){

}
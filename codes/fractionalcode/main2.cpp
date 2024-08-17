#include <iostream>
#include <string>
#include "FractionalOrderDE.h"

int main(){

//    Ohmic ohmic(1.0,1.0,0.5, 0.01, 1000, 1.0);
//    ohmic.Solve();
    Faradic faradic(1.0,1.0,1.0,1.75, 0.01, 1000, 1.0, std::string("Faradic"));
    faradic.Solve();    
    faradic.Dump(1);
    FaradicOrdinary faradicNormal(1.0,1.0,1.0, 1.0);
    faradicNormal.Dump(1000,0.01);
    return 0;
}

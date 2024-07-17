#include <iostream>
#include "FractionalOrderDE.h"

int main(){

    Ohmic ohmic(1.0,1.0,0.8, 0.01, 1000, 1.0);
    ohmic.Solve();
    

    return 0;
}
#include <iostream>
#include "FractionalOrderDE.h"

int main(){

    Ohmic ohmic(1.0,1.0,0.5, 0.01, 1000, 1.0);
    ohmic.Solve(true);
    

    return 0;
}
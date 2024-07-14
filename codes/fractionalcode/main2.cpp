#include <iostream>
#include "FractionalOrderDE.h"

int main(){

    Ohmic ohmic(1.0,1.0,0.99, 0.01, 20, 1.0);
    ohmic.Solve();
    

    return 0;
}
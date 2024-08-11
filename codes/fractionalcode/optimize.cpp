#include "FractionalOrderDE.h"

int main(){

    //Ohmic ohmic(1.0,1.0,0.5, 0.01, 1000, 1.0);
    //ohmic.Solve(true);
    opt::init("10-1OCP.csv", "Rest", 1, 10,20);
    opt::Optimmize();

    return 0;
}
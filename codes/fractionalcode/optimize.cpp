#include "FractionalOrderDE.h"

int main(){
        arma::vec x = arma::ones(6,1);

    //Ohmic ohmic(1.0,1.0,0.5, 0.01, 1000, 1.0);
    //ohmic.Solve(true);
    opt::init("10-1OCP.csv", "Rest", 1, 10,20);
   // opt::Optimmize();
    opt::ObjectiveFunc(x,nullptr,nullptr);

    return 0;
}
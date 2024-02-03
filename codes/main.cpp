#include <iostream>
#include <math.h>
#include "OrdinaryController.h"

double fun(double x){
    return exp(pow(2*x,2));
}


int main()
{
Operator<FourPointDerivative> derivative(0.001);
Operator<FourPointIntegral> integral(0.0001);
Operator<SimpleIntegral> integralsimple(0.0001);
Controller<SimpleDerivative,SimpleIntegral> c(0.01);

std::cout << derivative(fun,0.5) << std::endl;
std::cout << integral(fun,0.0,1.0) << std::endl;
std::cout << integralsimple(fun,0.0,1.0) << std::endl;
return 0;
}
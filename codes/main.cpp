#include <iostream>
#include <math.h>
#include "OrdinaryController.h"

double fun(double x){
    return exp(pow(x,2));
}


int main()
{
Operator<FourPointDerivative> derivative(0.001);
Controller<SimpleDerivative,SimpleIntegral> c(0.01);

 std::cout << derivative(fun,0.5) << std::endl;
return 0;
}
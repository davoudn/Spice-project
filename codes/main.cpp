#include <iostream>
#include <math.h>
#include "OrdinaryController.h"

double fun(double x){
    return exp(pow(x,2));
}


int main()
{
Operator<FourPointDerivative> op(0.001);
Controller<SimpleDerivative,SimpleIntegral> c(0.01);

 std::cout << op(fun,0.5) << std::endl;
return 0;
}
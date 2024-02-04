#include <iostream>
#include <math.h>
#include "OrdinaryController.h"

double fun(double x){
    return pow(x,2);
}


int main()
{
FourPointDerivative d4p(0.001);
SimpleDerivative dsimple(0.001);

FourPointIntegral i4p(0.001);
SimpleIntegral isimple(0.001);
//Controller<SimpleDerivative,SimpleIntegral> c(0.01);

std::cout << Op(d4p,fun,0.5) << std::endl;
std::cout << Op(dsimple,fun,0.5) << std::endl;

std::cout << Op(i4p,fun,0.5) << std::endl;
std::cout << Op(isimple,fun,0.5) << std::endl;

std::cout << Integral(i4p,fun,0.0,1.0) << std::endl;
std::cout << Integral(isimple,fun,0.0,1.0) << std::endl;


//std::cout << I(fun,0.0,1.0) << std::endl;
return 0;
}
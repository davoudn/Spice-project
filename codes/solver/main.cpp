// This is an example file as part of Modern-CMake

#include "Circuit.hpp"

#include <iostream>
#include "../Parser/Parser.h"


/*    */
std::vector<DParams> ParseFile (std::string FileName)
{
    std::vector<DParams> dparams;
    auto result = Parser::ParseFile(FileName);
    for (const auto& x:result){
        dparams.push_back(x);
    }
    return dparams;
}


int main() {

    std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
    auto result = ParseFile("Example1.net");
    BaseCircuit circuit;
    circuit.Init(result);

    return 0;
}


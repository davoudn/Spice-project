// This is an example file as part of Modern-CMake

#include "Circuit.hpp"

#include <iostream>
#include "../Parser/Parser.h"

int main() {

    std::cout << "Simple example C++ compiled correctly and ran." << std::endl;
    ParseFile("Example1.net");

    return 0;
}


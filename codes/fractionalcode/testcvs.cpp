#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
 
int main()
{
	std::fstream inf("10-1OCP.csv", std::ios_base::in);
    // greet the user
    std::string name, cvsline, l2;
    for (int i{0}; i <10; i++){
    //inf >> l2;
    //std::cout << l2 << "\n";
    }
    while(std::getline(inf, cvsline)){
    std::istringstream cvsstreeam(cvsline);
    for ( l2; std::getline(cvsstreeam, l2, ',');){
	    std::cout << l2 << "\n";
        }
    }
   // std::string line;
   // std::cout << cvsline << "\n";
 
    // read file line by line
    std::istringstream input;
    input.str("1\n2\n3\n4\n5\n6\n7\n");
    int sum = 0;
    for (std::string line; std::getline(input, line);)
        sum += std::stoi(line);
    std::cout << "\nThe sum is " << sum << ".\n\n";
 
    // use separator to read parts of the line
    std::istringstream input2;
    input2.str("a;b;c;d");
    for (std::string line; std::getline(input2, line, ';');)
        std::cout << line << '\n';
}

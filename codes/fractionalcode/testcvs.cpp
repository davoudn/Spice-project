#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include "cvs.h"

std::vector<int>* Linear(){
    std::vector<int>* tmp = new std::vector<int>();
    for (int i{0}; i<100;i++){
	    tmp->push_back(i);
    }
    return tmp;
}	

int main()
{
/*	std::fstream inf("10-1OCP.csv", std::ios_base::in);
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


auto _file = "10-1OCP.csv";
cvsread_neware data(_file);

auto x = data.filter("Rest", 1, 30);

for (int i{0}; i < x[0].size(); i++){
    std::cout << x[0][i] << " "  << x[1][i] << "\n";
}
*/
auto res = Linear();

std::cout << res->size() << "\n";

for (int i{0}; i<res->size(); i++){
    std::cout << res->at(i) << "\n";
}
delete res;
return 0;
}

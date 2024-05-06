#include <iostream>
#include "antlr4-runtime.h"
#include "generated/TLexer.h"
#include "generated/TParser.h"
#include <fstream>
#include <string>

using namespace antlrcpptest;
using namespace antlr4;

int main(int , const char **) {
  // std :: cout << "Reading File ...." << std :: endl;
  // std :: cout << "_________________________________________" << std :: endl;

  std::ifstream t("Example.net");
  t.seekg(0, std::ios::end);
  size_t size = t.tellg();
  std::string buffer(size, ' ');
  t.seekg(0);
  t.read(&buffer[0], size);
  // std :: cout << buffer << std :: endl;
  
  // std :: cout << "_________________________________________" << std :: endl << std :: endl;
  
  
  ANTLRInputStream input(buffer);
  TLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  for (auto token : tokens.getTokens()) {
    std::cout << token->toString() << std::endl;
  }

  TParser parser(&tokens);
  // parser.resistor();
  tree::ParseTree* tree = parser.main();
  
  std::cout << tree->toStringTree(&parser) << std::endl << std::endl;

  return 0;
}
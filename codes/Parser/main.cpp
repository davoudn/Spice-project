#include <iostream>
#include "antlr4-runtime.h"
#include "generated/TLexer.h"
#include "generated/TParser.h"
#include "generated/TParserBaseVisitor.h"
#include <fstream>
#include <string>

using namespace antlrcpptest;
using namespace antlr4;

int main(int argc ,const char* argv[]) {


  if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
        return 1;
  }

  // Open input file
  std::ifstream buffer;
  buffer.open(argv[1]);
  if (!buffer.is_open()) {
      std::cerr << "Error: Cannot open file " << argv[1] << std::endl;
      return 1;
  }
  ANTLRInputStream input(buffer);
  TLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  // for (auto token : tokens.getTokens()) {
  //       std::cout << token->toString() << std::endl;
  //   }
  tokens.fill();
  TParser parser(&tokens);

  TParserBaseVisitor visitor;
  visitor.visitCircuit(parser.circuit());
  
  return 0;
}
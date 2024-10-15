#include <iostream>
#include "antlr4-runtime.h"
#include "generated/TLexer.h"
#include "generated/TParser.h"
#include "generated/TParserBaseVisitor.h"
#include <fstream>
#include <string>

using namespace antlrcpptest;
using namespace antlr4;

int main(int , const char **) {
  std::ifstream t("Example.net");
  t.seekg(0, std::ios::end);
  size_t size = t.tellg();
  std::string buffer(size, ' ');
  t.seekg(0);
  t.read(&buffer[0], size);

  ANTLRInputStream input(buffer);
  TLexer lexer(&input);
  CommonTokenStream tokens(&lexer);

  tokens.fill();
  TParser parser(&tokens);

  TParserBaseVisitor visitor;
  visitor.visitMain(parser.main());
  
  return 0;
}
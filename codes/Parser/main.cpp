#include <iostream>
#include "antlr4-runtime.h"
#include "generated/TLexer.h"
#include "generated/TParser.h"
#include "generated/TParserBaseListener.h"
#include "generated/TParserBaseVisitor.h"
#include "tree/ParseTreeWalker.h"
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
    // std :: cout << token[0] ;
    std::cout << token->toString() << std::endl;
  }

  TParser parser(&tokens);

  TParserBaseVisitor visitor;
  visitor.visitMain(parser.main());
  TParserBaseListener listener;
  listener.enterMain(parser.main());
  // parser.main();
  // parser.resistor();

  // tree::ParseTree* tree = parser.main();
  // std::cout << tree->toStringTree(&parser) << std::endl << std::endl;
  // TParserBaseVisitor visitor;
  // // std::string str = visitor.visitMain(parser.main()).as<std::string>();
  // visitor.visitMain(parser.main());
  // // std::cout << "Visitor output: " << visitor.visitMain(parser.main()).type().name() << std::endl;

  // tree :: ParseTreeWalker walker;
  // ParserRuleContext* fileInput = parser.main();
  // TParserBaseListener *listener = new TParserBaseListener();
  // walker.walk(listener,fileInput);
  
  // std :: cout << "finish" << std ::endl;
  return 0;
}
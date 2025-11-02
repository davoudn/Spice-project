#include <iostream>
#include "antlr4-runtime.h"
#include "generated/TLexer.h"
#include "generated/TParser.h"
#include "generated/TParserBaseVisitor.h"


#include <fstream>
#include <string>
#include "vector"
#include "map"

using namespace antlrcpptest;
using namespace antlr4;

class CircuitParser : TParserBaseVisitor{
  public:

    std :: vector<std::map<std::string,std::string>> ElementVector;
    CircuitParser(){};
  
  std::any visitCircuit(TParser::CircuitContext *ctx) override {
    return visitChildren(ctx);
  }

  std::any visitElement(TParser::ElementContext *ctx) override {
    return visitChildren(ctx);
  }

  std::any visitVoltagesource(TParser::VoltagesourceContext *ctx) override {
    std :: map<std :: string, std :: string> temp;
    temp["Voltage"] = ctx->COMPONENT_VALUE(0)->toString();
    temp["NegNET"] = ctx->TEXT(1)->toString();
    temp["PosNET"] = ctx->TEXT(0)->toString();
    temp["name"] = ctx->VOLTAGE_SOURCE_NAME()->toString();
    temp["type"] = "VoltageSource";
    ElementVector.push_back(temp);
    return visitChildren(ctx);
  }

  std::any visitCurrentsource(TParser::CurrentsourceContext *ctx) override {
    std :: map<std :: string, std :: string> temp;
    temp["Current"] = ctx->COMPONENT_VALUE(0)->toString();
    temp["NegNET"] = ctx->TEXT(1)->toString();
    temp["PosNET"] = ctx->TEXT(0)->toString();
    temp["name"] = ctx->CURRENT_SOURCE_NAME()->toString();
    temp["type"] = "CurrentSource";
    ElementVector.push_back(temp);
    return visitChildren(ctx);
  }

  std::any visitResistor(TParser::ResistorContext *ctx) override {
    std :: map<std :: string, std :: string> temp;
    temp["Resistance"] = ctx->COMPONENT_VALUE(0)->toString();
    temp["NegNET"] = ctx->TEXT(1)->toString();
    temp["PosNET"] = ctx->TEXT(0)->toString();
    temp["name"] = ctx->RESISTOR_NAME()->toString();
    temp["type"] = "Resistor";
    ElementVector.push_back(temp);
    return visitChildren(ctx);
  }

  std::any visitCapacitor(TParser::CapacitorContext *ctx) override {
    std :: map<std :: string, std :: string> temp;
    for(auto item : ctx->PARAMS()){
        temp["Params"] = item->toString();
    }
    
    temp["Capacitance"] = ctx->COMPONENT_VALUE(0)->toString();
    temp["NegNET"] = ctx->TEXT(1)->toString();
    temp["PosNET"] = ctx->TEXT(0)->toString();
    temp["name"] = ctx->CAPACITOR_NAME()->toString();
    temp["type"] = "Capacitor";
    return visitChildren(ctx);
  }

  std::any visitInductor(TParser::InductorContext *ctx) override {
    std :: map<std :: string, std :: string> temp;
    temp["Inductance"] = ctx->COMPONENT_VALUE(0)->toString();
    temp["NegNET"] = ctx->TEXT(1)->toString();
    temp["PosNET"] = ctx->TEXT(0)->toString();
    temp["name"] = ctx->INDUCTOR_NAME()->toString();
    temp["type"] = "Inductor";
    return visitChildren(ctx);
  }
  void print_element(){
    for(auto item : ElementVector){
      std :: map<std :: string, std :: string>::iterator it = item.begin();

      // Iterate through the map and print the elements
      while (it != item.end()) {
          std :: cout << it->first
              << " : " << it->second << std :: endl;
          ++it;
      }

      std :: cout << "----------------------------------------" << std :: endl;
    }
  }
};

std::vector<std :: map<std::string,std:: string>> ParseFile(std:: string FileName){
  std::ifstream buffer;
  buffer.open(FileName);
  if (!buffer.is_open()) {
    std::vector<std :: map<std::string,std:: string>> temp;
      std::cerr << "Error: Cannot open file " << FileName << std::endl;
      return temp;
  }
  ANTLRInputStream input(buffer);
  TLexer lexer(&input);
  CommonTokenStream tokens(&lexer);
  
  tokens.fill();
  TParser parser(&tokens);

  CircuitParser visitor;
  visitor.visitCircuit(parser.circuit());
  
  visitor.print_element();

  return visitor.ElementVector;
}

// int main(int argc ,const char* argv[]) {

//   if (argc != 2) {
//         std::cerr << "Usage: " << argv[0] << " <input-file>" << std::endl;
//         return 1;
//   }
//   ParseFile(argv[1]);

//   return 0;
// }


// Generated from TParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "TParserVisitor.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of TParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  TParserBaseVisitor : public TParserVisitor {
public:

  virtual std::any visitMain(TParser::MainContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResistor(TParser::ResistorContext *ctx) override {
    std :: cout << "Resistor Detect :  " << ctx->RESISTOR_NAME()->toString() << std :: endl;
    for(auto it : ctx->TEXT())
      std :: cout << "Nodes : " << it->toString() << std :: endl;
    
    for (auto it : ctx->COMPONENT_VALUE())
      std :: cout << "value is : " << it->toString() << std :: endl;
    
    std :: cout << "_________________________________" << std :: endl;
    return visitChildren(ctx);
  }

  virtual std::any visitCapacitor(TParser::CapacitorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInductor(TParser::InductorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMutual_inductor(TParser::Mutual_inductorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDiod(TParser::DiodContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlrcpptest

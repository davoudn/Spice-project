
// Generated from TParser.g4 by ANTLR 4.10

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

  virtual std::any visitCircuit(TParser::CircuitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElement(TParser::ElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVoltagesource(TParser::VoltagesourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCurrentsource(TParser::CurrentsourceContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitResistor(TParser::ResistorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitCapacitor(TParser::CapacitorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitInductor(TParser::InductorContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace antlrcpptest

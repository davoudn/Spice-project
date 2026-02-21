
// Generated from TParser.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "TParser.h"


namespace antlrcpptest {

/**
 * This interface defines an abstract listener for a parse tree produced by TParser.
 */
class  TParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCircuit(TParser::CircuitContext *ctx) = 0;
  virtual void exitCircuit(TParser::CircuitContext *ctx) = 0;

  virtual void enterElement(TParser::ElementContext *ctx) = 0;
  virtual void exitElement(TParser::ElementContext *ctx) = 0;

  virtual void enterVoltagesource(TParser::VoltagesourceContext *ctx) = 0;
  virtual void exitVoltagesource(TParser::VoltagesourceContext *ctx) = 0;

  virtual void enterCurrentsource(TParser::CurrentsourceContext *ctx) = 0;
  virtual void exitCurrentsource(TParser::CurrentsourceContext *ctx) = 0;

  virtual void enterResistor(TParser::ResistorContext *ctx) = 0;
  virtual void exitResistor(TParser::ResistorContext *ctx) = 0;

  virtual void enterCapacitor(TParser::CapacitorContext *ctx) = 0;
  virtual void exitCapacitor(TParser::CapacitorContext *ctx) = 0;

  virtual void enterInductor(TParser::InductorContext *ctx) = 0;
  virtual void exitInductor(TParser::InductorContext *ctx) = 0;


};

}  // namespace antlrcpptest

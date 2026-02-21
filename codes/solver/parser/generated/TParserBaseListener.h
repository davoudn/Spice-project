
// Generated from TParser.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"
#include "TParserListener.h"


namespace antlrcpptest {

/**
 * This class provides an empty implementation of TParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  TParserBaseListener : public TParserListener {
public:

  virtual void enterCircuit(TParser::CircuitContext * /*ctx*/) override { }
  virtual void exitCircuit(TParser::CircuitContext * /*ctx*/) override { }

  virtual void enterElement(TParser::ElementContext * /*ctx*/) override { }
  virtual void exitElement(TParser::ElementContext * /*ctx*/) override { }

  virtual void enterVoltagesource(TParser::VoltagesourceContext * /*ctx*/) override { }
  virtual void exitVoltagesource(TParser::VoltagesourceContext * /*ctx*/) override { }

  virtual void enterCurrentsource(TParser::CurrentsourceContext * /*ctx*/) override { }
  virtual void exitCurrentsource(TParser::CurrentsourceContext * /*ctx*/) override { }

  virtual void enterResistor(TParser::ResistorContext * /*ctx*/) override { }
  virtual void exitResistor(TParser::ResistorContext * /*ctx*/) override { }

  virtual void enterCapacitor(TParser::CapacitorContext * /*ctx*/) override { }
  virtual void exitCapacitor(TParser::CapacitorContext * /*ctx*/) override { }

  virtual void enterInductor(TParser::InductorContext * /*ctx*/) override { }
  virtual void exitInductor(TParser::InductorContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace antlrcpptest

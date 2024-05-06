
// Generated from TParser.g4 by ANTLR 4.13.1

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

  virtual void enterMain(TParser::MainContext * /*ctx*/) override { }
  virtual void exitMain(TParser::MainContext * /*ctx*/) override { }

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


// Generated from TParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  TParser : public antlr4::Parser {
public:
  enum {
    COMMENT = 1, WHITESPACE = 2, NEWLINE = 3, RESISTOR_NAME = 4, CAPACITOR_NAME = 5, 
    INDUCTOR_NAME = 6, VOLTAGE_SOURCE_NAME = 7, CURRENT_SOURCE_NAME = 8, 
    DC = 9, COMPONENT_VALUE = 10, NUMERIC_VALUE = 11, NUMBERS = 12, END = 13, 
    PARAMS = 14, TEXT = 15
  };

  enum {
    RuleCircuit = 0, RuleElement = 1, RuleVoltagesource = 2, RuleCurrentsource = 3, 
    RuleResistor = 4, RuleCapacitor = 5, RuleInductor = 6
  };

  explicit TParser(antlr4::TokenStream *input);

  TParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~TParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class CircuitContext;
  class ElementContext;
  class VoltagesourceContext;
  class CurrentsourceContext;
  class ResistorContext;
  class CapacitorContext;
  class InductorContext; 

  class  CircuitContext : public antlr4::ParserRuleContext {
  public:
    CircuitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *EOF();
    std::vector<ElementContext *> element();
    ElementContext* element(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CircuitContext* circuit();

  class  ElementContext : public antlr4::ParserRuleContext {
  public:
    ElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CapacitorContext *capacitor();
    ResistorContext *resistor();
    InductorContext *inductor();
    VoltagesourceContext *voltagesource();
    CurrentsourceContext *currentsource();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementContext* element();

  class  VoltagesourceContext : public antlr4::ParserRuleContext {
  public:
    VoltagesourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VOLTAGE_SOURCE_NAME();
    std::vector<antlr4::tree::TerminalNode *> TEXT();
    antlr4::tree::TerminalNode* TEXT(size_t i);
    antlr4::tree::TerminalNode *DC();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMPONENT_VALUE();
    antlr4::tree::TerminalNode* COMPONENT_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VoltagesourceContext* voltagesource();

  class  CurrentsourceContext : public antlr4::ParserRuleContext {
  public:
    CurrentsourceContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CURRENT_SOURCE_NAME();
    std::vector<antlr4::tree::TerminalNode *> TEXT();
    antlr4::tree::TerminalNode* TEXT(size_t i);
    antlr4::tree::TerminalNode *DC();
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMPONENT_VALUE();
    antlr4::tree::TerminalNode* COMPONENT_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CurrentsourceContext* currentsource();

  class  ResistorContext : public antlr4::ParserRuleContext {
  public:
    ResistorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESISTOR_NAME();
    std::vector<antlr4::tree::TerminalNode *> TEXT();
    antlr4::tree::TerminalNode* TEXT(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMPONENT_VALUE();
    antlr4::tree::TerminalNode* COMPONENT_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ResistorContext* resistor();

  class  CapacitorContext : public antlr4::ParserRuleContext {
  public:
    CapacitorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CAPACITOR_NAME();
    std::vector<antlr4::tree::TerminalNode *> TEXT();
    antlr4::tree::TerminalNode* TEXT(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMPONENT_VALUE();
    antlr4::tree::TerminalNode* COMPONENT_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CapacitorContext* capacitor();

  class  InductorContext : public antlr4::ParserRuleContext {
  public:
    InductorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INDUCTOR_NAME();
    std::vector<antlr4::tree::TerminalNode *> TEXT();
    antlr4::tree::TerminalNode* TEXT(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMPONENT_VALUE();
    antlr4::tree::TerminalNode* COMPONENT_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InductorContext* inductor();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace antlrcpptest

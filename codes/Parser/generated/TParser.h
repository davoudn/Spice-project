
// Generated from TParser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  TParser : public antlr4::Parser {
public:
  enum {
    COMMENT = 1, WHITESPACE = 2, NEWLINE = 3, RESISTOR_NAME = 4, CAPACITOR_NAME = 5, 
    INDUCTOR_NAME = 6, MUTUAL_INDUCTOR_NAME = 7, DIOD_NAME = 8, BJT_NAME = 9, 
    MOSFET_NAME = 10, JFET_NAME = 11, VOLTAGE_SOURCE_NAME = 12, CURRENT_SOURCE_NAME = 13, 
    PALSE = 14, SIN = 15, EXP = 16, PWL = 17, MODEL = 18, OFF = 19, COMPONENT_VALUE = 20, 
    NUMERIC_VALUE = 21, NUMBERS = 22, END = 23, PARAMS = 24, TEXT = 25
  };

  enum {
    RuleMain = 0, RuleResistor = 1, RuleCapacitor = 2, RuleInductor = 3, 
    RuleMutual_inductor = 4, RuleDiod = 5
  };

  explicit TParser(antlr4::TokenStream *input);

  TParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~TParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class MainContext;
  class ResistorContext;
  class CapacitorContext;
  class InductorContext;
  class Mutual_inductorContext;
  class DiodContext; 

  class  MainContext : public antlr4::ParserRuleContext {
  public:
    MainContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ResistorContext *> resistor();
    ResistorContext* resistor(size_t i);
    std::vector<CapacitorContext *> capacitor();
    CapacitorContext* capacitor(size_t i);
    std::vector<InductorContext *> inductor();
    InductorContext* inductor(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MainContext* main();

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

  class  Mutual_inductorContext : public antlr4::ParserRuleContext {
  public:
    Mutual_inductorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MUTUAL_INDUCTOR_NAME();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> INDUCTOR_NAME();
    antlr4::tree::TerminalNode* INDUCTOR_NAME(size_t i);
    antlr4::tree::TerminalNode *COMPONENT_VALUE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Mutual_inductorContext* mutual_inductor();

  class  DiodContext : public antlr4::ParserRuleContext {
  public:
    DiodContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RESISTOR_NAME();
    std::vector<antlr4::tree::TerminalNode *> TEXT();
    antlr4::tree::TerminalNode* TEXT(size_t i);
    antlr4::tree::TerminalNode *NEWLINE();
    std::vector<antlr4::tree::TerminalNode *> WHITESPACE();
    antlr4::tree::TerminalNode* WHITESPACE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DiodContext* diod();


  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

}  // namespace antlrcpptest

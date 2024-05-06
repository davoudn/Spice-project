
// Generated from TParser.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  TParser : public antlr4::Parser {
public:
  enum {
    COMMENT = 1, WHITESPACE = 2, NEWLINE = 3, RESISTOR_NAME = 4, CAPACITOR_NAME = 5, 
    INDUCTOR_NAME = 6, COMPONENT_VALUE = 7, NUMERIC_VALUE = 8, NUMBERS = 9, 
    END = 10, PARAMS = 11, TEXT = 12
  };

  enum {
    RuleMain = 0, RuleResistor = 1, RuleCapacitor = 2, RuleInductor = 3
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

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

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
    std::vector<antlr4::tree::TerminalNode *> NUMERIC_VALUE();
    antlr4::tree::TerminalNode* NUMERIC_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

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
    std::vector<antlr4::tree::TerminalNode *> NUMERIC_VALUE();
    antlr4::tree::TerminalNode* NUMERIC_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

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
    std::vector<antlr4::tree::TerminalNode *> NUMERIC_VALUE();
    antlr4::tree::TerminalNode* NUMERIC_VALUE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PARAMS();
    antlr4::tree::TerminalNode* PARAMS(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

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

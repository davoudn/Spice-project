
// Generated from TLexer.g4 by ANTLR 4.10

#pragma once


#include "antlr4-runtime.h"


namespace antlrcpptest {


class  TLexer : public antlr4::Lexer {
public:
  enum {
    COMMENT = 1, WHITESPACE = 2, NEWLINE = 3, RESISTOR_NAME = 4, CAPACITOR_NAME = 5, 
    INDUCTOR_NAME = 6, VOLTAGE_SOURCE_NAME = 7, CURRENT_SOURCE_NAME = 8, 
    DC = 9, COMPONENT_VALUE = 10, NUMERIC_VALUE = 11, NUMBERS = 12, END = 13, 
    PARAMS = 14, TEXT = 15
  };

  explicit TLexer(antlr4::CharStream *input);

  ~TLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

}  // namespace antlrcpptest

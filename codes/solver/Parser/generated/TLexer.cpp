
// Generated from TLexer.g4 by ANTLR 4.13.2


#include "TLexer.h"


using namespace antlr4;

using namespace antlrcpptest;


using namespace antlr4;

namespace {

struct TLexerStaticData final {
  TLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TLexerStaticData(const TLexerStaticData&) = delete;
  TLexerStaticData(TLexerStaticData&&) = delete;
  TLexerStaticData& operator=(const TLexerStaticData&) = delete;
  TLexerStaticData& operator=(TLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<TLexerStaticData> tlexerLexerStaticData = nullptr;

void tlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (tlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(tlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TLexerStaticData>(
    std::vector<std::string>{
      "COMMENT", "WHITESPACE", "NEWLINE", "RESISTOR_NAME", "CAPACITOR_NAME", 
      "INDUCTOR_NAME", "VOLTAGE_SOURCE_NAME", "CURRENT_SOURCE_NAME", "DC", 
      "COMPONENT_VALUE", "NUMERIC_VALUE", "NUMBERS", "END", "PARAMS", "TEXT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "'DC'", "", "", "", "'.end'"
    },
    std::vector<std::string>{
      "", "COMMENT", "WHITESPACE", "NEWLINE", "RESISTOR_NAME", "CAPACITOR_NAME", 
      "INDUCTOR_NAME", "VOLTAGE_SOURCE_NAME", "CURRENT_SOURCE_NAME", "DC", 
      "COMPONENT_VALUE", "NUMERIC_VALUE", "NUMBERS", "END", "PARAMS", "TEXT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,15,155,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,1,0,1,0,5,0,34,8,0,10,0,12,0,37,9,0,1,0,1,0,1,1,1,1,1,2,3,2,44,8,
  	2,1,2,1,2,4,2,48,8,2,11,2,12,2,49,1,3,1,3,4,3,54,8,3,11,3,12,3,55,1,4,
  	1,4,4,4,60,8,4,11,4,12,4,61,1,5,1,5,4,5,66,8,5,11,5,12,5,67,1,6,1,6,4,
  	6,72,8,6,11,6,12,6,73,1,7,1,7,4,7,78,8,7,11,7,12,7,79,1,8,1,8,1,8,1,9,
  	4,9,86,8,9,11,9,12,9,87,1,9,1,9,1,9,4,9,93,8,9,11,9,12,9,94,3,9,97,8,
  	9,1,10,1,10,1,10,1,10,1,10,1,10,5,10,105,8,10,10,10,12,10,108,9,10,1,
  	10,5,10,111,8,10,10,10,12,10,114,9,10,1,11,4,11,117,8,11,11,11,12,11,
  	118,1,12,1,12,1,12,1,12,1,12,1,13,4,13,127,8,13,11,13,12,13,128,1,13,
  	5,13,132,8,13,10,13,12,13,135,9,13,1,13,1,13,4,13,139,8,13,11,13,12,13,
  	140,1,13,5,13,144,8,13,10,13,12,13,147,9,13,1,14,1,14,5,14,151,8,14,10,
  	14,12,14,154,9,14,0,0,15,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,
  	21,11,23,12,25,13,27,14,29,15,1,0,5,1,0,10,10,2,0,9,9,32,32,10,0,71,71,
  	77,77,80,80,84,84,97,97,102,102,107,107,109,110,112,112,117,117,1,0,48,
  	57,2,0,9,10,32,32,176,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,
  	0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,
  	0,0,1,31,1,0,0,0,3,40,1,0,0,0,5,47,1,0,0,0,7,51,1,0,0,0,9,57,1,0,0,0,
  	11,63,1,0,0,0,13,69,1,0,0,0,15,75,1,0,0,0,17,81,1,0,0,0,19,96,1,0,0,0,
  	21,98,1,0,0,0,23,116,1,0,0,0,25,120,1,0,0,0,27,126,1,0,0,0,29,148,1,0,
  	0,0,31,35,5,42,0,0,32,34,8,0,0,0,33,32,1,0,0,0,34,37,1,0,0,0,35,33,1,
  	0,0,0,35,36,1,0,0,0,36,38,1,0,0,0,37,35,1,0,0,0,38,39,5,10,0,0,39,2,1,
  	0,0,0,40,41,7,1,0,0,41,4,1,0,0,0,42,44,5,13,0,0,43,42,1,0,0,0,43,44,1,
  	0,0,0,44,45,1,0,0,0,45,48,5,10,0,0,46,48,5,13,0,0,47,43,1,0,0,0,47,46,
  	1,0,0,0,48,49,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,6,1,0,0,0,51,53,
  	5,82,0,0,52,54,3,29,14,0,53,52,1,0,0,0,54,55,1,0,0,0,55,53,1,0,0,0,55,
  	56,1,0,0,0,56,8,1,0,0,0,57,59,5,67,0,0,58,60,3,29,14,0,59,58,1,0,0,0,
  	60,61,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,10,1,0,0,0,63,65,5,76,0,
  	0,64,66,3,29,14,0,65,64,1,0,0,0,66,67,1,0,0,0,67,65,1,0,0,0,67,68,1,0,
  	0,0,68,12,1,0,0,0,69,71,5,86,0,0,70,72,3,29,14,0,71,70,1,0,0,0,72,73,
  	1,0,0,0,73,71,1,0,0,0,73,74,1,0,0,0,74,14,1,0,0,0,75,77,5,73,0,0,76,78,
  	3,29,14,0,77,76,1,0,0,0,78,79,1,0,0,0,79,77,1,0,0,0,79,80,1,0,0,0,80,
  	16,1,0,0,0,81,82,5,68,0,0,82,83,5,67,0,0,83,18,1,0,0,0,84,86,3,21,10,
  	0,85,84,1,0,0,0,86,87,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,89,1,0,0,
  	0,89,90,7,2,0,0,90,97,1,0,0,0,91,93,3,21,10,0,92,91,1,0,0,0,93,94,1,0,
  	0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,97,1,0,0,0,96,85,1,0,0,0,96,92,1,0,
  	0,0,97,20,1,0,0,0,98,106,3,23,11,0,99,105,5,46,0,0,100,101,5,101,0,0,
  	101,105,5,45,0,0,102,103,5,69,0,0,103,105,5,45,0,0,104,99,1,0,0,0,104,
  	100,1,0,0,0,104,102,1,0,0,0,105,108,1,0,0,0,106,104,1,0,0,0,106,107,1,
  	0,0,0,107,112,1,0,0,0,108,106,1,0,0,0,109,111,3,23,11,0,110,109,1,0,0,
  	0,111,114,1,0,0,0,112,110,1,0,0,0,112,113,1,0,0,0,113,22,1,0,0,0,114,
  	112,1,0,0,0,115,117,7,3,0,0,116,115,1,0,0,0,117,118,1,0,0,0,118,116,1,
  	0,0,0,118,119,1,0,0,0,119,24,1,0,0,0,120,121,5,46,0,0,121,122,5,101,0,
  	0,122,123,5,110,0,0,123,124,5,100,0,0,124,26,1,0,0,0,125,127,3,29,14,
  	0,126,125,1,0,0,0,127,128,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,
  	133,1,0,0,0,130,132,3,3,1,0,131,130,1,0,0,0,132,135,1,0,0,0,133,131,1,
  	0,0,0,133,134,1,0,0,0,134,136,1,0,0,0,135,133,1,0,0,0,136,138,5,61,0,
  	0,137,139,3,29,14,0,138,137,1,0,0,0,139,140,1,0,0,0,140,138,1,0,0,0,140,
  	141,1,0,0,0,141,145,1,0,0,0,142,144,3,3,1,0,143,142,1,0,0,0,144,147,1,
  	0,0,0,145,143,1,0,0,0,145,146,1,0,0,0,146,28,1,0,0,0,147,145,1,0,0,0,
  	148,152,8,4,0,0,149,151,8,4,0,0,150,149,1,0,0,0,151,154,1,0,0,0,152,150,
  	1,0,0,0,152,153,1,0,0,0,153,30,1,0,0,0,154,152,1,0,0,0,22,0,35,43,47,
  	49,55,61,67,73,79,87,94,96,104,106,112,118,128,133,140,145,152,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tlexerLexerStaticData = std::move(staticData);
}

}

TLexer::TLexer(CharStream *input) : Lexer(input) {
  TLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *tlexerLexerStaticData->atn, tlexerLexerStaticData->decisionToDFA, tlexerLexerStaticData->sharedContextCache);
}

TLexer::~TLexer() {
  delete _interpreter;
}

std::string TLexer::getGrammarFileName() const {
  return "TLexer.g4";
}

const std::vector<std::string>& TLexer::getRuleNames() const {
  return tlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& TLexer::getChannelNames() const {
  return tlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& TLexer::getModeNames() const {
  return tlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& TLexer::getVocabulary() const {
  return tlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TLexer::getSerializedATN() const {
  return tlexerLexerStaticData->serializedATN;
}

const atn::ATN& TLexer::getATN() const {
  return *tlexerLexerStaticData->atn;
}




void TLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  tlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(tlexerLexerOnceFlag, tlexerLexerInitialize);
#endif
}

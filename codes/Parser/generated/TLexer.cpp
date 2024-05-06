
// Generated from TLexer.g4 by ANTLR 4.13.1


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
TLexerStaticData *tlexerLexerStaticData = nullptr;

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
      "INDUCTOR_NAME", "COMPONENT_VALUE", "NUMERIC_VALUE", "NUMBERS", "END", 
      "PARAMS", "TEXT"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "'.end'"
    },
    std::vector<std::string>{
      "", "COMMENT", "WHITESPACE", "NEWLINE", "RESISTOR_NAME", "CAPACITOR_NAME", 
      "INDUCTOR_NAME", "COMPONENT_VALUE", "NUMERIC_VALUE", "NUMBERS", "END", 
      "PARAMS", "TEXT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,12,199,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,5,0,28,8,0,10,0,
  	12,0,31,9,0,1,0,1,0,1,1,1,1,1,2,3,2,38,8,2,1,2,1,2,4,2,42,8,2,11,2,12,
  	2,43,1,3,1,3,4,3,48,8,3,11,3,12,3,49,1,4,1,4,4,4,54,8,4,11,4,12,4,55,
  	1,5,1,5,4,5,60,8,5,11,5,12,5,61,1,6,4,6,65,8,6,11,6,12,6,66,1,6,1,6,1,
  	6,4,6,72,8,6,11,6,12,6,73,1,6,1,6,1,6,4,6,79,8,6,11,6,12,6,80,1,6,1,6,
  	1,6,4,6,86,8,6,11,6,12,6,87,1,6,1,6,1,6,4,6,93,8,6,11,6,12,6,94,1,6,1,
  	6,1,6,4,6,100,8,6,11,6,12,6,101,1,6,1,6,1,6,4,6,107,8,6,11,6,12,6,108,
  	1,6,1,6,1,6,4,6,114,8,6,11,6,12,6,115,1,6,1,6,1,6,4,6,121,8,6,11,6,12,
  	6,122,1,6,1,6,1,6,4,6,128,8,6,11,6,12,6,129,1,6,1,6,1,6,4,6,135,8,6,11,
  	6,12,6,136,1,6,1,6,3,6,141,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,3,7,158,8,7,1,8,4,8,161,8,8,11,8,12,8,162,1,9,1,
  	9,1,9,1,9,1,9,1,10,4,10,171,8,10,11,10,12,10,172,1,10,5,10,176,8,10,10,
  	10,12,10,179,9,10,1,10,1,10,4,10,183,8,10,11,10,12,10,184,1,10,5,10,188,
  	8,10,10,10,12,10,191,9,10,1,11,1,11,5,11,195,8,11,10,11,12,11,198,9,11,
  	0,0,12,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,1,0,
  	4,1,0,10,10,2,0,9,9,32,32,1,0,48,57,2,0,9,10,32,32,235,0,1,1,0,0,0,0,
  	3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,
  	0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,1,
  	25,1,0,0,0,3,34,1,0,0,0,5,41,1,0,0,0,7,45,1,0,0,0,9,51,1,0,0,0,11,57,
  	1,0,0,0,13,140,1,0,0,0,15,157,1,0,0,0,17,160,1,0,0,0,19,164,1,0,0,0,21,
  	170,1,0,0,0,23,192,1,0,0,0,25,29,5,42,0,0,26,28,8,0,0,0,27,26,1,0,0,0,
  	28,31,1,0,0,0,29,27,1,0,0,0,29,30,1,0,0,0,30,32,1,0,0,0,31,29,1,0,0,0,
  	32,33,5,10,0,0,33,2,1,0,0,0,34,35,7,1,0,0,35,4,1,0,0,0,36,38,5,13,0,0,
  	37,36,1,0,0,0,37,38,1,0,0,0,38,39,1,0,0,0,39,42,5,10,0,0,40,42,5,13,0,
  	0,41,37,1,0,0,0,41,40,1,0,0,0,42,43,1,0,0,0,43,41,1,0,0,0,43,44,1,0,0,
  	0,44,6,1,0,0,0,45,47,5,82,0,0,46,48,3,17,8,0,47,46,1,0,0,0,48,49,1,0,
  	0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,8,1,0,0,0,51,53,5,67,0,0,52,54,3,17,
  	8,0,53,52,1,0,0,0,54,55,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,10,1,0,
  	0,0,57,59,5,76,0,0,58,60,3,17,8,0,59,58,1,0,0,0,60,61,1,0,0,0,61,59,1,
  	0,0,0,61,62,1,0,0,0,62,12,1,0,0,0,63,65,3,15,7,0,64,63,1,0,0,0,65,66,
  	1,0,0,0,66,64,1,0,0,0,66,67,1,0,0,0,67,68,1,0,0,0,68,69,5,80,0,0,69,141,
  	1,0,0,0,70,72,3,15,7,0,71,70,1,0,0,0,72,73,1,0,0,0,73,71,1,0,0,0,73,74,
  	1,0,0,0,74,75,1,0,0,0,75,76,5,84,0,0,76,141,1,0,0,0,77,79,3,15,7,0,78,
  	77,1,0,0,0,79,80,1,0,0,0,80,78,1,0,0,0,80,81,1,0,0,0,81,82,1,0,0,0,82,
  	83,5,71,0,0,83,141,1,0,0,0,84,86,3,15,7,0,85,84,1,0,0,0,86,87,1,0,0,0,
  	87,85,1,0,0,0,87,88,1,0,0,0,88,89,1,0,0,0,89,90,5,77,0,0,90,141,1,0,0,
  	0,91,93,3,15,7,0,92,91,1,0,0,0,93,94,1,0,0,0,94,92,1,0,0,0,94,95,1,0,
  	0,0,95,96,1,0,0,0,96,97,5,107,0,0,97,141,1,0,0,0,98,100,3,15,7,0,99,98,
  	1,0,0,0,100,101,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,102,103,1,0,0,
  	0,103,104,5,109,0,0,104,141,1,0,0,0,105,107,3,15,7,0,106,105,1,0,0,0,
  	107,108,1,0,0,0,108,106,1,0,0,0,108,109,1,0,0,0,109,110,1,0,0,0,110,111,
  	5,117,0,0,111,141,1,0,0,0,112,114,3,15,7,0,113,112,1,0,0,0,114,115,1,
  	0,0,0,115,113,1,0,0,0,115,116,1,0,0,0,116,117,1,0,0,0,117,118,5,110,0,
  	0,118,141,1,0,0,0,119,121,3,15,7,0,120,119,1,0,0,0,121,122,1,0,0,0,122,
  	120,1,0,0,0,122,123,1,0,0,0,123,124,1,0,0,0,124,125,5,112,0,0,125,141,
  	1,0,0,0,126,128,3,15,7,0,127,126,1,0,0,0,128,129,1,0,0,0,129,127,1,0,
  	0,0,129,130,1,0,0,0,130,131,1,0,0,0,131,132,5,102,0,0,132,141,1,0,0,0,
  	133,135,3,15,7,0,134,133,1,0,0,0,135,136,1,0,0,0,136,134,1,0,0,0,136,
  	137,1,0,0,0,137,138,1,0,0,0,138,139,5,97,0,0,139,141,1,0,0,0,140,64,1,
  	0,0,0,140,71,1,0,0,0,140,78,1,0,0,0,140,85,1,0,0,0,140,92,1,0,0,0,140,
  	99,1,0,0,0,140,106,1,0,0,0,140,113,1,0,0,0,140,120,1,0,0,0,140,127,1,
  	0,0,0,140,134,1,0,0,0,141,14,1,0,0,0,142,143,3,17,8,0,143,144,5,46,0,
  	0,144,145,3,17,8,0,145,158,1,0,0,0,146,158,3,17,8,0,147,148,3,17,8,0,
  	148,149,5,101,0,0,149,150,5,45,0,0,150,151,3,17,8,0,151,158,1,0,0,0,152,
  	153,3,17,8,0,153,154,5,69,0,0,154,155,5,45,0,0,155,156,3,17,8,0,156,158,
  	1,0,0,0,157,142,1,0,0,0,157,146,1,0,0,0,157,147,1,0,0,0,157,152,1,0,0,
  	0,158,16,1,0,0,0,159,161,7,2,0,0,160,159,1,0,0,0,161,162,1,0,0,0,162,
  	160,1,0,0,0,162,163,1,0,0,0,163,18,1,0,0,0,164,165,5,46,0,0,165,166,5,
  	101,0,0,166,167,5,110,0,0,167,168,5,100,0,0,168,20,1,0,0,0,169,171,3,
  	23,11,0,170,169,1,0,0,0,171,172,1,0,0,0,172,170,1,0,0,0,172,173,1,0,0,
  	0,173,177,1,0,0,0,174,176,3,3,1,0,175,174,1,0,0,0,176,179,1,0,0,0,177,
  	175,1,0,0,0,177,178,1,0,0,0,178,180,1,0,0,0,179,177,1,0,0,0,180,182,5,
  	61,0,0,181,183,3,23,11,0,182,181,1,0,0,0,183,184,1,0,0,0,184,182,1,0,
  	0,0,184,185,1,0,0,0,185,189,1,0,0,0,186,188,3,3,1,0,187,186,1,0,0,0,188,
  	191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,22,1,0,0,0,191,189,1,
  	0,0,0,192,196,8,3,0,0,193,195,8,3,0,0,194,193,1,0,0,0,195,198,1,0,0,0,
  	196,194,1,0,0,0,196,197,1,0,0,0,197,24,1,0,0,0,198,196,1,0,0,0,27,0,29,
  	37,41,43,49,55,61,66,73,80,87,94,101,108,115,122,129,136,140,157,162,
  	172,177,184,189,196,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tlexerLexerStaticData = staticData.release();
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


// Generated from TParser.g4 by ANTLR 4.13.1


#include "TParserListener.h"
#include "TParserVisitor.h"

#include "TParser.h"


using namespace antlrcpp;
using namespace antlrcpptest;

using namespace antlr4;

namespace {

struct TParserStaticData final {
  TParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  TParserStaticData(const TParserStaticData&) = delete;
  TParserStaticData(TParserStaticData&&) = delete;
  TParserStaticData& operator=(const TParserStaticData&) = delete;
  TParserStaticData& operator=(TParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag tparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
TParserStaticData *tparserParserStaticData = nullptr;

void tparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (tparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(tparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<TParserStaticData>(
    std::vector<std::string>{
      "main", "resistor", "capacitor", "inductor"
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
  	4,1,12,309,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,1,0,5,0,10,8,0,10,0,12,0,13,
  	9,0,1,0,5,0,16,8,0,10,0,12,0,19,9,0,1,0,5,0,22,8,0,10,0,12,0,25,9,0,1,
  	1,1,1,4,1,29,8,1,11,1,12,1,30,1,1,1,1,4,1,35,8,1,11,1,12,1,36,1,1,1,1,
  	4,1,41,8,1,11,1,12,1,42,1,1,4,1,46,8,1,11,1,12,1,47,1,1,4,1,51,8,1,11,
  	1,12,1,52,1,1,5,1,56,8,1,10,1,12,1,59,9,1,1,1,5,1,62,8,1,10,1,12,1,65,
  	9,1,1,1,1,1,1,1,4,1,70,8,1,11,1,12,1,71,1,1,1,1,4,1,76,8,1,11,1,12,1,
  	77,1,1,1,1,4,1,82,8,1,11,1,12,1,83,1,1,5,1,87,8,1,10,1,12,1,90,9,1,1,
  	1,5,1,93,8,1,10,1,12,1,96,9,1,1,1,1,1,1,1,4,1,101,8,1,11,1,12,1,102,1,
  	1,1,1,4,1,107,8,1,11,1,12,1,108,1,1,1,1,5,1,113,8,1,10,1,12,1,116,9,1,
  	1,1,3,1,119,8,1,1,2,1,2,4,2,123,8,2,11,2,12,2,124,1,2,1,2,4,2,129,8,2,
  	11,2,12,2,130,1,2,1,2,4,2,135,8,2,11,2,12,2,136,1,2,4,2,140,8,2,11,2,
  	12,2,141,1,2,4,2,145,8,2,11,2,12,2,146,1,2,5,2,150,8,2,10,2,12,2,153,
  	9,2,1,2,5,2,156,8,2,10,2,12,2,159,9,2,1,2,1,2,1,2,4,2,164,8,2,11,2,12,
  	2,165,1,2,1,2,4,2,170,8,2,11,2,12,2,171,1,2,1,2,4,2,176,8,2,11,2,12,2,
  	177,1,2,5,2,181,8,2,10,2,12,2,184,9,2,1,2,5,2,187,8,2,10,2,12,2,190,9,
  	2,1,2,1,2,1,2,4,2,195,8,2,11,2,12,2,196,1,2,1,2,4,2,201,8,2,11,2,12,2,
  	202,1,2,1,2,5,2,207,8,2,10,2,12,2,210,9,2,1,2,3,2,213,8,2,1,3,1,3,4,3,
  	217,8,3,11,3,12,3,218,1,3,1,3,4,3,223,8,3,11,3,12,3,224,1,3,1,3,4,3,229,
  	8,3,11,3,12,3,230,1,3,4,3,234,8,3,11,3,12,3,235,1,3,4,3,239,8,3,11,3,
  	12,3,240,1,3,5,3,244,8,3,10,3,12,3,247,9,3,1,3,5,3,250,8,3,10,3,12,3,
  	253,9,3,1,3,1,3,1,3,4,3,258,8,3,11,3,12,3,259,1,3,1,3,4,3,264,8,3,11,
  	3,12,3,265,1,3,1,3,4,3,270,8,3,11,3,12,3,271,1,3,5,3,275,8,3,10,3,12,
  	3,278,9,3,1,3,5,3,281,8,3,10,3,12,3,284,9,3,1,3,1,3,1,3,4,3,289,8,3,11,
  	3,12,3,290,1,3,1,3,4,3,295,8,3,11,3,12,3,296,1,3,1,3,5,3,301,8,3,10,3,
  	12,3,304,9,3,1,3,3,3,307,8,3,1,3,0,0,4,0,2,4,6,0,0,358,0,11,1,0,0,0,2,
  	118,1,0,0,0,4,212,1,0,0,0,6,306,1,0,0,0,8,10,3,2,1,0,9,8,1,0,0,0,10,13,
  	1,0,0,0,11,9,1,0,0,0,11,12,1,0,0,0,12,17,1,0,0,0,13,11,1,0,0,0,14,16,
  	3,4,2,0,15,14,1,0,0,0,16,19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,23,
  	1,0,0,0,19,17,1,0,0,0,20,22,3,6,3,0,21,20,1,0,0,0,22,25,1,0,0,0,23,21,
  	1,0,0,0,23,24,1,0,0,0,24,1,1,0,0,0,25,23,1,0,0,0,26,28,5,4,0,0,27,29,
  	5,2,0,0,28,27,1,0,0,0,29,30,1,0,0,0,30,28,1,0,0,0,30,31,1,0,0,0,31,32,
  	1,0,0,0,32,34,5,12,0,0,33,35,5,2,0,0,34,33,1,0,0,0,35,36,1,0,0,0,36,34,
  	1,0,0,0,36,37,1,0,0,0,37,38,1,0,0,0,38,40,5,12,0,0,39,41,5,2,0,0,40,39,
  	1,0,0,0,41,42,1,0,0,0,42,40,1,0,0,0,42,43,1,0,0,0,43,45,1,0,0,0,44,46,
  	5,8,0,0,45,44,1,0,0,0,46,47,1,0,0,0,47,45,1,0,0,0,47,48,1,0,0,0,48,50,
  	1,0,0,0,49,51,5,2,0,0,50,49,1,0,0,0,51,52,1,0,0,0,52,50,1,0,0,0,52,53,
  	1,0,0,0,53,57,1,0,0,0,54,56,5,11,0,0,55,54,1,0,0,0,56,59,1,0,0,0,57,55,
  	1,0,0,0,57,58,1,0,0,0,58,63,1,0,0,0,59,57,1,0,0,0,60,62,5,2,0,0,61,60,
  	1,0,0,0,62,65,1,0,0,0,63,61,1,0,0,0,63,64,1,0,0,0,64,66,1,0,0,0,65,63,
  	1,0,0,0,66,119,5,3,0,0,67,69,5,4,0,0,68,70,5,2,0,0,69,68,1,0,0,0,70,71,
  	1,0,0,0,71,69,1,0,0,0,71,72,1,0,0,0,72,73,1,0,0,0,73,75,5,12,0,0,74,76,
  	5,2,0,0,75,74,1,0,0,0,76,77,1,0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,79,
  	1,0,0,0,79,81,5,12,0,0,80,82,5,2,0,0,81,80,1,0,0,0,82,83,1,0,0,0,83,81,
  	1,0,0,0,83,84,1,0,0,0,84,88,1,0,0,0,85,87,5,8,0,0,86,85,1,0,0,0,87,90,
  	1,0,0,0,88,86,1,0,0,0,88,89,1,0,0,0,89,94,1,0,0,0,90,88,1,0,0,0,91,93,
  	5,2,0,0,92,91,1,0,0,0,93,96,1,0,0,0,94,92,1,0,0,0,94,95,1,0,0,0,95,97,
  	1,0,0,0,96,94,1,0,0,0,97,119,5,3,0,0,98,100,5,4,0,0,99,101,5,2,0,0,100,
  	99,1,0,0,0,101,102,1,0,0,0,102,100,1,0,0,0,102,103,1,0,0,0,103,104,1,
  	0,0,0,104,106,5,12,0,0,105,107,5,2,0,0,106,105,1,0,0,0,107,108,1,0,0,
  	0,108,106,1,0,0,0,108,109,1,0,0,0,109,110,1,0,0,0,110,114,5,12,0,0,111,
  	113,5,2,0,0,112,111,1,0,0,0,113,116,1,0,0,0,114,112,1,0,0,0,114,115,1,
  	0,0,0,115,117,1,0,0,0,116,114,1,0,0,0,117,119,5,3,0,0,118,26,1,0,0,0,
  	118,67,1,0,0,0,118,98,1,0,0,0,119,3,1,0,0,0,120,122,5,5,0,0,121,123,5,
  	2,0,0,122,121,1,0,0,0,123,124,1,0,0,0,124,122,1,0,0,0,124,125,1,0,0,0,
  	125,126,1,0,0,0,126,128,5,12,0,0,127,129,5,2,0,0,128,127,1,0,0,0,129,
  	130,1,0,0,0,130,128,1,0,0,0,130,131,1,0,0,0,131,132,1,0,0,0,132,134,5,
  	12,0,0,133,135,5,2,0,0,134,133,1,0,0,0,135,136,1,0,0,0,136,134,1,0,0,
  	0,136,137,1,0,0,0,137,139,1,0,0,0,138,140,5,8,0,0,139,138,1,0,0,0,140,
  	141,1,0,0,0,141,139,1,0,0,0,141,142,1,0,0,0,142,144,1,0,0,0,143,145,5,
  	2,0,0,144,143,1,0,0,0,145,146,1,0,0,0,146,144,1,0,0,0,146,147,1,0,0,0,
  	147,151,1,0,0,0,148,150,5,11,0,0,149,148,1,0,0,0,150,153,1,0,0,0,151,
  	149,1,0,0,0,151,152,1,0,0,0,152,157,1,0,0,0,153,151,1,0,0,0,154,156,5,
  	2,0,0,155,154,1,0,0,0,156,159,1,0,0,0,157,155,1,0,0,0,157,158,1,0,0,0,
  	158,160,1,0,0,0,159,157,1,0,0,0,160,213,5,3,0,0,161,163,5,5,0,0,162,164,
  	5,2,0,0,163,162,1,0,0,0,164,165,1,0,0,0,165,163,1,0,0,0,165,166,1,0,0,
  	0,166,167,1,0,0,0,167,169,5,12,0,0,168,170,5,2,0,0,169,168,1,0,0,0,170,
  	171,1,0,0,0,171,169,1,0,0,0,171,172,1,0,0,0,172,173,1,0,0,0,173,175,5,
  	12,0,0,174,176,5,2,0,0,175,174,1,0,0,0,176,177,1,0,0,0,177,175,1,0,0,
  	0,177,178,1,0,0,0,178,182,1,0,0,0,179,181,5,8,0,0,180,179,1,0,0,0,181,
  	184,1,0,0,0,182,180,1,0,0,0,182,183,1,0,0,0,183,188,1,0,0,0,184,182,1,
  	0,0,0,185,187,5,2,0,0,186,185,1,0,0,0,187,190,1,0,0,0,188,186,1,0,0,0,
  	188,189,1,0,0,0,189,191,1,0,0,0,190,188,1,0,0,0,191,213,5,3,0,0,192,194,
  	5,5,0,0,193,195,5,2,0,0,194,193,1,0,0,0,195,196,1,0,0,0,196,194,1,0,0,
  	0,196,197,1,0,0,0,197,198,1,0,0,0,198,200,5,12,0,0,199,201,5,2,0,0,200,
  	199,1,0,0,0,201,202,1,0,0,0,202,200,1,0,0,0,202,203,1,0,0,0,203,204,1,
  	0,0,0,204,208,5,12,0,0,205,207,5,2,0,0,206,205,1,0,0,0,207,210,1,0,0,
  	0,208,206,1,0,0,0,208,209,1,0,0,0,209,211,1,0,0,0,210,208,1,0,0,0,211,
  	213,5,3,0,0,212,120,1,0,0,0,212,161,1,0,0,0,212,192,1,0,0,0,213,5,1,0,
  	0,0,214,216,5,6,0,0,215,217,5,2,0,0,216,215,1,0,0,0,217,218,1,0,0,0,218,
  	216,1,0,0,0,218,219,1,0,0,0,219,220,1,0,0,0,220,222,5,12,0,0,221,223,
  	5,2,0,0,222,221,1,0,0,0,223,224,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,
  	0,225,226,1,0,0,0,226,228,5,12,0,0,227,229,5,2,0,0,228,227,1,0,0,0,229,
  	230,1,0,0,0,230,228,1,0,0,0,230,231,1,0,0,0,231,233,1,0,0,0,232,234,5,
  	8,0,0,233,232,1,0,0,0,234,235,1,0,0,0,235,233,1,0,0,0,235,236,1,0,0,0,
  	236,238,1,0,0,0,237,239,5,2,0,0,238,237,1,0,0,0,239,240,1,0,0,0,240,238,
  	1,0,0,0,240,241,1,0,0,0,241,245,1,0,0,0,242,244,5,11,0,0,243,242,1,0,
  	0,0,244,247,1,0,0,0,245,243,1,0,0,0,245,246,1,0,0,0,246,251,1,0,0,0,247,
  	245,1,0,0,0,248,250,5,2,0,0,249,248,1,0,0,0,250,253,1,0,0,0,251,249,1,
  	0,0,0,251,252,1,0,0,0,252,254,1,0,0,0,253,251,1,0,0,0,254,307,5,3,0,0,
  	255,257,5,6,0,0,256,258,5,2,0,0,257,256,1,0,0,0,258,259,1,0,0,0,259,257,
  	1,0,0,0,259,260,1,0,0,0,260,261,1,0,0,0,261,263,5,12,0,0,262,264,5,2,
  	0,0,263,262,1,0,0,0,264,265,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,
  	267,1,0,0,0,267,269,5,12,0,0,268,270,5,2,0,0,269,268,1,0,0,0,270,271,
  	1,0,0,0,271,269,1,0,0,0,271,272,1,0,0,0,272,276,1,0,0,0,273,275,5,8,0,
  	0,274,273,1,0,0,0,275,278,1,0,0,0,276,274,1,0,0,0,276,277,1,0,0,0,277,
  	282,1,0,0,0,278,276,1,0,0,0,279,281,5,2,0,0,280,279,1,0,0,0,281,284,1,
  	0,0,0,282,280,1,0,0,0,282,283,1,0,0,0,283,285,1,0,0,0,284,282,1,0,0,0,
  	285,307,5,3,0,0,286,288,5,6,0,0,287,289,5,2,0,0,288,287,1,0,0,0,289,290,
  	1,0,0,0,290,288,1,0,0,0,290,291,1,0,0,0,291,292,1,0,0,0,292,294,5,12,
  	0,0,293,295,5,2,0,0,294,293,1,0,0,0,295,296,1,0,0,0,296,294,1,0,0,0,296,
  	297,1,0,0,0,297,298,1,0,0,0,298,302,5,12,0,0,299,301,5,2,0,0,300,299,
  	1,0,0,0,301,304,1,0,0,0,302,300,1,0,0,0,302,303,1,0,0,0,303,305,1,0,0,
  	0,304,302,1,0,0,0,305,307,5,3,0,0,306,214,1,0,0,0,306,255,1,0,0,0,306,
  	286,1,0,0,0,307,7,1,0,0,0,51,11,17,23,30,36,42,47,52,57,63,71,77,83,88,
  	94,102,108,114,118,124,130,136,141,146,151,157,165,171,177,182,188,196,
  	202,208,212,218,224,230,235,240,245,251,259,265,271,276,282,290,296,302,
  	306
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tparserParserStaticData = staticData.release();
}

}

TParser::TParser(TokenStream *input) : TParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

TParser::TParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  TParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *tparserParserStaticData->atn, tparserParserStaticData->decisionToDFA, tparserParserStaticData->sharedContextCache, options);
}

TParser::~TParser() {
  delete _interpreter;
}

const atn::ATN& TParser::getATN() const {
  return *tparserParserStaticData->atn;
}

std::string TParser::getGrammarFileName() const {
  return "TParser.g4";
}

const std::vector<std::string>& TParser::getRuleNames() const {
  return tparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& TParser::getVocabulary() const {
  return tparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView TParser::getSerializedATN() const {
  return tparserParserStaticData->serializedATN;
}


//----------------- MainContext ------------------------------------------------------------------

TParser::MainContext::MainContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<TParser::ResistorContext *> TParser::MainContext::resistor() {
  return getRuleContexts<TParser::ResistorContext>();
}

TParser::ResistorContext* TParser::MainContext::resistor(size_t i) {
  return getRuleContext<TParser::ResistorContext>(i);
}

std::vector<TParser::CapacitorContext *> TParser::MainContext::capacitor() {
  return getRuleContexts<TParser::CapacitorContext>();
}

TParser::CapacitorContext* TParser::MainContext::capacitor(size_t i) {
  return getRuleContext<TParser::CapacitorContext>(i);
}

std::vector<TParser::InductorContext *> TParser::MainContext::inductor() {
  return getRuleContexts<TParser::InductorContext>();
}

TParser::InductorContext* TParser::MainContext::inductor(size_t i) {
  return getRuleContext<TParser::InductorContext>(i);
}


size_t TParser::MainContext::getRuleIndex() const {
  return TParser::RuleMain;
}

void TParser::MainContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMain(this);
}

void TParser::MainContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMain(this);
}


std::any TParser::MainContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitMain(this);
  else
    return visitor->visitChildren(this);
}

TParser::MainContext* TParser::main() {
  MainContext *_localctx = _tracker.createInstance<MainContext>(_ctx, getState());
  enterRule(_localctx, 0, TParser::RuleMain);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(11);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::RESISTOR_NAME) {
      setState(8);
      resistor();
      setState(13);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::CAPACITOR_NAME) {
      setState(14);
      capacitor();
      setState(19);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(23);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::INDUCTOR_NAME) {
      setState(20);
      inductor();
      setState(25);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResistorContext ------------------------------------------------------------------

TParser::ResistorContext::ResistorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::ResistorContext::RESISTOR_NAME() {
  return getToken(TParser::RESISTOR_NAME, 0);
}

std::vector<tree::TerminalNode *> TParser::ResistorContext::TEXT() {
  return getTokens(TParser::TEXT);
}

tree::TerminalNode* TParser::ResistorContext::TEXT(size_t i) {
  return getToken(TParser::TEXT, i);
}

tree::TerminalNode* TParser::ResistorContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TParser::ResistorContext::WHITESPACE() {
  return getTokens(TParser::WHITESPACE);
}

tree::TerminalNode* TParser::ResistorContext::WHITESPACE(size_t i) {
  return getToken(TParser::WHITESPACE, i);
}

std::vector<tree::TerminalNode *> TParser::ResistorContext::NUMERIC_VALUE() {
  return getTokens(TParser::NUMERIC_VALUE);
}

tree::TerminalNode* TParser::ResistorContext::NUMERIC_VALUE(size_t i) {
  return getToken(TParser::NUMERIC_VALUE, i);
}

std::vector<tree::TerminalNode *> TParser::ResistorContext::PARAMS() {
  return getTokens(TParser::PARAMS);
}

tree::TerminalNode* TParser::ResistorContext::PARAMS(size_t i) {
  return getToken(TParser::PARAMS, i);
}


size_t TParser::ResistorContext::getRuleIndex() const {
  return TParser::RuleResistor;
}

void TParser::ResistorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResistor(this);
}

void TParser::ResistorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResistor(this);
}


std::any TParser::ResistorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitResistor(this);
  else
    return visitor->visitChildren(this);
}

TParser::ResistorContext* TParser::resistor() {
  ResistorContext *_localctx = _tracker.createInstance<ResistorContext>(_ctx, getState());
  enterRule(_localctx, 2, TParser::RuleResistor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(118);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(26);
      match(TParser::RESISTOR_NAME);
      setState(28); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(27);
        match(TParser::WHITESPACE);
        setState(30); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(32);
      match(TParser::TEXT);
      setState(34); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(33);
        match(TParser::WHITESPACE);
        setState(36); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(38);
      match(TParser::TEXT);
      setState(40); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(39);
        match(TParser::WHITESPACE);
        setState(42); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(45); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(44);
        match(TParser::NUMERIC_VALUE);
        setState(47); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::NUMERIC_VALUE);
      setState(50); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(49);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(52); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(54);
        match(TParser::PARAMS);
        setState(59);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(63);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(60);
        match(TParser::WHITESPACE);
        setState(65);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(66);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      match(TParser::RESISTOR_NAME);
      setState(69); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(68);
        match(TParser::WHITESPACE);
        setState(71); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(73);
      match(TParser::TEXT);
      setState(75); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(74);
        match(TParser::WHITESPACE);
        setState(77); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(79);
      match(TParser::TEXT);
      setState(81); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(80);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(83); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(88);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::NUMERIC_VALUE) {
        setState(85);
        match(TParser::NUMERIC_VALUE);
        setState(90);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(91);
        match(TParser::WHITESPACE);
        setState(96);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(97);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(98);
      match(TParser::RESISTOR_NAME);
      setState(100); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(99);
        match(TParser::WHITESPACE);
        setState(102); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(104);
      match(TParser::TEXT);
      setState(106); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(105);
        match(TParser::WHITESPACE);
        setState(108); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(110);
      match(TParser::TEXT);
      setState(114);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(111);
        match(TParser::WHITESPACE);
        setState(116);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(117);
      match(TParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CapacitorContext ------------------------------------------------------------------

TParser::CapacitorContext::CapacitorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::CapacitorContext::CAPACITOR_NAME() {
  return getToken(TParser::CAPACITOR_NAME, 0);
}

std::vector<tree::TerminalNode *> TParser::CapacitorContext::TEXT() {
  return getTokens(TParser::TEXT);
}

tree::TerminalNode* TParser::CapacitorContext::TEXT(size_t i) {
  return getToken(TParser::TEXT, i);
}

tree::TerminalNode* TParser::CapacitorContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TParser::CapacitorContext::WHITESPACE() {
  return getTokens(TParser::WHITESPACE);
}

tree::TerminalNode* TParser::CapacitorContext::WHITESPACE(size_t i) {
  return getToken(TParser::WHITESPACE, i);
}

std::vector<tree::TerminalNode *> TParser::CapacitorContext::NUMERIC_VALUE() {
  return getTokens(TParser::NUMERIC_VALUE);
}

tree::TerminalNode* TParser::CapacitorContext::NUMERIC_VALUE(size_t i) {
  return getToken(TParser::NUMERIC_VALUE, i);
}

std::vector<tree::TerminalNode *> TParser::CapacitorContext::PARAMS() {
  return getTokens(TParser::PARAMS);
}

tree::TerminalNode* TParser::CapacitorContext::PARAMS(size_t i) {
  return getToken(TParser::PARAMS, i);
}


size_t TParser::CapacitorContext::getRuleIndex() const {
  return TParser::RuleCapacitor;
}

void TParser::CapacitorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCapacitor(this);
}

void TParser::CapacitorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCapacitor(this);
}


std::any TParser::CapacitorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitCapacitor(this);
  else
    return visitor->visitChildren(this);
}

TParser::CapacitorContext* TParser::capacitor() {
  CapacitorContext *_localctx = _tracker.createInstance<CapacitorContext>(_ctx, getState());
  enterRule(_localctx, 4, TParser::RuleCapacitor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(212);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(120);
      match(TParser::CAPACITOR_NAME);
      setState(122); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(121);
        match(TParser::WHITESPACE);
        setState(124); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(126);
      match(TParser::TEXT);
      setState(128); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(127);
        match(TParser::WHITESPACE);
        setState(130); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(132);
      match(TParser::TEXT);
      setState(134); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(133);
        match(TParser::WHITESPACE);
        setState(136); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(139); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(138);
        match(TParser::NUMERIC_VALUE);
        setState(141); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::NUMERIC_VALUE);
      setState(144); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(143);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(146); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(151);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(148);
        match(TParser::PARAMS);
        setState(153);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(157);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(154);
        match(TParser::WHITESPACE);
        setState(159);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(160);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(161);
      match(TParser::CAPACITOR_NAME);
      setState(163); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(162);
        match(TParser::WHITESPACE);
        setState(165); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(167);
      match(TParser::TEXT);
      setState(169); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(168);
        match(TParser::WHITESPACE);
        setState(171); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(173);
      match(TParser::TEXT);
      setState(175); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(174);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(177); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(182);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::NUMERIC_VALUE) {
        setState(179);
        match(TParser::NUMERIC_VALUE);
        setState(184);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(188);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(185);
        match(TParser::WHITESPACE);
        setState(190);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(191);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(192);
      match(TParser::CAPACITOR_NAME);
      setState(194); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(193);
        match(TParser::WHITESPACE);
        setState(196); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(198);
      match(TParser::TEXT);
      setState(200); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(199);
        match(TParser::WHITESPACE);
        setState(202); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(204);
      match(TParser::TEXT);
      setState(208);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(205);
        match(TParser::WHITESPACE);
        setState(210);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(211);
      match(TParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InductorContext ------------------------------------------------------------------

TParser::InductorContext::InductorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::InductorContext::INDUCTOR_NAME() {
  return getToken(TParser::INDUCTOR_NAME, 0);
}

std::vector<tree::TerminalNode *> TParser::InductorContext::TEXT() {
  return getTokens(TParser::TEXT);
}

tree::TerminalNode* TParser::InductorContext::TEXT(size_t i) {
  return getToken(TParser::TEXT, i);
}

tree::TerminalNode* TParser::InductorContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TParser::InductorContext::WHITESPACE() {
  return getTokens(TParser::WHITESPACE);
}

tree::TerminalNode* TParser::InductorContext::WHITESPACE(size_t i) {
  return getToken(TParser::WHITESPACE, i);
}

std::vector<tree::TerminalNode *> TParser::InductorContext::NUMERIC_VALUE() {
  return getTokens(TParser::NUMERIC_VALUE);
}

tree::TerminalNode* TParser::InductorContext::NUMERIC_VALUE(size_t i) {
  return getToken(TParser::NUMERIC_VALUE, i);
}

std::vector<tree::TerminalNode *> TParser::InductorContext::PARAMS() {
  return getTokens(TParser::PARAMS);
}

tree::TerminalNode* TParser::InductorContext::PARAMS(size_t i) {
  return getToken(TParser::PARAMS, i);
}


size_t TParser::InductorContext::getRuleIndex() const {
  return TParser::RuleInductor;
}

void TParser::InductorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInductor(this);
}

void TParser::InductorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<TParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInductor(this);
}


std::any TParser::InductorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitInductor(this);
  else
    return visitor->visitChildren(this);
}

TParser::InductorContext* TParser::inductor() {
  InductorContext *_localctx = _tracker.createInstance<InductorContext>(_ctx, getState());
  enterRule(_localctx, 6, TParser::RuleInductor);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(306);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 50, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(214);
      match(TParser::INDUCTOR_NAME);
      setState(216); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(215);
        match(TParser::WHITESPACE);
        setState(218); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(220);
      match(TParser::TEXT);
      setState(222); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(221);
        match(TParser::WHITESPACE);
        setState(224); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(226);
      match(TParser::TEXT);
      setState(228); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(227);
        match(TParser::WHITESPACE);
        setState(230); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(233); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(232);
        match(TParser::NUMERIC_VALUE);
        setState(235); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::NUMERIC_VALUE);
      setState(238); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(237);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(240); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(245);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(242);
        match(TParser::PARAMS);
        setState(247);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(251);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(248);
        match(TParser::WHITESPACE);
        setState(253);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(254);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(255);
      match(TParser::INDUCTOR_NAME);
      setState(257); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(256);
        match(TParser::WHITESPACE);
        setState(259); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(261);
      match(TParser::TEXT);
      setState(263); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(262);
        match(TParser::WHITESPACE);
        setState(265); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(267);
      match(TParser::TEXT);
      setState(269); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(268);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(271); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::NUMERIC_VALUE) {
        setState(273);
        match(TParser::NUMERIC_VALUE);
        setState(278);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(282);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(279);
        match(TParser::WHITESPACE);
        setState(284);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(285);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(286);
      match(TParser::INDUCTOR_NAME);
      setState(288); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(287);
        match(TParser::WHITESPACE);
        setState(290); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(292);
      match(TParser::TEXT);
      setState(294); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(293);
        match(TParser::WHITESPACE);
        setState(296); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(298);
      match(TParser::TEXT);
      setState(302);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(299);
        match(TParser::WHITESPACE);
        setState(304);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(305);
      match(TParser::NEWLINE);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void TParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  tparserParserInitialize();
#else
  ::antlr4::internal::call_once(tparserParserOnceFlag, tparserParserInitialize);
#endif
}

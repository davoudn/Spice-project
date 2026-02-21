
// Generated from TParser.g4 by ANTLR 4.13.2


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
std::unique_ptr<TParserStaticData> tparserParserStaticData = nullptr;

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
      "circuit", "element", "voltagesource", "currentsource", "resistor", 
      "capacitor", "inductor"
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
  	4,1,15,258,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,
  	0,5,0,16,8,0,10,0,12,0,19,9,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,3,1,29,
  	8,1,1,2,1,2,4,2,33,8,2,11,2,12,2,34,1,2,1,2,4,2,39,8,2,11,2,12,2,40,1,
  	2,1,2,4,2,45,8,2,11,2,12,2,46,1,2,1,2,4,2,51,8,2,11,2,12,2,52,1,2,4,2,
  	56,8,2,11,2,12,2,57,1,2,5,2,61,8,2,10,2,12,2,64,9,2,1,2,5,2,67,8,2,10,
  	2,12,2,70,9,2,1,2,5,2,73,8,2,10,2,12,2,76,9,2,1,2,1,2,1,3,1,3,4,3,82,
  	8,3,11,3,12,3,83,1,3,1,3,4,3,88,8,3,11,3,12,3,89,1,3,1,3,4,3,94,8,3,11,
  	3,12,3,95,1,3,1,3,4,3,100,8,3,11,3,12,3,101,1,3,4,3,105,8,3,11,3,12,3,
  	106,1,3,5,3,110,8,3,10,3,12,3,113,9,3,1,3,5,3,116,8,3,10,3,12,3,119,9,
  	3,1,3,5,3,122,8,3,10,3,12,3,125,9,3,1,3,1,3,1,4,1,4,4,4,131,8,4,11,4,
  	12,4,132,1,4,1,4,4,4,137,8,4,11,4,12,4,138,1,4,1,4,4,4,143,8,4,11,4,12,
  	4,144,1,4,4,4,148,8,4,11,4,12,4,149,1,4,5,4,153,8,4,10,4,12,4,156,9,4,
  	1,4,5,4,159,8,4,10,4,12,4,162,9,4,1,4,5,4,165,8,4,10,4,12,4,168,9,4,1,
  	4,1,4,1,5,1,5,4,5,174,8,5,11,5,12,5,175,1,5,1,5,4,5,180,8,5,11,5,12,5,
  	181,1,5,1,5,4,5,186,8,5,11,5,12,5,187,1,5,4,5,191,8,5,11,5,12,5,192,1,
  	5,5,5,196,8,5,10,5,12,5,199,9,5,1,5,5,5,202,8,5,10,5,12,5,205,9,5,1,5,
  	5,5,208,8,5,10,5,12,5,211,9,5,1,5,1,5,1,6,1,6,4,6,217,8,6,11,6,12,6,218,
  	1,6,1,6,4,6,223,8,6,11,6,12,6,224,1,6,1,6,4,6,229,8,6,11,6,12,6,230,1,
  	6,4,6,234,8,6,11,6,12,6,235,1,6,5,6,239,8,6,10,6,12,6,242,9,6,1,6,5,6,
  	245,8,6,10,6,12,6,248,9,6,1,6,5,6,251,8,6,10,6,12,6,254,9,6,1,6,1,6,1,
  	6,0,0,7,0,2,4,6,8,10,12,0,0,292,0,17,1,0,0,0,2,28,1,0,0,0,4,30,1,0,0,
  	0,6,79,1,0,0,0,8,128,1,0,0,0,10,171,1,0,0,0,12,214,1,0,0,0,14,16,3,2,
  	1,0,15,14,1,0,0,0,16,19,1,0,0,0,17,15,1,0,0,0,17,18,1,0,0,0,18,20,1,0,
  	0,0,19,17,1,0,0,0,20,21,5,13,0,0,21,22,5,0,0,1,22,1,1,0,0,0,23,29,3,10,
  	5,0,24,29,3,8,4,0,25,29,3,12,6,0,26,29,3,4,2,0,27,29,3,6,3,0,28,23,1,
  	0,0,0,28,24,1,0,0,0,28,25,1,0,0,0,28,26,1,0,0,0,28,27,1,0,0,0,29,3,1,
  	0,0,0,30,32,5,7,0,0,31,33,5,2,0,0,32,31,1,0,0,0,33,34,1,0,0,0,34,32,1,
  	0,0,0,34,35,1,0,0,0,35,36,1,0,0,0,36,38,5,15,0,0,37,39,5,2,0,0,38,37,
  	1,0,0,0,39,40,1,0,0,0,40,38,1,0,0,0,40,41,1,0,0,0,41,42,1,0,0,0,42,44,
  	5,15,0,0,43,45,5,2,0,0,44,43,1,0,0,0,45,46,1,0,0,0,46,44,1,0,0,0,46,47,
  	1,0,0,0,47,48,1,0,0,0,48,50,5,9,0,0,49,51,5,2,0,0,50,49,1,0,0,0,51,52,
  	1,0,0,0,52,50,1,0,0,0,52,53,1,0,0,0,53,55,1,0,0,0,54,56,5,10,0,0,55,54,
  	1,0,0,0,56,57,1,0,0,0,57,55,1,0,0,0,57,58,1,0,0,0,58,62,1,0,0,0,59,61,
  	5,2,0,0,60,59,1,0,0,0,61,64,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,68,
  	1,0,0,0,64,62,1,0,0,0,65,67,5,14,0,0,66,65,1,0,0,0,67,70,1,0,0,0,68,66,
  	1,0,0,0,68,69,1,0,0,0,69,74,1,0,0,0,70,68,1,0,0,0,71,73,5,2,0,0,72,71,
  	1,0,0,0,73,76,1,0,0,0,74,72,1,0,0,0,74,75,1,0,0,0,75,77,1,0,0,0,76,74,
  	1,0,0,0,77,78,5,3,0,0,78,5,1,0,0,0,79,81,5,8,0,0,80,82,5,2,0,0,81,80,
  	1,0,0,0,82,83,1,0,0,0,83,81,1,0,0,0,83,84,1,0,0,0,84,85,1,0,0,0,85,87,
  	5,15,0,0,86,88,5,2,0,0,87,86,1,0,0,0,88,89,1,0,0,0,89,87,1,0,0,0,89,90,
  	1,0,0,0,90,91,1,0,0,0,91,93,5,15,0,0,92,94,5,2,0,0,93,92,1,0,0,0,94,95,
  	1,0,0,0,95,93,1,0,0,0,95,96,1,0,0,0,96,97,1,0,0,0,97,99,5,9,0,0,98,100,
  	5,2,0,0,99,98,1,0,0,0,100,101,1,0,0,0,101,99,1,0,0,0,101,102,1,0,0,0,
  	102,104,1,0,0,0,103,105,5,10,0,0,104,103,1,0,0,0,105,106,1,0,0,0,106,
  	104,1,0,0,0,106,107,1,0,0,0,107,111,1,0,0,0,108,110,5,2,0,0,109,108,1,
  	0,0,0,110,113,1,0,0,0,111,109,1,0,0,0,111,112,1,0,0,0,112,117,1,0,0,0,
  	113,111,1,0,0,0,114,116,5,14,0,0,115,114,1,0,0,0,116,119,1,0,0,0,117,
  	115,1,0,0,0,117,118,1,0,0,0,118,123,1,0,0,0,119,117,1,0,0,0,120,122,5,
  	2,0,0,121,120,1,0,0,0,122,125,1,0,0,0,123,121,1,0,0,0,123,124,1,0,0,0,
  	124,126,1,0,0,0,125,123,1,0,0,0,126,127,5,3,0,0,127,7,1,0,0,0,128,130,
  	5,4,0,0,129,131,5,2,0,0,130,129,1,0,0,0,131,132,1,0,0,0,132,130,1,0,0,
  	0,132,133,1,0,0,0,133,134,1,0,0,0,134,136,5,15,0,0,135,137,5,2,0,0,136,
  	135,1,0,0,0,137,138,1,0,0,0,138,136,1,0,0,0,138,139,1,0,0,0,139,140,1,
  	0,0,0,140,142,5,15,0,0,141,143,5,2,0,0,142,141,1,0,0,0,143,144,1,0,0,
  	0,144,142,1,0,0,0,144,145,1,0,0,0,145,147,1,0,0,0,146,148,5,10,0,0,147,
  	146,1,0,0,0,148,149,1,0,0,0,149,147,1,0,0,0,149,150,1,0,0,0,150,154,1,
  	0,0,0,151,153,5,2,0,0,152,151,1,0,0,0,153,156,1,0,0,0,154,152,1,0,0,0,
  	154,155,1,0,0,0,155,160,1,0,0,0,156,154,1,0,0,0,157,159,5,14,0,0,158,
  	157,1,0,0,0,159,162,1,0,0,0,160,158,1,0,0,0,160,161,1,0,0,0,161,166,1,
  	0,0,0,162,160,1,0,0,0,163,165,5,2,0,0,164,163,1,0,0,0,165,168,1,0,0,0,
  	166,164,1,0,0,0,166,167,1,0,0,0,167,169,1,0,0,0,168,166,1,0,0,0,169,170,
  	5,3,0,0,170,9,1,0,0,0,171,173,5,5,0,0,172,174,5,2,0,0,173,172,1,0,0,0,
  	174,175,1,0,0,0,175,173,1,0,0,0,175,176,1,0,0,0,176,177,1,0,0,0,177,179,
  	5,15,0,0,178,180,5,2,0,0,179,178,1,0,0,0,180,181,1,0,0,0,181,179,1,0,
  	0,0,181,182,1,0,0,0,182,183,1,0,0,0,183,185,5,15,0,0,184,186,5,2,0,0,
  	185,184,1,0,0,0,186,187,1,0,0,0,187,185,1,0,0,0,187,188,1,0,0,0,188,190,
  	1,0,0,0,189,191,5,10,0,0,190,189,1,0,0,0,191,192,1,0,0,0,192,190,1,0,
  	0,0,192,193,1,0,0,0,193,197,1,0,0,0,194,196,5,2,0,0,195,194,1,0,0,0,196,
  	199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,203,1,0,0,0,199,197,1,
  	0,0,0,200,202,5,14,0,0,201,200,1,0,0,0,202,205,1,0,0,0,203,201,1,0,0,
  	0,203,204,1,0,0,0,204,209,1,0,0,0,205,203,1,0,0,0,206,208,5,2,0,0,207,
  	206,1,0,0,0,208,211,1,0,0,0,209,207,1,0,0,0,209,210,1,0,0,0,210,212,1,
  	0,0,0,211,209,1,0,0,0,212,213,5,3,0,0,213,11,1,0,0,0,214,216,5,6,0,0,
  	215,217,5,2,0,0,216,215,1,0,0,0,217,218,1,0,0,0,218,216,1,0,0,0,218,219,
  	1,0,0,0,219,220,1,0,0,0,220,222,5,15,0,0,221,223,5,2,0,0,222,221,1,0,
  	0,0,223,224,1,0,0,0,224,222,1,0,0,0,224,225,1,0,0,0,225,226,1,0,0,0,226,
  	228,5,15,0,0,227,229,5,2,0,0,228,227,1,0,0,0,229,230,1,0,0,0,230,228,
  	1,0,0,0,230,231,1,0,0,0,231,233,1,0,0,0,232,234,5,10,0,0,233,232,1,0,
  	0,0,234,235,1,0,0,0,235,233,1,0,0,0,235,236,1,0,0,0,236,240,1,0,0,0,237,
  	239,5,2,0,0,238,237,1,0,0,0,239,242,1,0,0,0,240,238,1,0,0,0,240,241,1,
  	0,0,0,241,246,1,0,0,0,242,240,1,0,0,0,243,245,5,14,0,0,244,243,1,0,0,
  	0,245,248,1,0,0,0,246,244,1,0,0,0,246,247,1,0,0,0,247,252,1,0,0,0,248,
  	246,1,0,0,0,249,251,5,2,0,0,250,249,1,0,0,0,251,254,1,0,0,0,252,250,1,
  	0,0,0,252,253,1,0,0,0,253,255,1,0,0,0,254,252,1,0,0,0,255,256,5,3,0,0,
  	256,13,1,0,0,0,39,17,28,34,40,46,52,57,62,68,74,83,89,95,101,106,111,
  	117,123,132,138,144,149,154,160,166,175,181,187,192,197,203,209,218,224,
  	230,235,240,246,252
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  tparserParserStaticData = std::move(staticData);
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


//----------------- CircuitContext ------------------------------------------------------------------

TParser::CircuitContext::CircuitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::CircuitContext::END() {
  return getToken(TParser::END, 0);
}

tree::TerminalNode* TParser::CircuitContext::EOF() {
  return getToken(TParser::EOF, 0);
}

std::vector<TParser::ElementContext *> TParser::CircuitContext::element() {
  return getRuleContexts<TParser::ElementContext>();
}

TParser::ElementContext* TParser::CircuitContext::element(size_t i) {
  return getRuleContext<TParser::ElementContext>(i);
}


size_t TParser::CircuitContext::getRuleIndex() const {
  return TParser::RuleCircuit;
}


std::any TParser::CircuitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitCircuit(this);
  else
    return visitor->visitChildren(this);
}

TParser::CircuitContext* TParser::circuit() {
  CircuitContext *_localctx = _tracker.createInstance<CircuitContext>(_ctx, getState());
  enterRule(_localctx, 0, TParser::RuleCircuit);
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
    setState(17);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 496) != 0)) {
      setState(14);
      element();
      setState(19);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(20);
    match(TParser::END);
    setState(21);
    match(TParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementContext ------------------------------------------------------------------

TParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

TParser::CapacitorContext* TParser::ElementContext::capacitor() {
  return getRuleContext<TParser::CapacitorContext>(0);
}

TParser::ResistorContext* TParser::ElementContext::resistor() {
  return getRuleContext<TParser::ResistorContext>(0);
}

TParser::InductorContext* TParser::ElementContext::inductor() {
  return getRuleContext<TParser::InductorContext>(0);
}

TParser::VoltagesourceContext* TParser::ElementContext::voltagesource() {
  return getRuleContext<TParser::VoltagesourceContext>(0);
}

TParser::CurrentsourceContext* TParser::ElementContext::currentsource() {
  return getRuleContext<TParser::CurrentsourceContext>(0);
}


size_t TParser::ElementContext::getRuleIndex() const {
  return TParser::RuleElement;
}


std::any TParser::ElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitElement(this);
  else
    return visitor->visitChildren(this);
}

TParser::ElementContext* TParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 2, TParser::RuleElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(28);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case TParser::CAPACITOR_NAME: {
        enterOuterAlt(_localctx, 1);
        setState(23);
        capacitor();
        break;
      }

      case TParser::RESISTOR_NAME: {
        enterOuterAlt(_localctx, 2);
        setState(24);
        resistor();
        break;
      }

      case TParser::INDUCTOR_NAME: {
        enterOuterAlt(_localctx, 3);
        setState(25);
        inductor();
        break;
      }

      case TParser::VOLTAGE_SOURCE_NAME: {
        enterOuterAlt(_localctx, 4);
        setState(26);
        voltagesource();
        break;
      }

      case TParser::CURRENT_SOURCE_NAME: {
        enterOuterAlt(_localctx, 5);
        setState(27);
        currentsource();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VoltagesourceContext ------------------------------------------------------------------

TParser::VoltagesourceContext::VoltagesourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::VoltagesourceContext::VOLTAGE_SOURCE_NAME() {
  return getToken(TParser::VOLTAGE_SOURCE_NAME, 0);
}

std::vector<tree::TerminalNode *> TParser::VoltagesourceContext::TEXT() {
  return getTokens(TParser::TEXT);
}

tree::TerminalNode* TParser::VoltagesourceContext::TEXT(size_t i) {
  return getToken(TParser::TEXT, i);
}

tree::TerminalNode* TParser::VoltagesourceContext::DC() {
  return getToken(TParser::DC, 0);
}

tree::TerminalNode* TParser::VoltagesourceContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TParser::VoltagesourceContext::WHITESPACE() {
  return getTokens(TParser::WHITESPACE);
}

tree::TerminalNode* TParser::VoltagesourceContext::WHITESPACE(size_t i) {
  return getToken(TParser::WHITESPACE, i);
}

std::vector<tree::TerminalNode *> TParser::VoltagesourceContext::COMPONENT_VALUE() {
  return getTokens(TParser::COMPONENT_VALUE);
}

tree::TerminalNode* TParser::VoltagesourceContext::COMPONENT_VALUE(size_t i) {
  return getToken(TParser::COMPONENT_VALUE, i);
}

std::vector<tree::TerminalNode *> TParser::VoltagesourceContext::PARAMS() {
  return getTokens(TParser::PARAMS);
}

tree::TerminalNode* TParser::VoltagesourceContext::PARAMS(size_t i) {
  return getToken(TParser::PARAMS, i);
}


size_t TParser::VoltagesourceContext::getRuleIndex() const {
  return TParser::RuleVoltagesource;
}


std::any TParser::VoltagesourceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitVoltagesource(this);
  else
    return visitor->visitChildren(this);
}

TParser::VoltagesourceContext* TParser::voltagesource() {
  VoltagesourceContext *_localctx = _tracker.createInstance<VoltagesourceContext>(_ctx, getState());
  enterRule(_localctx, 4, TParser::RuleVoltagesource);
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
    enterOuterAlt(_localctx, 1);
    setState(30);
    match(TParser::VOLTAGE_SOURCE_NAME);
    setState(32); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(31);
      match(TParser::WHITESPACE);
      setState(34); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(36);
    match(TParser::TEXT);
    setState(38); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(37);
      match(TParser::WHITESPACE);
      setState(40); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(42);
    match(TParser::TEXT);
    setState(44); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(43);
      match(TParser::WHITESPACE);
      setState(46); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(48);
    match(TParser::DC);
    setState(50); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(49);
      match(TParser::WHITESPACE);
      setState(52); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(55); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(54);
      match(TParser::COMPONENT_VALUE);
      setState(57); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::COMPONENT_VALUE);
    setState(62);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(59);
        match(TParser::WHITESPACE); 
      }
      setState(64);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
    }
    setState(68);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::PARAMS) {
      setState(65);
      match(TParser::PARAMS);
      setState(70);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(74);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::WHITESPACE) {
      setState(71);
      match(TParser::WHITESPACE);
      setState(76);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(77);
    match(TParser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CurrentsourceContext ------------------------------------------------------------------

TParser::CurrentsourceContext::CurrentsourceContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::CurrentsourceContext::CURRENT_SOURCE_NAME() {
  return getToken(TParser::CURRENT_SOURCE_NAME, 0);
}

std::vector<tree::TerminalNode *> TParser::CurrentsourceContext::TEXT() {
  return getTokens(TParser::TEXT);
}

tree::TerminalNode* TParser::CurrentsourceContext::TEXT(size_t i) {
  return getToken(TParser::TEXT, i);
}

tree::TerminalNode* TParser::CurrentsourceContext::DC() {
  return getToken(TParser::DC, 0);
}

tree::TerminalNode* TParser::CurrentsourceContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TParser::CurrentsourceContext::WHITESPACE() {
  return getTokens(TParser::WHITESPACE);
}

tree::TerminalNode* TParser::CurrentsourceContext::WHITESPACE(size_t i) {
  return getToken(TParser::WHITESPACE, i);
}

std::vector<tree::TerminalNode *> TParser::CurrentsourceContext::COMPONENT_VALUE() {
  return getTokens(TParser::COMPONENT_VALUE);
}

tree::TerminalNode* TParser::CurrentsourceContext::COMPONENT_VALUE(size_t i) {
  return getToken(TParser::COMPONENT_VALUE, i);
}

std::vector<tree::TerminalNode *> TParser::CurrentsourceContext::PARAMS() {
  return getTokens(TParser::PARAMS);
}

tree::TerminalNode* TParser::CurrentsourceContext::PARAMS(size_t i) {
  return getToken(TParser::PARAMS, i);
}


size_t TParser::CurrentsourceContext::getRuleIndex() const {
  return TParser::RuleCurrentsource;
}


std::any TParser::CurrentsourceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitCurrentsource(this);
  else
    return visitor->visitChildren(this);
}

TParser::CurrentsourceContext* TParser::currentsource() {
  CurrentsourceContext *_localctx = _tracker.createInstance<CurrentsourceContext>(_ctx, getState());
  enterRule(_localctx, 6, TParser::RuleCurrentsource);
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
    enterOuterAlt(_localctx, 1);
    setState(79);
    match(TParser::CURRENT_SOURCE_NAME);
    setState(81); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(80);
      match(TParser::WHITESPACE);
      setState(83); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(85);
    match(TParser::TEXT);
    setState(87); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(86);
      match(TParser::WHITESPACE);
      setState(89); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(91);
    match(TParser::TEXT);
    setState(93); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(92);
      match(TParser::WHITESPACE);
      setState(95); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(97);
    match(TParser::DC);
    setState(99); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(98);
      match(TParser::WHITESPACE);
      setState(101); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(104); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(103);
      match(TParser::COMPONENT_VALUE);
      setState(106); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::COMPONENT_VALUE);
    setState(111);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(108);
        match(TParser::WHITESPACE); 
      }
      setState(113);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
    setState(117);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::PARAMS) {
      setState(114);
      match(TParser::PARAMS);
      setState(119);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(123);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::WHITESPACE) {
      setState(120);
      match(TParser::WHITESPACE);
      setState(125);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(126);
    match(TParser::NEWLINE);
   
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

std::vector<tree::TerminalNode *> TParser::ResistorContext::COMPONENT_VALUE() {
  return getTokens(TParser::COMPONENT_VALUE);
}

tree::TerminalNode* TParser::ResistorContext::COMPONENT_VALUE(size_t i) {
  return getToken(TParser::COMPONENT_VALUE, i);
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


std::any TParser::ResistorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitResistor(this);
  else
    return visitor->visitChildren(this);
}

TParser::ResistorContext* TParser::resistor() {
  ResistorContext *_localctx = _tracker.createInstance<ResistorContext>(_ctx, getState());
  enterRule(_localctx, 8, TParser::RuleResistor);
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
    enterOuterAlt(_localctx, 1);
    setState(128);
    match(TParser::RESISTOR_NAME);
    setState(130); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(129);
      match(TParser::WHITESPACE);
      setState(132); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(134);
    match(TParser::TEXT);
    setState(136); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(135);
      match(TParser::WHITESPACE);
      setState(138); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(140);
    match(TParser::TEXT);
    setState(142); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(141);
      match(TParser::WHITESPACE);
      setState(144); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(147); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(146);
      match(TParser::COMPONENT_VALUE);
      setState(149); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::COMPONENT_VALUE);
    setState(154);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(151);
        match(TParser::WHITESPACE); 
      }
      setState(156);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(160);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::PARAMS) {
      setState(157);
      match(TParser::PARAMS);
      setState(162);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::WHITESPACE) {
      setState(163);
      match(TParser::WHITESPACE);
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(169);
    match(TParser::NEWLINE);
   
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

std::vector<tree::TerminalNode *> TParser::CapacitorContext::COMPONENT_VALUE() {
  return getTokens(TParser::COMPONENT_VALUE);
}

tree::TerminalNode* TParser::CapacitorContext::COMPONENT_VALUE(size_t i) {
  return getToken(TParser::COMPONENT_VALUE, i);
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


std::any TParser::CapacitorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitCapacitor(this);
  else
    return visitor->visitChildren(this);
}

TParser::CapacitorContext* TParser::capacitor() {
  CapacitorContext *_localctx = _tracker.createInstance<CapacitorContext>(_ctx, getState());
  enterRule(_localctx, 10, TParser::RuleCapacitor);
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
    enterOuterAlt(_localctx, 1);
    setState(171);
    match(TParser::CAPACITOR_NAME);
    setState(173); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(172);
      match(TParser::WHITESPACE);
      setState(175); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(177);
    match(TParser::TEXT);
    setState(179); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(178);
      match(TParser::WHITESPACE);
      setState(181); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(183);
    match(TParser::TEXT);
    setState(185); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(184);
      match(TParser::WHITESPACE);
      setState(187); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::WHITESPACE);
    setState(190); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(189);
      match(TParser::COMPONENT_VALUE);
      setState(192); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::COMPONENT_VALUE);
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(194);
        match(TParser::WHITESPACE); 
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
    setState(203);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::PARAMS) {
      setState(200);
      match(TParser::PARAMS);
      setState(205);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(209);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::WHITESPACE) {
      setState(206);
      match(TParser::WHITESPACE);
      setState(211);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(212);
    match(TParser::NEWLINE);
   
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

std::vector<tree::TerminalNode *> TParser::InductorContext::COMPONENT_VALUE() {
  return getTokens(TParser::COMPONENT_VALUE);
}

tree::TerminalNode* TParser::InductorContext::COMPONENT_VALUE(size_t i) {
  return getToken(TParser::COMPONENT_VALUE, i);
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


std::any TParser::InductorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitInductor(this);
  else
    return visitor->visitChildren(this);
}

TParser::InductorContext* TParser::inductor() {
  InductorContext *_localctx = _tracker.createInstance<InductorContext>(_ctx, getState());
  enterRule(_localctx, 12, TParser::RuleInductor);
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
      match(TParser::COMPONENT_VALUE);
      setState(235); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == TParser::COMPONENT_VALUE);
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(237);
        match(TParser::WHITESPACE); 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx);
    }
    setState(246);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::PARAMS) {
      setState(243);
      match(TParser::PARAMS);
      setState(248);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(252);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::WHITESPACE) {
      setState(249);
      match(TParser::WHITESPACE);
      setState(254);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(255);
    match(TParser::NEWLINE);
   
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

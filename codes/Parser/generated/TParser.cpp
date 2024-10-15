
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
      "main", "resistor", "capacitor", "inductor", "mutual_inductor", "diod"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'PULSE'", 
      "'SIN'", "'EXP'", "'PWL'", "'.model'", "'OFF'", "", "", "", "'.end'"
    },
    std::vector<std::string>{
      "", "COMMENT", "WHITESPACE", "NEWLINE", "RESISTOR_NAME", "CAPACITOR_NAME", 
      "INDUCTOR_NAME", "MUTUAL_INDUCTOR_NAME", "DIOD_NAME", "BJT_NAME", 
      "MOSFET_NAME", "JFET_NAME", "VOLTAGE_SOURCE_NAME", "CURRENT_SOURCE_NAME", 
      "PALSE", "SIN", "EXP", "PWL", "MODEL", "OFF", "COMPONENT_VALUE", "NUMERIC_VALUE", 
      "NUMBERS", "END", "PARAMS", "TEXT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,25,487,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,1,0,5,0,14,
  	8,0,10,0,12,0,17,9,0,1,0,5,0,20,8,0,10,0,12,0,23,9,0,1,0,5,0,26,8,0,10,
  	0,12,0,29,9,0,1,1,1,1,4,1,33,8,1,11,1,12,1,34,1,1,1,1,4,1,39,8,1,11,1,
  	12,1,40,1,1,1,1,4,1,45,8,1,11,1,12,1,46,1,1,4,1,50,8,1,11,1,12,1,51,1,
  	1,4,1,55,8,1,11,1,12,1,56,1,1,5,1,60,8,1,10,1,12,1,63,9,1,1,1,5,1,66,
  	8,1,10,1,12,1,69,9,1,1,1,1,1,1,1,4,1,74,8,1,11,1,12,1,75,1,1,1,1,4,1,
  	80,8,1,11,1,12,1,81,1,1,1,1,4,1,86,8,1,11,1,12,1,87,1,1,5,1,91,8,1,10,
  	1,12,1,94,9,1,1,1,5,1,97,8,1,10,1,12,1,100,9,1,1,1,1,1,1,1,4,1,105,8,
  	1,11,1,12,1,106,1,1,1,1,4,1,111,8,1,11,1,12,1,112,1,1,1,1,5,1,117,8,1,
  	10,1,12,1,120,9,1,1,1,3,1,123,8,1,1,2,1,2,4,2,127,8,2,11,2,12,2,128,1,
  	2,1,2,4,2,133,8,2,11,2,12,2,134,1,2,1,2,4,2,139,8,2,11,2,12,2,140,1,2,
  	4,2,144,8,2,11,2,12,2,145,1,2,4,2,149,8,2,11,2,12,2,150,1,2,5,2,154,8,
  	2,10,2,12,2,157,9,2,1,2,5,2,160,8,2,10,2,12,2,163,9,2,1,2,1,2,1,2,4,2,
  	168,8,2,11,2,12,2,169,1,2,1,2,4,2,174,8,2,11,2,12,2,175,1,2,1,2,4,2,180,
  	8,2,11,2,12,2,181,1,2,5,2,185,8,2,10,2,12,2,188,9,2,1,2,5,2,191,8,2,10,
  	2,12,2,194,9,2,1,2,1,2,1,2,4,2,199,8,2,11,2,12,2,200,1,2,1,2,4,2,205,
  	8,2,11,2,12,2,206,1,2,1,2,5,2,211,8,2,10,2,12,2,214,9,2,1,2,1,2,1,2,4,
  	2,219,8,2,11,2,12,2,220,1,2,1,2,4,2,225,8,2,11,2,12,2,226,1,2,1,2,4,2,
  	231,8,2,11,2,12,2,232,1,2,4,2,236,8,2,11,2,12,2,237,1,2,4,2,241,8,2,11,
  	2,12,2,242,1,2,5,2,246,8,2,10,2,12,2,249,9,2,1,2,5,2,252,8,2,10,2,12,
  	2,255,9,2,1,2,1,2,1,2,4,2,260,8,2,11,2,12,2,261,1,2,1,2,4,2,266,8,2,11,
  	2,12,2,267,1,2,1,2,4,2,272,8,2,11,2,12,2,273,1,2,5,2,277,8,2,10,2,12,
  	2,280,9,2,1,2,5,2,283,8,2,10,2,12,2,286,9,2,1,2,3,2,289,8,2,1,3,1,3,4,
  	3,293,8,3,11,3,12,3,294,1,3,1,3,4,3,299,8,3,11,3,12,3,300,1,3,1,3,4,3,
  	305,8,3,11,3,12,3,306,1,3,4,3,310,8,3,11,3,12,3,311,1,3,4,3,315,8,3,11,
  	3,12,3,316,1,3,5,3,320,8,3,10,3,12,3,323,9,3,1,3,5,3,326,8,3,10,3,12,
  	3,329,9,3,1,3,1,3,1,3,4,3,334,8,3,11,3,12,3,335,1,3,1,3,4,3,340,8,3,11,
  	3,12,3,341,1,3,1,3,4,3,346,8,3,11,3,12,3,347,1,3,5,3,351,8,3,10,3,12,
  	3,354,9,3,1,3,5,3,357,8,3,10,3,12,3,360,9,3,1,3,1,3,1,3,4,3,365,8,3,11,
  	3,12,3,366,1,3,1,3,4,3,371,8,3,11,3,12,3,372,1,3,1,3,5,3,377,8,3,10,3,
  	12,3,380,9,3,1,3,3,3,383,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,5,1,5,
  	4,5,395,8,5,11,5,12,5,396,1,5,1,5,4,5,401,8,5,11,5,12,5,402,1,5,1,5,4,
  	5,407,8,5,11,5,12,5,408,1,5,4,5,412,8,5,11,5,12,5,413,1,5,4,5,417,8,5,
  	11,5,12,5,418,1,5,5,5,422,8,5,10,5,12,5,425,9,5,1,5,5,5,428,8,5,10,5,
  	12,5,431,9,5,1,5,1,5,1,5,4,5,436,8,5,11,5,12,5,437,1,5,1,5,4,5,442,8,
  	5,11,5,12,5,443,1,5,1,5,4,5,448,8,5,11,5,12,5,449,1,5,5,5,453,8,5,10,
  	5,12,5,456,9,5,1,5,5,5,459,8,5,10,5,12,5,462,9,5,1,5,1,5,1,5,4,5,467,
  	8,5,11,5,12,5,468,1,5,1,5,4,5,473,8,5,11,5,12,5,474,1,5,1,5,5,5,479,8,
  	5,10,5,12,5,482,9,5,1,5,3,5,485,8,5,1,5,0,0,6,0,2,4,6,8,10,0,0,565,0,
  	15,1,0,0,0,2,122,1,0,0,0,4,288,1,0,0,0,6,382,1,0,0,0,8,384,1,0,0,0,10,
  	484,1,0,0,0,12,14,3,2,1,0,13,12,1,0,0,0,14,17,1,0,0,0,15,13,1,0,0,0,15,
  	16,1,0,0,0,16,21,1,0,0,0,17,15,1,0,0,0,18,20,3,4,2,0,19,18,1,0,0,0,20,
  	23,1,0,0,0,21,19,1,0,0,0,21,22,1,0,0,0,22,27,1,0,0,0,23,21,1,0,0,0,24,
  	26,3,6,3,0,25,24,1,0,0,0,26,29,1,0,0,0,27,25,1,0,0,0,27,28,1,0,0,0,28,
  	1,1,0,0,0,29,27,1,0,0,0,30,32,5,4,0,0,31,33,5,2,0,0,32,31,1,0,0,0,33,
  	34,1,0,0,0,34,32,1,0,0,0,34,35,1,0,0,0,35,36,1,0,0,0,36,38,5,25,0,0,37,
  	39,5,2,0,0,38,37,1,0,0,0,39,40,1,0,0,0,40,38,1,0,0,0,40,41,1,0,0,0,41,
  	42,1,0,0,0,42,44,5,25,0,0,43,45,5,2,0,0,44,43,1,0,0,0,45,46,1,0,0,0,46,
  	44,1,0,0,0,46,47,1,0,0,0,47,49,1,0,0,0,48,50,5,20,0,0,49,48,1,0,0,0,50,
  	51,1,0,0,0,51,49,1,0,0,0,51,52,1,0,0,0,52,54,1,0,0,0,53,55,5,2,0,0,54,
  	53,1,0,0,0,55,56,1,0,0,0,56,54,1,0,0,0,56,57,1,0,0,0,57,61,1,0,0,0,58,
  	60,5,24,0,0,59,58,1,0,0,0,60,63,1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,
  	67,1,0,0,0,63,61,1,0,0,0,64,66,5,2,0,0,65,64,1,0,0,0,66,69,1,0,0,0,67,
  	65,1,0,0,0,67,68,1,0,0,0,68,70,1,0,0,0,69,67,1,0,0,0,70,123,5,3,0,0,71,
  	73,5,4,0,0,72,74,5,2,0,0,73,72,1,0,0,0,74,75,1,0,0,0,75,73,1,0,0,0,75,
  	76,1,0,0,0,76,77,1,0,0,0,77,79,5,25,0,0,78,80,5,2,0,0,79,78,1,0,0,0,80,
  	81,1,0,0,0,81,79,1,0,0,0,81,82,1,0,0,0,82,83,1,0,0,0,83,85,5,25,0,0,84,
  	86,5,2,0,0,85,84,1,0,0,0,86,87,1,0,0,0,87,85,1,0,0,0,87,88,1,0,0,0,88,
  	92,1,0,0,0,89,91,5,20,0,0,90,89,1,0,0,0,91,94,1,0,0,0,92,90,1,0,0,0,92,
  	93,1,0,0,0,93,98,1,0,0,0,94,92,1,0,0,0,95,97,5,2,0,0,96,95,1,0,0,0,97,
  	100,1,0,0,0,98,96,1,0,0,0,98,99,1,0,0,0,99,101,1,0,0,0,100,98,1,0,0,0,
  	101,123,5,3,0,0,102,104,5,4,0,0,103,105,5,2,0,0,104,103,1,0,0,0,105,106,
  	1,0,0,0,106,104,1,0,0,0,106,107,1,0,0,0,107,108,1,0,0,0,108,110,5,25,
  	0,0,109,111,5,2,0,0,110,109,1,0,0,0,111,112,1,0,0,0,112,110,1,0,0,0,112,
  	113,1,0,0,0,113,114,1,0,0,0,114,118,5,25,0,0,115,117,5,2,0,0,116,115,
  	1,0,0,0,117,120,1,0,0,0,118,116,1,0,0,0,118,119,1,0,0,0,119,121,1,0,0,
  	0,120,118,1,0,0,0,121,123,5,3,0,0,122,30,1,0,0,0,122,71,1,0,0,0,122,102,
  	1,0,0,0,123,3,1,0,0,0,124,126,5,5,0,0,125,127,5,2,0,0,126,125,1,0,0,0,
  	127,128,1,0,0,0,128,126,1,0,0,0,128,129,1,0,0,0,129,130,1,0,0,0,130,132,
  	5,25,0,0,131,133,5,2,0,0,132,131,1,0,0,0,133,134,1,0,0,0,134,132,1,0,
  	0,0,134,135,1,0,0,0,135,136,1,0,0,0,136,138,5,25,0,0,137,139,5,2,0,0,
  	138,137,1,0,0,0,139,140,1,0,0,0,140,138,1,0,0,0,140,141,1,0,0,0,141,143,
  	1,0,0,0,142,144,5,20,0,0,143,142,1,0,0,0,144,145,1,0,0,0,145,143,1,0,
  	0,0,145,146,1,0,0,0,146,148,1,0,0,0,147,149,5,2,0,0,148,147,1,0,0,0,149,
  	150,1,0,0,0,150,148,1,0,0,0,150,151,1,0,0,0,151,155,1,0,0,0,152,154,5,
  	24,0,0,153,152,1,0,0,0,154,157,1,0,0,0,155,153,1,0,0,0,155,156,1,0,0,
  	0,156,161,1,0,0,0,157,155,1,0,0,0,158,160,5,2,0,0,159,158,1,0,0,0,160,
  	163,1,0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,164,1,0,0,0,163,161,1,
  	0,0,0,164,289,5,3,0,0,165,167,5,5,0,0,166,168,5,2,0,0,167,166,1,0,0,0,
  	168,169,1,0,0,0,169,167,1,0,0,0,169,170,1,0,0,0,170,171,1,0,0,0,171,173,
  	5,25,0,0,172,174,5,2,0,0,173,172,1,0,0,0,174,175,1,0,0,0,175,173,1,0,
  	0,0,175,176,1,0,0,0,176,177,1,0,0,0,177,179,5,25,0,0,178,180,5,2,0,0,
  	179,178,1,0,0,0,180,181,1,0,0,0,181,179,1,0,0,0,181,182,1,0,0,0,182,186,
  	1,0,0,0,183,185,5,20,0,0,184,183,1,0,0,0,185,188,1,0,0,0,186,184,1,0,
  	0,0,186,187,1,0,0,0,187,192,1,0,0,0,188,186,1,0,0,0,189,191,5,2,0,0,190,
  	189,1,0,0,0,191,194,1,0,0,0,192,190,1,0,0,0,192,193,1,0,0,0,193,195,1,
  	0,0,0,194,192,1,0,0,0,195,289,5,3,0,0,196,198,5,5,0,0,197,199,5,2,0,0,
  	198,197,1,0,0,0,199,200,1,0,0,0,200,198,1,0,0,0,200,201,1,0,0,0,201,202,
  	1,0,0,0,202,204,5,25,0,0,203,205,5,2,0,0,204,203,1,0,0,0,205,206,1,0,
  	0,0,206,204,1,0,0,0,206,207,1,0,0,0,207,208,1,0,0,0,208,212,5,25,0,0,
  	209,211,5,2,0,0,210,209,1,0,0,0,211,214,1,0,0,0,212,210,1,0,0,0,212,213,
  	1,0,0,0,213,215,1,0,0,0,214,212,1,0,0,0,215,289,5,3,0,0,216,218,5,5,0,
  	0,217,219,5,2,0,0,218,217,1,0,0,0,219,220,1,0,0,0,220,218,1,0,0,0,220,
  	221,1,0,0,0,221,222,1,0,0,0,222,224,5,25,0,0,223,225,5,2,0,0,224,223,
  	1,0,0,0,225,226,1,0,0,0,226,224,1,0,0,0,226,227,1,0,0,0,227,228,1,0,0,
  	0,228,230,5,25,0,0,229,231,5,2,0,0,230,229,1,0,0,0,231,232,1,0,0,0,232,
  	230,1,0,0,0,232,233,1,0,0,0,233,235,1,0,0,0,234,236,5,25,0,0,235,234,
  	1,0,0,0,236,237,1,0,0,0,237,235,1,0,0,0,237,238,1,0,0,0,238,240,1,0,0,
  	0,239,241,5,2,0,0,240,239,1,0,0,0,241,242,1,0,0,0,242,240,1,0,0,0,242,
  	243,1,0,0,0,243,247,1,0,0,0,244,246,5,24,0,0,245,244,1,0,0,0,246,249,
  	1,0,0,0,247,245,1,0,0,0,247,248,1,0,0,0,248,253,1,0,0,0,249,247,1,0,0,
  	0,250,252,5,2,0,0,251,250,1,0,0,0,252,255,1,0,0,0,253,251,1,0,0,0,253,
  	254,1,0,0,0,254,256,1,0,0,0,255,253,1,0,0,0,256,289,5,3,0,0,257,259,5,
  	5,0,0,258,260,5,2,0,0,259,258,1,0,0,0,260,261,1,0,0,0,261,259,1,0,0,0,
  	261,262,1,0,0,0,262,263,1,0,0,0,263,265,5,25,0,0,264,266,5,2,0,0,265,
  	264,1,0,0,0,266,267,1,0,0,0,267,265,1,0,0,0,267,268,1,0,0,0,268,269,1,
  	0,0,0,269,271,5,25,0,0,270,272,5,2,0,0,271,270,1,0,0,0,272,273,1,0,0,
  	0,273,271,1,0,0,0,273,274,1,0,0,0,274,278,1,0,0,0,275,277,5,25,0,0,276,
  	275,1,0,0,0,277,280,1,0,0,0,278,276,1,0,0,0,278,279,1,0,0,0,279,284,1,
  	0,0,0,280,278,1,0,0,0,281,283,5,2,0,0,282,281,1,0,0,0,283,286,1,0,0,0,
  	284,282,1,0,0,0,284,285,1,0,0,0,285,287,1,0,0,0,286,284,1,0,0,0,287,289,
  	5,3,0,0,288,124,1,0,0,0,288,165,1,0,0,0,288,196,1,0,0,0,288,216,1,0,0,
  	0,288,257,1,0,0,0,289,5,1,0,0,0,290,292,5,6,0,0,291,293,5,2,0,0,292,291,
  	1,0,0,0,293,294,1,0,0,0,294,292,1,0,0,0,294,295,1,0,0,0,295,296,1,0,0,
  	0,296,298,5,25,0,0,297,299,5,2,0,0,298,297,1,0,0,0,299,300,1,0,0,0,300,
  	298,1,0,0,0,300,301,1,0,0,0,301,302,1,0,0,0,302,304,5,25,0,0,303,305,
  	5,2,0,0,304,303,1,0,0,0,305,306,1,0,0,0,306,304,1,0,0,0,306,307,1,0,0,
  	0,307,309,1,0,0,0,308,310,5,20,0,0,309,308,1,0,0,0,310,311,1,0,0,0,311,
  	309,1,0,0,0,311,312,1,0,0,0,312,314,1,0,0,0,313,315,5,2,0,0,314,313,1,
  	0,0,0,315,316,1,0,0,0,316,314,1,0,0,0,316,317,1,0,0,0,317,321,1,0,0,0,
  	318,320,5,24,0,0,319,318,1,0,0,0,320,323,1,0,0,0,321,319,1,0,0,0,321,
  	322,1,0,0,0,322,327,1,0,0,0,323,321,1,0,0,0,324,326,5,2,0,0,325,324,1,
  	0,0,0,326,329,1,0,0,0,327,325,1,0,0,0,327,328,1,0,0,0,328,330,1,0,0,0,
  	329,327,1,0,0,0,330,383,5,3,0,0,331,333,5,6,0,0,332,334,5,2,0,0,333,332,
  	1,0,0,0,334,335,1,0,0,0,335,333,1,0,0,0,335,336,1,0,0,0,336,337,1,0,0,
  	0,337,339,5,25,0,0,338,340,5,2,0,0,339,338,1,0,0,0,340,341,1,0,0,0,341,
  	339,1,0,0,0,341,342,1,0,0,0,342,343,1,0,0,0,343,345,5,25,0,0,344,346,
  	5,2,0,0,345,344,1,0,0,0,346,347,1,0,0,0,347,345,1,0,0,0,347,348,1,0,0,
  	0,348,352,1,0,0,0,349,351,5,20,0,0,350,349,1,0,0,0,351,354,1,0,0,0,352,
  	350,1,0,0,0,352,353,1,0,0,0,353,358,1,0,0,0,354,352,1,0,0,0,355,357,5,
  	2,0,0,356,355,1,0,0,0,357,360,1,0,0,0,358,356,1,0,0,0,358,359,1,0,0,0,
  	359,361,1,0,0,0,360,358,1,0,0,0,361,383,5,3,0,0,362,364,5,6,0,0,363,365,
  	5,2,0,0,364,363,1,0,0,0,365,366,1,0,0,0,366,364,1,0,0,0,366,367,1,0,0,
  	0,367,368,1,0,0,0,368,370,5,25,0,0,369,371,5,2,0,0,370,369,1,0,0,0,371,
  	372,1,0,0,0,372,370,1,0,0,0,372,373,1,0,0,0,373,374,1,0,0,0,374,378,5,
  	25,0,0,375,377,5,2,0,0,376,375,1,0,0,0,377,380,1,0,0,0,378,376,1,0,0,
  	0,378,379,1,0,0,0,379,381,1,0,0,0,380,378,1,0,0,0,381,383,5,3,0,0,382,
  	290,1,0,0,0,382,331,1,0,0,0,382,362,1,0,0,0,383,7,1,0,0,0,384,385,5,7,
  	0,0,385,386,5,2,0,0,386,387,5,6,0,0,387,388,5,2,0,0,388,389,5,6,0,0,389,
  	390,5,2,0,0,390,391,5,20,0,0,391,9,1,0,0,0,392,394,5,4,0,0,393,395,5,
  	2,0,0,394,393,1,0,0,0,395,396,1,0,0,0,396,394,1,0,0,0,396,397,1,0,0,0,
  	397,398,1,0,0,0,398,400,5,25,0,0,399,401,5,2,0,0,400,399,1,0,0,0,401,
  	402,1,0,0,0,402,400,1,0,0,0,402,403,1,0,0,0,403,404,1,0,0,0,404,406,5,
  	25,0,0,405,407,5,2,0,0,406,405,1,0,0,0,407,408,1,0,0,0,408,406,1,0,0,
  	0,408,409,1,0,0,0,409,411,1,0,0,0,410,412,5,25,0,0,411,410,1,0,0,0,412,
  	413,1,0,0,0,413,411,1,0,0,0,413,414,1,0,0,0,414,416,1,0,0,0,415,417,5,
  	2,0,0,416,415,1,0,0,0,417,418,1,0,0,0,418,416,1,0,0,0,418,419,1,0,0,0,
  	419,423,1,0,0,0,420,422,5,24,0,0,421,420,1,0,0,0,422,425,1,0,0,0,423,
  	421,1,0,0,0,423,424,1,0,0,0,424,429,1,0,0,0,425,423,1,0,0,0,426,428,5,
  	2,0,0,427,426,1,0,0,0,428,431,1,0,0,0,429,427,1,0,0,0,429,430,1,0,0,0,
  	430,432,1,0,0,0,431,429,1,0,0,0,432,485,5,3,0,0,433,435,5,4,0,0,434,436,
  	5,2,0,0,435,434,1,0,0,0,436,437,1,0,0,0,437,435,1,0,0,0,437,438,1,0,0,
  	0,438,439,1,0,0,0,439,441,5,25,0,0,440,442,5,2,0,0,441,440,1,0,0,0,442,
  	443,1,0,0,0,443,441,1,0,0,0,443,444,1,0,0,0,444,445,1,0,0,0,445,447,5,
  	25,0,0,446,448,5,2,0,0,447,446,1,0,0,0,448,449,1,0,0,0,449,447,1,0,0,
  	0,449,450,1,0,0,0,450,454,1,0,0,0,451,453,5,25,0,0,452,451,1,0,0,0,453,
  	456,1,0,0,0,454,452,1,0,0,0,454,455,1,0,0,0,455,460,1,0,0,0,456,454,1,
  	0,0,0,457,459,5,2,0,0,458,457,1,0,0,0,459,462,1,0,0,0,460,458,1,0,0,0,
  	460,461,1,0,0,0,461,463,1,0,0,0,462,460,1,0,0,0,463,485,5,3,0,0,464,466,
  	5,4,0,0,465,467,5,2,0,0,466,465,1,0,0,0,467,468,1,0,0,0,468,466,1,0,0,
  	0,468,469,1,0,0,0,469,470,1,0,0,0,470,472,5,25,0,0,471,473,5,2,0,0,472,
  	471,1,0,0,0,473,474,1,0,0,0,474,472,1,0,0,0,474,475,1,0,0,0,475,476,1,
  	0,0,0,476,480,5,25,0,0,477,479,5,2,0,0,478,477,1,0,0,0,479,482,1,0,0,
  	0,480,478,1,0,0,0,480,481,1,0,0,0,481,483,1,0,0,0,482,480,1,0,0,0,483,
  	485,5,3,0,0,484,392,1,0,0,0,484,433,1,0,0,0,484,464,1,0,0,0,485,11,1,
  	0,0,0,79,15,21,27,34,40,46,51,56,61,67,75,81,87,92,98,106,112,118,122,
  	128,134,140,145,150,155,161,169,175,181,186,192,200,206,212,220,226,232,
  	237,242,247,253,261,267,273,278,284,288,294,300,306,311,316,321,327,335,
  	341,347,352,358,366,372,378,382,396,402,408,413,418,423,429,437,443,449,
  	454,460,468,474,480,484
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
    setState(15);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::RESISTOR_NAME) {
      setState(12);
      resistor();
      setState(17);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(21);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::CAPACITOR_NAME) {
      setState(18);
      capacitor();
      setState(23);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(27);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == TParser::INDUCTOR_NAME) {
      setState(24);
      inductor();
      setState(29);
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
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(30);
      match(TParser::RESISTOR_NAME);
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
      setState(49); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(48);
        match(TParser::COMPONENT_VALUE);
        setState(51); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::COMPONENT_VALUE);
      setState(54); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(53);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(56); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(61);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(58);
        match(TParser::PARAMS);
        setState(63);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(64);
        match(TParser::WHITESPACE);
        setState(69);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(70);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(71);
      match(TParser::RESISTOR_NAME);
      setState(73); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(72);
        match(TParser::WHITESPACE);
        setState(75); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(77);
      match(TParser::TEXT);
      setState(79); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(78);
        match(TParser::WHITESPACE);
        setState(81); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(83);
      match(TParser::TEXT);
      setState(85); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(84);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(87); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(92);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::COMPONENT_VALUE) {
        setState(89);
        match(TParser::COMPONENT_VALUE);
        setState(94);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(95);
        match(TParser::WHITESPACE);
        setState(100);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(101);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(102);
      match(TParser::RESISTOR_NAME);
      setState(104); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(103);
        match(TParser::WHITESPACE);
        setState(106); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(108);
      match(TParser::TEXT);
      setState(110); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(109);
        match(TParser::WHITESPACE);
        setState(112); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(114);
      match(TParser::TEXT);
      setState(118);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(115);
        match(TParser::WHITESPACE);
        setState(120);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(121);
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
    setState(288);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(124);
      match(TParser::CAPACITOR_NAME);
      setState(126); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(125);
        match(TParser::WHITESPACE);
        setState(128); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(130);
      match(TParser::TEXT);
      setState(132); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(131);
        match(TParser::WHITESPACE);
        setState(134); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(136);
      match(TParser::TEXT);
      setState(138); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(137);
        match(TParser::WHITESPACE);
        setState(140); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(143); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(142);
        match(TParser::COMPONENT_VALUE);
        setState(145); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::COMPONENT_VALUE);
      setState(148); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(147);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(150); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(152);
        match(TParser::PARAMS);
        setState(157);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(161);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(158);
        match(TParser::WHITESPACE);
        setState(163);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(164);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(165);
      match(TParser::CAPACITOR_NAME);
      setState(167); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(166);
        match(TParser::WHITESPACE);
        setState(169); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(171);
      match(TParser::TEXT);
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
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(178);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(181); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(186);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::COMPONENT_VALUE) {
        setState(183);
        match(TParser::COMPONENT_VALUE);
        setState(188);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(192);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(189);
        match(TParser::WHITESPACE);
        setState(194);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(195);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(196);
      match(TParser::CAPACITOR_NAME);
      setState(198); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(197);
        match(TParser::WHITESPACE);
        setState(200); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(202);
      match(TParser::TEXT);
      setState(204); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(203);
        match(TParser::WHITESPACE);
        setState(206); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(208);
      match(TParser::TEXT);
      setState(212);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(209);
        match(TParser::WHITESPACE);
        setState(214);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(215);
      match(TParser::NEWLINE);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(216);
      match(TParser::CAPACITOR_NAME);
      setState(218); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(217);
        match(TParser::WHITESPACE);
        setState(220); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(222);
      match(TParser::TEXT);
      setState(224); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(223);
        match(TParser::WHITESPACE);
        setState(226); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(228);
      match(TParser::TEXT);
      setState(230); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(229);
        match(TParser::WHITESPACE);
        setState(232); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(235); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(234);
        match(TParser::TEXT);
        setState(237); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::TEXT);
      setState(240); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(239);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(242); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(247);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(244);
        match(TParser::PARAMS);
        setState(249);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(253);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(250);
        match(TParser::WHITESPACE);
        setState(255);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(256);
      match(TParser::NEWLINE);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(257);
      match(TParser::CAPACITOR_NAME);
      setState(259); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(258);
        match(TParser::WHITESPACE);
        setState(261); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(263);
      match(TParser::TEXT);
      setState(265); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(264);
        match(TParser::WHITESPACE);
        setState(267); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(269);
      match(TParser::TEXT);
      setState(271); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(270);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(273); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(278);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::TEXT) {
        setState(275);
        match(TParser::TEXT);
        setState(280);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(284);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(281);
        match(TParser::WHITESPACE);
        setState(286);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(287);
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
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 62, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(290);
      match(TParser::INDUCTOR_NAME);
      setState(292); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(291);
        match(TParser::WHITESPACE);
        setState(294); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(296);
      match(TParser::TEXT);
      setState(298); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(297);
        match(TParser::WHITESPACE);
        setState(300); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(302);
      match(TParser::TEXT);
      setState(304); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(303);
        match(TParser::WHITESPACE);
        setState(306); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(309); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(308);
        match(TParser::COMPONENT_VALUE);
        setState(311); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::COMPONENT_VALUE);
      setState(314); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(313);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(316); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 51, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(321);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(318);
        match(TParser::PARAMS);
        setState(323);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(327);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(324);
        match(TParser::WHITESPACE);
        setState(329);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(330);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(331);
      match(TParser::INDUCTOR_NAME);
      setState(333); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(332);
        match(TParser::WHITESPACE);
        setState(335); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(337);
      match(TParser::TEXT);
      setState(339); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(338);
        match(TParser::WHITESPACE);
        setState(341); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(343);
      match(TParser::TEXT);
      setState(345); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(344);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(347); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(352);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::COMPONENT_VALUE) {
        setState(349);
        match(TParser::COMPONENT_VALUE);
        setState(354);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(358);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(355);
        match(TParser::WHITESPACE);
        setState(360);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(361);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(362);
      match(TParser::INDUCTOR_NAME);
      setState(364); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(363);
        match(TParser::WHITESPACE);
        setState(366); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(368);
      match(TParser::TEXT);
      setState(370); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(369);
        match(TParser::WHITESPACE);
        setState(372); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(374);
      match(TParser::TEXT);
      setState(378);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(375);
        match(TParser::WHITESPACE);
        setState(380);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(381);
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

//----------------- Mutual_inductorContext ------------------------------------------------------------------

TParser::Mutual_inductorContext::Mutual_inductorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::Mutual_inductorContext::MUTUAL_INDUCTOR_NAME() {
  return getToken(TParser::MUTUAL_INDUCTOR_NAME, 0);
}

std::vector<tree::TerminalNode *> TParser::Mutual_inductorContext::WHITESPACE() {
  return getTokens(TParser::WHITESPACE);
}

tree::TerminalNode* TParser::Mutual_inductorContext::WHITESPACE(size_t i) {
  return getToken(TParser::WHITESPACE, i);
}

std::vector<tree::TerminalNode *> TParser::Mutual_inductorContext::INDUCTOR_NAME() {
  return getTokens(TParser::INDUCTOR_NAME);
}

tree::TerminalNode* TParser::Mutual_inductorContext::INDUCTOR_NAME(size_t i) {
  return getToken(TParser::INDUCTOR_NAME, i);
}

tree::TerminalNode* TParser::Mutual_inductorContext::COMPONENT_VALUE() {
  return getToken(TParser::COMPONENT_VALUE, 0);
}


size_t TParser::Mutual_inductorContext::getRuleIndex() const {
  return TParser::RuleMutual_inductor;
}


std::any TParser::Mutual_inductorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitMutual_inductor(this);
  else
    return visitor->visitChildren(this);
}

TParser::Mutual_inductorContext* TParser::mutual_inductor() {
  Mutual_inductorContext *_localctx = _tracker.createInstance<Mutual_inductorContext>(_ctx, getState());
  enterRule(_localctx, 8, TParser::RuleMutual_inductor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(384);
    match(TParser::MUTUAL_INDUCTOR_NAME);
    setState(385);
    match(TParser::WHITESPACE);
    setState(386);
    match(TParser::INDUCTOR_NAME);
    setState(387);
    match(TParser::WHITESPACE);
    setState(388);
    match(TParser::INDUCTOR_NAME);
    setState(389);
    match(TParser::WHITESPACE);
    setState(390);
    match(TParser::COMPONENT_VALUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DiodContext ------------------------------------------------------------------

TParser::DiodContext::DiodContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* TParser::DiodContext::RESISTOR_NAME() {
  return getToken(TParser::RESISTOR_NAME, 0);
}

std::vector<tree::TerminalNode *> TParser::DiodContext::TEXT() {
  return getTokens(TParser::TEXT);
}

tree::TerminalNode* TParser::DiodContext::TEXT(size_t i) {
  return getToken(TParser::TEXT, i);
}

tree::TerminalNode* TParser::DiodContext::NEWLINE() {
  return getToken(TParser::NEWLINE, 0);
}

std::vector<tree::TerminalNode *> TParser::DiodContext::WHITESPACE() {
  return getTokens(TParser::WHITESPACE);
}

tree::TerminalNode* TParser::DiodContext::WHITESPACE(size_t i) {
  return getToken(TParser::WHITESPACE, i);
}

std::vector<tree::TerminalNode *> TParser::DiodContext::PARAMS() {
  return getTokens(TParser::PARAMS);
}

tree::TerminalNode* TParser::DiodContext::PARAMS(size_t i) {
  return getToken(TParser::PARAMS, i);
}


size_t TParser::DiodContext::getRuleIndex() const {
  return TParser::RuleDiod;
}


std::any TParser::DiodContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<TParserVisitor*>(visitor))
    return parserVisitor->visitDiod(this);
  else
    return visitor->visitChildren(this);
}

TParser::DiodContext* TParser::diod() {
  DiodContext *_localctx = _tracker.createInstance<DiodContext>(_ctx, getState());
  enterRule(_localctx, 10, TParser::RuleDiod);
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
    setState(484);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 78, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(392);
      match(TParser::RESISTOR_NAME);
      setState(394); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(393);
        match(TParser::WHITESPACE);
        setState(396); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(398);
      match(TParser::TEXT);
      setState(400); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(399);
        match(TParser::WHITESPACE);
        setState(402); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(404);
      match(TParser::TEXT);
      setState(406); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(405);
        match(TParser::WHITESPACE);
        setState(408); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(411); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(410);
        match(TParser::TEXT);
        setState(413); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::TEXT);
      setState(416); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(415);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(418); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(423);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::PARAMS) {
        setState(420);
        match(TParser::PARAMS);
        setState(425);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(429);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(426);
        match(TParser::WHITESPACE);
        setState(431);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(432);
      match(TParser::NEWLINE);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(433);
      match(TParser::RESISTOR_NAME);
      setState(435); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(434);
        match(TParser::WHITESPACE);
        setState(437); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(439);
      match(TParser::TEXT);
      setState(441); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(440);
        match(TParser::WHITESPACE);
        setState(443); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(445);
      match(TParser::TEXT);
      setState(447); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(446);
                match(TParser::WHITESPACE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(449); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(454);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::TEXT) {
        setState(451);
        match(TParser::TEXT);
        setState(456);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(460);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(457);
        match(TParser::WHITESPACE);
        setState(462);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(463);
      match(TParser::NEWLINE);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(464);
      match(TParser::RESISTOR_NAME);
      setState(466); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(465);
        match(TParser::WHITESPACE);
        setState(468); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(470);
      match(TParser::TEXT);
      setState(472); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(471);
        match(TParser::WHITESPACE);
        setState(474); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == TParser::WHITESPACE);
      setState(476);
      match(TParser::TEXT);
      setState(480);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == TParser::WHITESPACE) {
        setState(477);
        match(TParser::WHITESPACE);
        setState(482);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(483);
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

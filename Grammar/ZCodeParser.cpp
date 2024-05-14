
// Generated from ./Grammar/ZCode.g4 by ANTLR 4.13.1


#include "ZCodeVisitor.h"

#include "ZCodeParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct ZCodeParserStaticData final {
  ZCodeParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ZCodeParserStaticData(const ZCodeParserStaticData&) = delete;
  ZCodeParserStaticData(ZCodeParserStaticData&&) = delete;
  ZCodeParserStaticData& operator=(const ZCodeParserStaticData&) = delete;
  ZCodeParserStaticData& operator=(ZCodeParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag zcodeParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ZCodeParserStaticData *zcodeParserStaticData = nullptr;

void zcodeParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (zcodeParserStaticData != nullptr) {
    return;
  }
#else
  assert(zcodeParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ZCodeParserStaticData>(
    std::vector<std::string>{
      "program", "decl", "var_decl", "num_list", "vartype", "func_decl", 
      "params", "param", "stmt", "if_stmt", "assign_stmt", "lhs", "elem_array", 
      "for_stmt", "break_stmt", "continue_stmt", "return_stmt", "func_call_stmt", 
      "block_stmt", "expr", "expr1", "expr2", "expr3", "expr4", "expr5", 
      "expr6", "expr7", "array_cell", "func_call", "operands", "literals", 
      "array_lit", "expr_list"
    },
    std::vector<std::string>{
      "", "'break'", "'continue'", "'if'", "'else'", "'elif'", "'for'", 
      "'until'", "'by'", "'true'", "'false'", "'number'", "'bool'", "'string'", 
      "'return'", "'dynamic'", "'not'", "'and'", "'var'", "'or'", "'begin'", 
      "'end'", "'func'", "'+'", "'-'", "'*'", "'/'", "'%'", "'=='", "'='", 
      "'!='", "'<-'", "'<'", "'<='", "'>'", "'>='", "'...'", "'('", "')'", 
      "'['", "']'", "','"
    },
    std::vector<std::string>{
      "", "BREAK", "CONTINUE", "IF", "ELSE", "ELIF", "FOR", "UNTIL", "BY", 
      "TRUE", "FALSE", "NUMBER", "BOOL", "STRING", "RETURN", "DYNAMIC", 
      "NOT", "AND", "VAR", "OR", "BEGIN", "END", "FUNC", "ADD", "SUB", "MUL", 
      "DIV", "MOD", "STR_EQ", "EQ", "NOT_EQ", "REV_ARROW", "LT", "LTE", 
      "GT", "GTE", "CONCAT", "LR", "RR", "LS", "RS", "COMMA", "ID", "NUM_LIT", 
      "STR_LIT", "NEWLINE", "CMT", "WS", "ERROR_CHAR", "UNCLOSED_STRING", 
      "ILLEGAL_ESCAPE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,50,375,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,1,0,5,0,68,8,0,10,0,12,0,71,
  	9,0,1,0,1,0,1,0,5,0,76,8,0,10,0,12,0,79,9,0,1,0,1,0,1,1,1,1,3,1,85,8,
  	1,1,1,4,1,88,8,1,11,1,12,1,89,1,2,1,2,3,2,94,8,2,1,2,1,2,1,2,3,2,99,8,
  	2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,112,8,2,3,2,114,8,2,
  	1,3,1,3,1,3,1,3,3,3,120,8,3,1,4,1,4,1,5,1,5,1,5,1,5,3,5,128,8,5,1,5,1,
  	5,5,5,132,8,5,10,5,12,5,135,9,5,1,5,1,5,3,5,139,8,5,1,6,1,6,1,6,1,6,1,
  	6,3,6,146,8,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,157,8,7,1,8,1,8,
  	1,8,1,8,1,8,1,8,1,8,1,8,1,8,3,8,168,8,8,1,9,1,9,1,9,1,9,1,9,5,9,175,8,
  	9,10,9,12,9,178,9,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,5,9,188,8,9,10,9,
  	12,9,191,9,9,1,9,1,9,5,9,195,8,9,10,9,12,9,198,9,9,1,9,1,9,1,9,3,9,203,
  	8,9,1,10,1,10,1,10,1,10,1,11,1,11,3,11,211,8,11,1,12,1,12,1,12,1,12,1,
  	12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,5,13,225,8,13,10,13,12,13,228,9,
  	13,1,13,1,13,1,14,1,14,1,15,1,15,1,16,1,16,3,16,238,8,16,1,17,1,17,1,
  	17,3,17,243,8,17,1,17,1,17,1,18,1,18,4,18,249,8,18,11,18,12,18,250,1,
  	18,5,18,254,8,18,10,18,12,18,257,9,18,1,18,4,18,260,8,18,11,18,12,18,
  	261,5,18,264,8,18,10,18,12,18,267,9,18,1,18,1,18,1,19,1,19,1,19,1,19,
  	1,19,3,19,276,8,19,1,20,1,20,1,20,1,20,1,20,3,20,283,8,20,1,21,1,21,1,
  	21,1,21,1,21,1,21,5,21,291,8,21,10,21,12,21,294,9,21,1,22,1,22,1,22,1,
  	22,1,22,1,22,5,22,302,8,22,10,22,12,22,305,9,22,1,23,1,23,1,23,1,23,1,
  	23,1,23,5,23,313,8,23,10,23,12,23,316,9,23,1,24,1,24,1,24,3,24,321,8,
  	24,1,25,1,25,1,25,3,25,326,8,25,1,26,1,26,3,26,330,8,26,1,27,1,27,3,27,
  	334,8,27,1,27,1,27,1,27,1,27,1,28,1,28,1,28,3,28,343,8,28,1,28,1,28,1,
  	29,1,29,1,29,1,29,1,29,1,29,1,29,3,29,354,8,29,1,30,1,30,1,30,1,30,1,
  	30,3,30,361,8,30,1,31,1,31,1,31,1,31,1,32,1,32,1,32,5,32,370,8,32,10,
  	32,12,32,373,9,32,1,32,0,3,42,44,46,33,0,2,4,6,8,10,12,14,16,18,20,22,
  	24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,62,64,0,5,1,
  	0,11,13,2,0,28,30,32,35,2,0,17,17,19,19,1,0,23,24,1,0,25,27,396,0,69,
  	1,0,0,0,2,84,1,0,0,0,4,113,1,0,0,0,6,119,1,0,0,0,8,121,1,0,0,0,10,123,
  	1,0,0,0,12,145,1,0,0,0,14,156,1,0,0,0,16,167,1,0,0,0,18,169,1,0,0,0,20,
  	204,1,0,0,0,22,210,1,0,0,0,24,212,1,0,0,0,26,217,1,0,0,0,28,231,1,0,0,
  	0,30,233,1,0,0,0,32,235,1,0,0,0,34,239,1,0,0,0,36,246,1,0,0,0,38,275,
  	1,0,0,0,40,282,1,0,0,0,42,284,1,0,0,0,44,295,1,0,0,0,46,306,1,0,0,0,48,
  	320,1,0,0,0,50,325,1,0,0,0,52,329,1,0,0,0,54,333,1,0,0,0,56,339,1,0,0,
  	0,58,353,1,0,0,0,60,360,1,0,0,0,62,362,1,0,0,0,64,366,1,0,0,0,66,68,5,
  	45,0,0,67,66,1,0,0,0,68,71,1,0,0,0,69,67,1,0,0,0,69,70,1,0,0,0,70,72,
  	1,0,0,0,71,69,1,0,0,0,72,77,3,2,1,0,73,76,5,45,0,0,74,76,3,2,1,0,75,73,
  	1,0,0,0,75,74,1,0,0,0,76,79,1,0,0,0,77,75,1,0,0,0,77,78,1,0,0,0,78,80,
  	1,0,0,0,79,77,1,0,0,0,80,81,5,0,0,1,81,1,1,0,0,0,82,85,3,4,2,0,83,85,
  	3,10,5,0,84,82,1,0,0,0,84,83,1,0,0,0,85,87,1,0,0,0,86,88,5,45,0,0,87,
  	86,1,0,0,0,88,89,1,0,0,0,89,87,1,0,0,0,89,90,1,0,0,0,90,3,1,0,0,0,91,
  	94,3,8,4,0,92,94,5,15,0,0,93,91,1,0,0,0,93,92,1,0,0,0,94,95,1,0,0,0,95,
  	98,5,42,0,0,96,97,5,31,0,0,97,99,3,38,19,0,98,96,1,0,0,0,98,99,1,0,0,
  	0,99,114,1,0,0,0,100,101,5,18,0,0,101,102,5,42,0,0,102,103,5,31,0,0,103,
  	114,3,38,19,0,104,105,3,8,4,0,105,106,5,42,0,0,106,107,5,39,0,0,107,108,
  	3,6,3,0,108,111,5,40,0,0,109,110,5,31,0,0,110,112,3,38,19,0,111,109,1,
  	0,0,0,111,112,1,0,0,0,112,114,1,0,0,0,113,93,1,0,0,0,113,100,1,0,0,0,
  	113,104,1,0,0,0,114,5,1,0,0,0,115,116,5,43,0,0,116,117,5,41,0,0,117,120,
  	3,6,3,0,118,120,5,43,0,0,119,115,1,0,0,0,119,118,1,0,0,0,120,7,1,0,0,
  	0,121,122,7,0,0,0,122,9,1,0,0,0,123,124,5,22,0,0,124,125,5,42,0,0,125,
  	127,5,37,0,0,126,128,3,12,6,0,127,126,1,0,0,0,127,128,1,0,0,0,128,129,
  	1,0,0,0,129,133,5,38,0,0,130,132,5,45,0,0,131,130,1,0,0,0,132,135,1,0,
  	0,0,133,131,1,0,0,0,133,134,1,0,0,0,134,138,1,0,0,0,135,133,1,0,0,0,136,
  	139,3,32,16,0,137,139,3,36,18,0,138,136,1,0,0,0,138,137,1,0,0,0,138,139,
  	1,0,0,0,139,11,1,0,0,0,140,141,3,14,7,0,141,142,5,41,0,0,142,143,3,12,
  	6,0,143,146,1,0,0,0,144,146,3,14,7,0,145,140,1,0,0,0,145,144,1,0,0,0,
  	146,13,1,0,0,0,147,148,3,8,4,0,148,149,5,42,0,0,149,157,1,0,0,0,150,151,
  	3,8,4,0,151,152,5,42,0,0,152,153,5,39,0,0,153,154,3,6,3,0,154,155,5,40,
  	0,0,155,157,1,0,0,0,156,147,1,0,0,0,156,150,1,0,0,0,157,15,1,0,0,0,158,
  	168,3,4,2,0,159,168,3,18,9,0,160,168,3,20,10,0,161,168,3,26,13,0,162,
  	168,3,28,14,0,163,168,3,30,15,0,164,168,3,34,17,0,165,168,3,32,16,0,166,
  	168,3,36,18,0,167,158,1,0,0,0,167,159,1,0,0,0,167,160,1,0,0,0,167,161,
  	1,0,0,0,167,162,1,0,0,0,167,163,1,0,0,0,167,164,1,0,0,0,167,165,1,0,0,
  	0,167,166,1,0,0,0,168,17,1,0,0,0,169,170,5,3,0,0,170,171,5,37,0,0,171,
  	172,3,38,19,0,172,176,5,38,0,0,173,175,5,45,0,0,174,173,1,0,0,0,175,178,
  	1,0,0,0,176,174,1,0,0,0,176,177,1,0,0,0,177,179,1,0,0,0,178,176,1,0,0,
  	0,179,180,3,16,8,0,180,196,1,0,0,0,181,182,5,45,0,0,182,183,5,5,0,0,183,
  	184,5,37,0,0,184,185,3,38,19,0,185,189,5,38,0,0,186,188,5,45,0,0,187,
  	186,1,0,0,0,188,191,1,0,0,0,189,187,1,0,0,0,189,190,1,0,0,0,190,192,1,
  	0,0,0,191,189,1,0,0,0,192,193,3,16,8,0,193,195,1,0,0,0,194,181,1,0,0,
  	0,195,198,1,0,0,0,196,194,1,0,0,0,196,197,1,0,0,0,197,202,1,0,0,0,198,
  	196,1,0,0,0,199,200,5,45,0,0,200,201,5,4,0,0,201,203,3,16,8,0,202,199,
  	1,0,0,0,202,203,1,0,0,0,203,19,1,0,0,0,204,205,3,22,11,0,205,206,5,31,
  	0,0,206,207,3,38,19,0,207,21,1,0,0,0,208,211,5,42,0,0,209,211,3,24,12,
  	0,210,208,1,0,0,0,210,209,1,0,0,0,211,23,1,0,0,0,212,213,5,42,0,0,213,
  	214,5,39,0,0,214,215,3,64,32,0,215,216,5,40,0,0,216,25,1,0,0,0,217,218,
  	5,6,0,0,218,219,5,42,0,0,219,220,5,7,0,0,220,221,3,38,19,0,221,222,5,
  	8,0,0,222,226,3,38,19,0,223,225,5,45,0,0,224,223,1,0,0,0,225,228,1,0,
  	0,0,226,224,1,0,0,0,226,227,1,0,0,0,227,229,1,0,0,0,228,226,1,0,0,0,229,
  	230,3,16,8,0,230,27,1,0,0,0,231,232,5,1,0,0,232,29,1,0,0,0,233,234,5,
  	2,0,0,234,31,1,0,0,0,235,237,5,14,0,0,236,238,3,38,19,0,237,236,1,0,0,
  	0,237,238,1,0,0,0,238,33,1,0,0,0,239,240,5,42,0,0,240,242,5,37,0,0,241,
  	243,3,64,32,0,242,241,1,0,0,0,242,243,1,0,0,0,243,244,1,0,0,0,244,245,
  	5,38,0,0,245,35,1,0,0,0,246,248,5,20,0,0,247,249,5,45,0,0,248,247,1,0,
  	0,0,249,250,1,0,0,0,250,248,1,0,0,0,250,251,1,0,0,0,251,265,1,0,0,0,252,
  	254,3,16,8,0,253,252,1,0,0,0,254,257,1,0,0,0,255,253,1,0,0,0,255,256,
  	1,0,0,0,256,259,1,0,0,0,257,255,1,0,0,0,258,260,5,45,0,0,259,258,1,0,
  	0,0,260,261,1,0,0,0,261,259,1,0,0,0,261,262,1,0,0,0,262,264,1,0,0,0,263,
  	255,1,0,0,0,264,267,1,0,0,0,265,263,1,0,0,0,265,266,1,0,0,0,266,268,1,
  	0,0,0,267,265,1,0,0,0,268,269,5,21,0,0,269,37,1,0,0,0,270,271,3,40,20,
  	0,271,272,5,36,0,0,272,273,3,40,20,0,273,276,1,0,0,0,274,276,3,40,20,
  	0,275,270,1,0,0,0,275,274,1,0,0,0,276,39,1,0,0,0,277,278,3,42,21,0,278,
  	279,7,1,0,0,279,280,3,42,21,0,280,283,1,0,0,0,281,283,3,42,21,0,282,277,
  	1,0,0,0,282,281,1,0,0,0,283,41,1,0,0,0,284,285,6,21,-1,0,285,286,3,44,
  	22,0,286,292,1,0,0,0,287,288,10,2,0,0,288,289,7,2,0,0,289,291,3,44,22,
  	0,290,287,1,0,0,0,291,294,1,0,0,0,292,290,1,0,0,0,292,293,1,0,0,0,293,
  	43,1,0,0,0,294,292,1,0,0,0,295,296,6,22,-1,0,296,297,3,46,23,0,297,303,
  	1,0,0,0,298,299,10,2,0,0,299,300,7,3,0,0,300,302,3,46,23,0,301,298,1,
  	0,0,0,302,305,1,0,0,0,303,301,1,0,0,0,303,304,1,0,0,0,304,45,1,0,0,0,
  	305,303,1,0,0,0,306,307,6,23,-1,0,307,308,3,48,24,0,308,314,1,0,0,0,309,
  	310,10,2,0,0,310,311,7,4,0,0,311,313,3,48,24,0,312,309,1,0,0,0,313,316,
  	1,0,0,0,314,312,1,0,0,0,314,315,1,0,0,0,315,47,1,0,0,0,316,314,1,0,0,
  	0,317,318,5,16,0,0,318,321,3,48,24,0,319,321,3,50,25,0,320,317,1,0,0,
  	0,320,319,1,0,0,0,321,49,1,0,0,0,322,323,7,3,0,0,323,326,3,50,25,0,324,
  	326,3,52,26,0,325,322,1,0,0,0,325,324,1,0,0,0,326,51,1,0,0,0,327,330,
  	3,54,27,0,328,330,3,58,29,0,329,327,1,0,0,0,329,328,1,0,0,0,330,53,1,
  	0,0,0,331,334,5,42,0,0,332,334,3,56,28,0,333,331,1,0,0,0,333,332,1,0,
  	0,0,334,335,1,0,0,0,335,336,5,39,0,0,336,337,3,64,32,0,337,338,5,40,0,
  	0,338,55,1,0,0,0,339,340,5,42,0,0,340,342,5,37,0,0,341,343,3,64,32,0,
  	342,341,1,0,0,0,342,343,1,0,0,0,343,344,1,0,0,0,344,345,5,38,0,0,345,
  	57,1,0,0,0,346,354,5,42,0,0,347,348,5,37,0,0,348,349,3,38,19,0,349,350,
  	5,38,0,0,350,354,1,0,0,0,351,354,3,60,30,0,352,354,3,56,28,0,353,346,
  	1,0,0,0,353,347,1,0,0,0,353,351,1,0,0,0,353,352,1,0,0,0,354,59,1,0,0,
  	0,355,361,5,43,0,0,356,361,5,44,0,0,357,361,5,9,0,0,358,361,5,10,0,0,
  	359,361,3,62,31,0,360,355,1,0,0,0,360,356,1,0,0,0,360,357,1,0,0,0,360,
  	358,1,0,0,0,360,359,1,0,0,0,361,61,1,0,0,0,362,363,5,39,0,0,363,364,3,
  	64,32,0,364,365,5,40,0,0,365,63,1,0,0,0,366,371,3,38,19,0,367,368,5,41,
  	0,0,368,370,3,38,19,0,369,367,1,0,0,0,370,373,1,0,0,0,371,369,1,0,0,0,
  	371,372,1,0,0,0,372,65,1,0,0,0,373,371,1,0,0,0,41,69,75,77,84,89,93,98,
  	111,113,119,127,133,138,145,156,167,176,189,196,202,210,226,237,242,250,
  	255,261,265,275,282,292,303,314,320,325,329,333,342,353,360,371
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  zcodeParserStaticData = staticData.release();
}

}

ZCodeParser::ZCodeParser(TokenStream *input) : ZCodeParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

ZCodeParser::ZCodeParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  ZCodeParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *zcodeParserStaticData->atn, zcodeParserStaticData->decisionToDFA, zcodeParserStaticData->sharedContextCache, options);
}

ZCodeParser::~ZCodeParser() {
  delete _interpreter;
}

const atn::ATN& ZCodeParser::getATN() const {
  return *zcodeParserStaticData->atn;
}

std::string ZCodeParser::getGrammarFileName() const {
  return "ZCode.g4";
}

const std::vector<std::string>& ZCodeParser::getRuleNames() const {
  return zcodeParserStaticData->ruleNames;
}

const dfa::Vocabulary& ZCodeParser::getVocabulary() const {
  return zcodeParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ZCodeParser::getSerializedATN() const {
  return zcodeParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

ZCodeParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ZCodeParser::DeclContext *> ZCodeParser::ProgramContext::decl() {
  return getRuleContexts<ZCodeParser::DeclContext>();
}

ZCodeParser::DeclContext* ZCodeParser::ProgramContext::decl(size_t i) {
  return getRuleContext<ZCodeParser::DeclContext>(i);
}

tree::TerminalNode* ZCodeParser::ProgramContext::EOF() {
  return getToken(ZCodeParser::EOF, 0);
}

std::vector<tree::TerminalNode *> ZCodeParser::ProgramContext::NEWLINE() {
  return getTokens(ZCodeParser::NEWLINE);
}

tree::TerminalNode* ZCodeParser::ProgramContext::NEWLINE(size_t i) {
  return getToken(ZCodeParser::NEWLINE, i);
}


size_t ZCodeParser::ProgramContext::getRuleIndex() const {
  return ZCodeParser::RuleProgram;
}


std::any ZCodeParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::ProgramContext* ZCodeParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ZCodeParser::RuleProgram);
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
    setState(69);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ZCodeParser::NEWLINE) {
      setState(66);
      match(ZCodeParser::NEWLINE);
      setState(71);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(72);
    decl();
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 35184376592384) != 0)) {
      setState(75);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ZCodeParser::NEWLINE: {
          setState(73);
          match(ZCodeParser::NEWLINE);
          break;
        }

        case ZCodeParser::NUMBER:
        case ZCodeParser::BOOL:
        case ZCodeParser::STRING:
        case ZCodeParser::DYNAMIC:
        case ZCodeParser::VAR:
        case ZCodeParser::FUNC: {
          setState(74);
          decl();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(80);
    match(ZCodeParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclContext ------------------------------------------------------------------

ZCodeParser::DeclContext::DeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::Var_declContext* ZCodeParser::DeclContext::var_decl() {
  return getRuleContext<ZCodeParser::Var_declContext>(0);
}

ZCodeParser::Func_declContext* ZCodeParser::DeclContext::func_decl() {
  return getRuleContext<ZCodeParser::Func_declContext>(0);
}

std::vector<tree::TerminalNode *> ZCodeParser::DeclContext::NEWLINE() {
  return getTokens(ZCodeParser::NEWLINE);
}

tree::TerminalNode* ZCodeParser::DeclContext::NEWLINE(size_t i) {
  return getToken(ZCodeParser::NEWLINE, i);
}


size_t ZCodeParser::DeclContext::getRuleIndex() const {
  return ZCodeParser::RuleDecl;
}


std::any ZCodeParser::DeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitDecl(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::DeclContext* ZCodeParser::decl() {
  DeclContext *_localctx = _tracker.createInstance<DeclContext>(_ctx, getState());
  enterRule(_localctx, 2, ZCodeParser::RuleDecl);

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
    setState(84);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ZCodeParser::NUMBER:
      case ZCodeParser::BOOL:
      case ZCodeParser::STRING:
      case ZCodeParser::DYNAMIC:
      case ZCodeParser::VAR: {
        setState(82);
        var_decl();
        break;
      }

      case ZCodeParser::FUNC: {
        setState(83);
        func_decl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(87); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(86);
              match(ZCodeParser::NEWLINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(89); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declContext ------------------------------------------------------------------

ZCodeParser::Var_declContext::Var_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Var_declContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

ZCodeParser::VartypeContext* ZCodeParser::Var_declContext::vartype() {
  return getRuleContext<ZCodeParser::VartypeContext>(0);
}

tree::TerminalNode* ZCodeParser::Var_declContext::DYNAMIC() {
  return getToken(ZCodeParser::DYNAMIC, 0);
}

tree::TerminalNode* ZCodeParser::Var_declContext::REV_ARROW() {
  return getToken(ZCodeParser::REV_ARROW, 0);
}

ZCodeParser::ExprContext* ZCodeParser::Var_declContext::expr() {
  return getRuleContext<ZCodeParser::ExprContext>(0);
}

tree::TerminalNode* ZCodeParser::Var_declContext::VAR() {
  return getToken(ZCodeParser::VAR, 0);
}

tree::TerminalNode* ZCodeParser::Var_declContext::LS() {
  return getToken(ZCodeParser::LS, 0);
}

ZCodeParser::Num_listContext* ZCodeParser::Var_declContext::num_list() {
  return getRuleContext<ZCodeParser::Num_listContext>(0);
}

tree::TerminalNode* ZCodeParser::Var_declContext::RS() {
  return getToken(ZCodeParser::RS, 0);
}


size_t ZCodeParser::Var_declContext::getRuleIndex() const {
  return ZCodeParser::RuleVar_decl;
}


std::any ZCodeParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Var_declContext* ZCodeParser::var_decl() {
  Var_declContext *_localctx = _tracker.createInstance<Var_declContext>(_ctx, getState());
  enterRule(_localctx, 4, ZCodeParser::RuleVar_decl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(113);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ZCodeParser::NUMBER:
        case ZCodeParser::BOOL:
        case ZCodeParser::STRING: {
          setState(91);
          vartype();
          break;
        }

        case ZCodeParser::DYNAMIC: {
          setState(92);
          match(ZCodeParser::DYNAMIC);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(95);
      match(ZCodeParser::ID);
      setState(98);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ZCodeParser::REV_ARROW) {
        setState(96);
        match(ZCodeParser::REV_ARROW);
        setState(97);
        expr();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(100);
      match(ZCodeParser::VAR);
      setState(101);
      match(ZCodeParser::ID);
      setState(102);
      match(ZCodeParser::REV_ARROW);
      setState(103);
      expr();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(104);
      vartype();
      setState(105);
      match(ZCodeParser::ID);
      setState(106);
      match(ZCodeParser::LS);
      setState(107);
      num_list();
      setState(108);
      match(ZCodeParser::RS);
      setState(111);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == ZCodeParser::REV_ARROW) {
        setState(109);
        match(ZCodeParser::REV_ARROW);
        setState(110);
        expr();
      }
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

//----------------- Num_listContext ------------------------------------------------------------------

ZCodeParser::Num_listContext::Num_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Num_listContext::NUM_LIT() {
  return getToken(ZCodeParser::NUM_LIT, 0);
}

tree::TerminalNode* ZCodeParser::Num_listContext::COMMA() {
  return getToken(ZCodeParser::COMMA, 0);
}

ZCodeParser::Num_listContext* ZCodeParser::Num_listContext::num_list() {
  return getRuleContext<ZCodeParser::Num_listContext>(0);
}


size_t ZCodeParser::Num_listContext::getRuleIndex() const {
  return ZCodeParser::RuleNum_list;
}


std::any ZCodeParser::Num_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitNum_list(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Num_listContext* ZCodeParser::num_list() {
  Num_listContext *_localctx = _tracker.createInstance<Num_listContext>(_ctx, getState());
  enterRule(_localctx, 6, ZCodeParser::RuleNum_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(119);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      match(ZCodeParser::NUM_LIT);
      setState(116);
      match(ZCodeParser::COMMA);
      setState(117);
      num_list();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(118);
      match(ZCodeParser::NUM_LIT);
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

//----------------- VartypeContext ------------------------------------------------------------------

ZCodeParser::VartypeContext::VartypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::VartypeContext::NUMBER() {
  return getToken(ZCodeParser::NUMBER, 0);
}

tree::TerminalNode* ZCodeParser::VartypeContext::BOOL() {
  return getToken(ZCodeParser::BOOL, 0);
}

tree::TerminalNode* ZCodeParser::VartypeContext::STRING() {
  return getToken(ZCodeParser::STRING, 0);
}


size_t ZCodeParser::VartypeContext::getRuleIndex() const {
  return ZCodeParser::RuleVartype;
}


std::any ZCodeParser::VartypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitVartype(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::VartypeContext* ZCodeParser::vartype() {
  VartypeContext *_localctx = _tracker.createInstance<VartypeContext>(_ctx, getState());
  enterRule(_localctx, 8, ZCodeParser::RuleVartype);
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
    setState(121);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14336) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declContext ------------------------------------------------------------------

ZCodeParser::Func_declContext::Func_declContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Func_declContext::FUNC() {
  return getToken(ZCodeParser::FUNC, 0);
}

tree::TerminalNode* ZCodeParser::Func_declContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

tree::TerminalNode* ZCodeParser::Func_declContext::LR() {
  return getToken(ZCodeParser::LR, 0);
}

tree::TerminalNode* ZCodeParser::Func_declContext::RR() {
  return getToken(ZCodeParser::RR, 0);
}

ZCodeParser::ParamsContext* ZCodeParser::Func_declContext::params() {
  return getRuleContext<ZCodeParser::ParamsContext>(0);
}

std::vector<tree::TerminalNode *> ZCodeParser::Func_declContext::NEWLINE() {
  return getTokens(ZCodeParser::NEWLINE);
}

tree::TerminalNode* ZCodeParser::Func_declContext::NEWLINE(size_t i) {
  return getToken(ZCodeParser::NEWLINE, i);
}

ZCodeParser::Return_stmtContext* ZCodeParser::Func_declContext::return_stmt() {
  return getRuleContext<ZCodeParser::Return_stmtContext>(0);
}

ZCodeParser::Block_stmtContext* ZCodeParser::Func_declContext::block_stmt() {
  return getRuleContext<ZCodeParser::Block_stmtContext>(0);
}


size_t ZCodeParser::Func_declContext::getRuleIndex() const {
  return ZCodeParser::RuleFunc_decl;
}


std::any ZCodeParser::Func_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitFunc_decl(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Func_declContext* ZCodeParser::func_decl() {
  Func_declContext *_localctx = _tracker.createInstance<Func_declContext>(_ctx, getState());
  enterRule(_localctx, 10, ZCodeParser::RuleFunc_decl);
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
    setState(123);
    match(ZCodeParser::FUNC);
    setState(124);
    match(ZCodeParser::ID);
    setState(125);
    match(ZCodeParser::LR);
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 14336) != 0)) {
      setState(126);
      params();
    }
    setState(129);
    match(ZCodeParser::RR);
    setState(133);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(130);
        match(ZCodeParser::NEWLINE); 
      }
      setState(135);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(138);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ZCodeParser::RETURN: {
        setState(136);
        return_stmt();
        break;
      }

      case ZCodeParser::BEGIN: {
        setState(137);
        block_stmt();
        break;
      }

      case ZCodeParser::NEWLINE: {
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

//----------------- ParamsContext ------------------------------------------------------------------

ZCodeParser::ParamsContext::ParamsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::ParamContext* ZCodeParser::ParamsContext::param() {
  return getRuleContext<ZCodeParser::ParamContext>(0);
}

tree::TerminalNode* ZCodeParser::ParamsContext::COMMA() {
  return getToken(ZCodeParser::COMMA, 0);
}

ZCodeParser::ParamsContext* ZCodeParser::ParamsContext::params() {
  return getRuleContext<ZCodeParser::ParamsContext>(0);
}


size_t ZCodeParser::ParamsContext::getRuleIndex() const {
  return ZCodeParser::RuleParams;
}


std::any ZCodeParser::ParamsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitParams(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::ParamsContext* ZCodeParser::params() {
  ParamsContext *_localctx = _tracker.createInstance<ParamsContext>(_ctx, getState());
  enterRule(_localctx, 12, ZCodeParser::RuleParams);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(145);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      param();
      setState(141);
      match(ZCodeParser::COMMA);
      setState(142);
      params();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(144);
      param();
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

//----------------- ParamContext ------------------------------------------------------------------

ZCodeParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::VartypeContext* ZCodeParser::ParamContext::vartype() {
  return getRuleContext<ZCodeParser::VartypeContext>(0);
}

tree::TerminalNode* ZCodeParser::ParamContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

tree::TerminalNode* ZCodeParser::ParamContext::LS() {
  return getToken(ZCodeParser::LS, 0);
}

ZCodeParser::Num_listContext* ZCodeParser::ParamContext::num_list() {
  return getRuleContext<ZCodeParser::Num_listContext>(0);
}

tree::TerminalNode* ZCodeParser::ParamContext::RS() {
  return getToken(ZCodeParser::RS, 0);
}


size_t ZCodeParser::ParamContext::getRuleIndex() const {
  return ZCodeParser::RuleParam;
}


std::any ZCodeParser::ParamContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitParam(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::ParamContext* ZCodeParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 14, ZCodeParser::RuleParam);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(156);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(147);
      vartype();
      setState(148);
      match(ZCodeParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(150);
      vartype();
      setState(151);
      match(ZCodeParser::ID);
      setState(152);
      match(ZCodeParser::LS);
      setState(153);
      num_list();
      setState(154);
      match(ZCodeParser::RS);
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

//----------------- StmtContext ------------------------------------------------------------------

ZCodeParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::Var_declContext* ZCodeParser::StmtContext::var_decl() {
  return getRuleContext<ZCodeParser::Var_declContext>(0);
}

ZCodeParser::If_stmtContext* ZCodeParser::StmtContext::if_stmt() {
  return getRuleContext<ZCodeParser::If_stmtContext>(0);
}

ZCodeParser::Assign_stmtContext* ZCodeParser::StmtContext::assign_stmt() {
  return getRuleContext<ZCodeParser::Assign_stmtContext>(0);
}

ZCodeParser::For_stmtContext* ZCodeParser::StmtContext::for_stmt() {
  return getRuleContext<ZCodeParser::For_stmtContext>(0);
}

ZCodeParser::Break_stmtContext* ZCodeParser::StmtContext::break_stmt() {
  return getRuleContext<ZCodeParser::Break_stmtContext>(0);
}

ZCodeParser::Continue_stmtContext* ZCodeParser::StmtContext::continue_stmt() {
  return getRuleContext<ZCodeParser::Continue_stmtContext>(0);
}

ZCodeParser::Func_call_stmtContext* ZCodeParser::StmtContext::func_call_stmt() {
  return getRuleContext<ZCodeParser::Func_call_stmtContext>(0);
}

ZCodeParser::Return_stmtContext* ZCodeParser::StmtContext::return_stmt() {
  return getRuleContext<ZCodeParser::Return_stmtContext>(0);
}

ZCodeParser::Block_stmtContext* ZCodeParser::StmtContext::block_stmt() {
  return getRuleContext<ZCodeParser::Block_stmtContext>(0);
}


size_t ZCodeParser::StmtContext::getRuleIndex() const {
  return ZCodeParser::RuleStmt;
}


std::any ZCodeParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::StmtContext* ZCodeParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 16, ZCodeParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(158);
      var_decl();
      break;
    }

    case 2: {
      setState(159);
      if_stmt();
      break;
    }

    case 3: {
      setState(160);
      assign_stmt();
      break;
    }

    case 4: {
      setState(161);
      for_stmt();
      break;
    }

    case 5: {
      setState(162);
      break_stmt();
      break;
    }

    case 6: {
      setState(163);
      continue_stmt();
      break;
    }

    case 7: {
      setState(164);
      func_call_stmt();
      break;
    }

    case 8: {
      setState(165);
      return_stmt();
      break;
    }

    case 9: {
      setState(166);
      block_stmt();
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

//----------------- If_stmtContext ------------------------------------------------------------------

ZCodeParser::If_stmtContext::If_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::If_stmtContext::IF() {
  return getToken(ZCodeParser::IF, 0);
}

std::vector<tree::TerminalNode *> ZCodeParser::If_stmtContext::LR() {
  return getTokens(ZCodeParser::LR);
}

tree::TerminalNode* ZCodeParser::If_stmtContext::LR(size_t i) {
  return getToken(ZCodeParser::LR, i);
}

std::vector<ZCodeParser::ExprContext *> ZCodeParser::If_stmtContext::expr() {
  return getRuleContexts<ZCodeParser::ExprContext>();
}

ZCodeParser::ExprContext* ZCodeParser::If_stmtContext::expr(size_t i) {
  return getRuleContext<ZCodeParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> ZCodeParser::If_stmtContext::RR() {
  return getTokens(ZCodeParser::RR);
}

tree::TerminalNode* ZCodeParser::If_stmtContext::RR(size_t i) {
  return getToken(ZCodeParser::RR, i);
}

std::vector<ZCodeParser::StmtContext *> ZCodeParser::If_stmtContext::stmt() {
  return getRuleContexts<ZCodeParser::StmtContext>();
}

ZCodeParser::StmtContext* ZCodeParser::If_stmtContext::stmt(size_t i) {
  return getRuleContext<ZCodeParser::StmtContext>(i);
}

std::vector<tree::TerminalNode *> ZCodeParser::If_stmtContext::NEWLINE() {
  return getTokens(ZCodeParser::NEWLINE);
}

tree::TerminalNode* ZCodeParser::If_stmtContext::NEWLINE(size_t i) {
  return getToken(ZCodeParser::NEWLINE, i);
}

std::vector<tree::TerminalNode *> ZCodeParser::If_stmtContext::ELIF() {
  return getTokens(ZCodeParser::ELIF);
}

tree::TerminalNode* ZCodeParser::If_stmtContext::ELIF(size_t i) {
  return getToken(ZCodeParser::ELIF, i);
}

tree::TerminalNode* ZCodeParser::If_stmtContext::ELSE() {
  return getToken(ZCodeParser::ELSE, 0);
}


size_t ZCodeParser::If_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleIf_stmt;
}


std::any ZCodeParser::If_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitIf_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::If_stmtContext* ZCodeParser::if_stmt() {
  If_stmtContext *_localctx = _tracker.createInstance<If_stmtContext>(_ctx, getState());
  enterRule(_localctx, 18, ZCodeParser::RuleIf_stmt);
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
    setState(169);
    match(ZCodeParser::IF);
    setState(170);
    match(ZCodeParser::LR);
    setState(171);
    expr();
    setState(172);
    match(ZCodeParser::RR);
    setState(176);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ZCodeParser::NEWLINE) {
      setState(173);
      match(ZCodeParser::NEWLINE);
      setState(178);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(179);
    stmt();
    setState(196);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(181);
        match(ZCodeParser::NEWLINE);
        setState(182);
        match(ZCodeParser::ELIF);
        setState(183);
        match(ZCodeParser::LR);
        setState(184);
        expr();
        setState(185);
        match(ZCodeParser::RR);
        setState(189);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ZCodeParser::NEWLINE) {
          setState(186);
          match(ZCodeParser::NEWLINE);
          setState(191);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(192);
        stmt(); 
      }
      setState(198);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
    setState(202);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      setState(199);
      match(ZCodeParser::NEWLINE);
      setState(200);
      match(ZCodeParser::ELSE);
      setState(201);
      stmt();
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

//----------------- Assign_stmtContext ------------------------------------------------------------------

ZCodeParser::Assign_stmtContext::Assign_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::LhsContext* ZCodeParser::Assign_stmtContext::lhs() {
  return getRuleContext<ZCodeParser::LhsContext>(0);
}

tree::TerminalNode* ZCodeParser::Assign_stmtContext::REV_ARROW() {
  return getToken(ZCodeParser::REV_ARROW, 0);
}

ZCodeParser::ExprContext* ZCodeParser::Assign_stmtContext::expr() {
  return getRuleContext<ZCodeParser::ExprContext>(0);
}


size_t ZCodeParser::Assign_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleAssign_stmt;
}


std::any ZCodeParser::Assign_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitAssign_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Assign_stmtContext* ZCodeParser::assign_stmt() {
  Assign_stmtContext *_localctx = _tracker.createInstance<Assign_stmtContext>(_ctx, getState());
  enterRule(_localctx, 20, ZCodeParser::RuleAssign_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(204);
    lhs();
    setState(205);
    match(ZCodeParser::REV_ARROW);
    setState(206);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

ZCodeParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::LhsContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

ZCodeParser::Elem_arrayContext* ZCodeParser::LhsContext::elem_array() {
  return getRuleContext<ZCodeParser::Elem_arrayContext>(0);
}


size_t ZCodeParser::LhsContext::getRuleIndex() const {
  return ZCodeParser::RuleLhs;
}


std::any ZCodeParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::LhsContext* ZCodeParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 22, ZCodeParser::RuleLhs);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(210);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(208);
      match(ZCodeParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(209);
      elem_array();
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

//----------------- Elem_arrayContext ------------------------------------------------------------------

ZCodeParser::Elem_arrayContext::Elem_arrayContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Elem_arrayContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

tree::TerminalNode* ZCodeParser::Elem_arrayContext::LS() {
  return getToken(ZCodeParser::LS, 0);
}

ZCodeParser::Expr_listContext* ZCodeParser::Elem_arrayContext::expr_list() {
  return getRuleContext<ZCodeParser::Expr_listContext>(0);
}

tree::TerminalNode* ZCodeParser::Elem_arrayContext::RS() {
  return getToken(ZCodeParser::RS, 0);
}


size_t ZCodeParser::Elem_arrayContext::getRuleIndex() const {
  return ZCodeParser::RuleElem_array;
}


std::any ZCodeParser::Elem_arrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitElem_array(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Elem_arrayContext* ZCodeParser::elem_array() {
  Elem_arrayContext *_localctx = _tracker.createInstance<Elem_arrayContext>(_ctx, getState());
  enterRule(_localctx, 24, ZCodeParser::RuleElem_array);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(ZCodeParser::ID);
    setState(213);
    match(ZCodeParser::LS);
    setState(214);
    expr_list();
    setState(215);
    match(ZCodeParser::RS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_stmtContext ------------------------------------------------------------------

ZCodeParser::For_stmtContext::For_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::For_stmtContext::FOR() {
  return getToken(ZCodeParser::FOR, 0);
}

tree::TerminalNode* ZCodeParser::For_stmtContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

tree::TerminalNode* ZCodeParser::For_stmtContext::UNTIL() {
  return getToken(ZCodeParser::UNTIL, 0);
}

std::vector<ZCodeParser::ExprContext *> ZCodeParser::For_stmtContext::expr() {
  return getRuleContexts<ZCodeParser::ExprContext>();
}

ZCodeParser::ExprContext* ZCodeParser::For_stmtContext::expr(size_t i) {
  return getRuleContext<ZCodeParser::ExprContext>(i);
}

tree::TerminalNode* ZCodeParser::For_stmtContext::BY() {
  return getToken(ZCodeParser::BY, 0);
}

ZCodeParser::StmtContext* ZCodeParser::For_stmtContext::stmt() {
  return getRuleContext<ZCodeParser::StmtContext>(0);
}

std::vector<tree::TerminalNode *> ZCodeParser::For_stmtContext::NEWLINE() {
  return getTokens(ZCodeParser::NEWLINE);
}

tree::TerminalNode* ZCodeParser::For_stmtContext::NEWLINE(size_t i) {
  return getToken(ZCodeParser::NEWLINE, i);
}


size_t ZCodeParser::For_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleFor_stmt;
}


std::any ZCodeParser::For_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitFor_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::For_stmtContext* ZCodeParser::for_stmt() {
  For_stmtContext *_localctx = _tracker.createInstance<For_stmtContext>(_ctx, getState());
  enterRule(_localctx, 26, ZCodeParser::RuleFor_stmt);
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
    setState(217);
    match(ZCodeParser::FOR);
    setState(218);
    match(ZCodeParser::ID);
    setState(219);
    match(ZCodeParser::UNTIL);
    setState(220);
    expr();
    setState(221);
    match(ZCodeParser::BY);
    setState(222);
    expr();
    setState(226);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ZCodeParser::NEWLINE) {
      setState(223);
      match(ZCodeParser::NEWLINE);
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(229);
    stmt();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Break_stmtContext ------------------------------------------------------------------

ZCodeParser::Break_stmtContext::Break_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Break_stmtContext::BREAK() {
  return getToken(ZCodeParser::BREAK, 0);
}


size_t ZCodeParser::Break_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleBreak_stmt;
}


std::any ZCodeParser::Break_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitBreak_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Break_stmtContext* ZCodeParser::break_stmt() {
  Break_stmtContext *_localctx = _tracker.createInstance<Break_stmtContext>(_ctx, getState());
  enterRule(_localctx, 28, ZCodeParser::RuleBreak_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(231);
    match(ZCodeParser::BREAK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Continue_stmtContext ------------------------------------------------------------------

ZCodeParser::Continue_stmtContext::Continue_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Continue_stmtContext::CONTINUE() {
  return getToken(ZCodeParser::CONTINUE, 0);
}


size_t ZCodeParser::Continue_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleContinue_stmt;
}


std::any ZCodeParser::Continue_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitContinue_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Continue_stmtContext* ZCodeParser::continue_stmt() {
  Continue_stmtContext *_localctx = _tracker.createInstance<Continue_stmtContext>(_ctx, getState());
  enterRule(_localctx, 30, ZCodeParser::RuleContinue_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(ZCodeParser::CONTINUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Return_stmtContext ------------------------------------------------------------------

ZCodeParser::Return_stmtContext::Return_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Return_stmtContext::RETURN() {
  return getToken(ZCodeParser::RETURN, 0);
}

ZCodeParser::ExprContext* ZCodeParser::Return_stmtContext::expr() {
  return getRuleContext<ZCodeParser::ExprContext>(0);
}


size_t ZCodeParser::Return_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleReturn_stmt;
}


std::any ZCodeParser::Return_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitReturn_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Return_stmtContext* ZCodeParser::return_stmt() {
  Return_stmtContext *_localctx = _tracker.createInstance<Return_stmtContext>(_ctx, getState());
  enterRule(_localctx, 32, ZCodeParser::RuleReturn_stmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(ZCodeParser::RETURN);
    setState(237);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(236);
      expr();
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

//----------------- Func_call_stmtContext ------------------------------------------------------------------

ZCodeParser::Func_call_stmtContext::Func_call_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Func_call_stmtContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

tree::TerminalNode* ZCodeParser::Func_call_stmtContext::LR() {
  return getToken(ZCodeParser::LR, 0);
}

tree::TerminalNode* ZCodeParser::Func_call_stmtContext::RR() {
  return getToken(ZCodeParser::RR, 0);
}

ZCodeParser::Expr_listContext* ZCodeParser::Func_call_stmtContext::expr_list() {
  return getRuleContext<ZCodeParser::Expr_listContext>(0);
}


size_t ZCodeParser::Func_call_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleFunc_call_stmt;
}


std::any ZCodeParser::Func_call_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitFunc_call_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Func_call_stmtContext* ZCodeParser::func_call_stmt() {
  Func_call_stmtContext *_localctx = _tracker.createInstance<Func_call_stmtContext>(_ctx, getState());
  enterRule(_localctx, 34, ZCodeParser::RuleFunc_call_stmt);
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
    setState(239);
    match(ZCodeParser::ID);
    setState(240);
    match(ZCodeParser::LR);
    setState(242);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 31473545577984) != 0)) {
      setState(241);
      expr_list();
    }
    setState(244);
    match(ZCodeParser::RR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Block_stmtContext ------------------------------------------------------------------

ZCodeParser::Block_stmtContext::Block_stmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Block_stmtContext::BEGIN() {
  return getToken(ZCodeParser::BEGIN, 0);
}

tree::TerminalNode* ZCodeParser::Block_stmtContext::END() {
  return getToken(ZCodeParser::END, 0);
}

std::vector<tree::TerminalNode *> ZCodeParser::Block_stmtContext::NEWLINE() {
  return getTokens(ZCodeParser::NEWLINE);
}

tree::TerminalNode* ZCodeParser::Block_stmtContext::NEWLINE(size_t i) {
  return getToken(ZCodeParser::NEWLINE, i);
}

std::vector<ZCodeParser::StmtContext *> ZCodeParser::Block_stmtContext::stmt() {
  return getRuleContexts<ZCodeParser::StmtContext>();
}

ZCodeParser::StmtContext* ZCodeParser::Block_stmtContext::stmt(size_t i) {
  return getRuleContext<ZCodeParser::StmtContext>(i);
}


size_t ZCodeParser::Block_stmtContext::getRuleIndex() const {
  return ZCodeParser::RuleBlock_stmt;
}


std::any ZCodeParser::Block_stmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitBlock_stmt(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Block_stmtContext* ZCodeParser::block_stmt() {
  Block_stmtContext *_localctx = _tracker.createInstance<Block_stmtContext>(_ctx, getState());
  enterRule(_localctx, 36, ZCodeParser::RuleBlock_stmt);
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
    setState(246);
    match(ZCodeParser::BEGIN);
    setState(248); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(247);
              match(ZCodeParser::NEWLINE);
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(250); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
    setState(265);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 39582419974222) != 0)) {
      setState(255);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 4398047885390) != 0)) {
        setState(252);
        stmt();
        setState(257);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(259); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(258);
                match(ZCodeParser::NEWLINE);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(261); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(267);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(268);
    match(ZCodeParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

ZCodeParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ZCodeParser::Expr1Context *> ZCodeParser::ExprContext::expr1() {
  return getRuleContexts<ZCodeParser::Expr1Context>();
}

ZCodeParser::Expr1Context* ZCodeParser::ExprContext::expr1(size_t i) {
  return getRuleContext<ZCodeParser::Expr1Context>(i);
}

tree::TerminalNode* ZCodeParser::ExprContext::CONCAT() {
  return getToken(ZCodeParser::CONCAT, 0);
}


size_t ZCodeParser::ExprContext::getRuleIndex() const {
  return ZCodeParser::RuleExpr;
}


std::any ZCodeParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::ExprContext* ZCodeParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 38, ZCodeParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(275);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(270);
      expr1();
      setState(271);
      match(ZCodeParser::CONCAT);
      setState(272);
      expr1();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(274);
      expr1();
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

//----------------- Expr1Context ------------------------------------------------------------------

ZCodeParser::Expr1Context::Expr1Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ZCodeParser::Expr2Context *> ZCodeParser::Expr1Context::expr2() {
  return getRuleContexts<ZCodeParser::Expr2Context>();
}

ZCodeParser::Expr2Context* ZCodeParser::Expr1Context::expr2(size_t i) {
  return getRuleContext<ZCodeParser::Expr2Context>(i);
}

tree::TerminalNode* ZCodeParser::Expr1Context::EQ() {
  return getToken(ZCodeParser::EQ, 0);
}

tree::TerminalNode* ZCodeParser::Expr1Context::NOT_EQ() {
  return getToken(ZCodeParser::NOT_EQ, 0);
}

tree::TerminalNode* ZCodeParser::Expr1Context::LT() {
  return getToken(ZCodeParser::LT, 0);
}

tree::TerminalNode* ZCodeParser::Expr1Context::GT() {
  return getToken(ZCodeParser::GT, 0);
}

tree::TerminalNode* ZCodeParser::Expr1Context::LTE() {
  return getToken(ZCodeParser::LTE, 0);
}

tree::TerminalNode* ZCodeParser::Expr1Context::GTE() {
  return getToken(ZCodeParser::GTE, 0);
}

tree::TerminalNode* ZCodeParser::Expr1Context::STR_EQ() {
  return getToken(ZCodeParser::STR_EQ, 0);
}


size_t ZCodeParser::Expr1Context::getRuleIndex() const {
  return ZCodeParser::RuleExpr1;
}


std::any ZCodeParser::Expr1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr1(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Expr1Context* ZCodeParser::expr1() {
  Expr1Context *_localctx = _tracker.createInstance<Expr1Context>(_ctx, getState());
  enterRule(_localctx, 40, ZCodeParser::RuleExpr1);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(282);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(277);
      expr2(0);
      setState(278);
      _la = _input->LA(1);
      if (!((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 66303557632) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(279);
      expr2(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(281);
      expr2(0);
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

//----------------- Expr2Context ------------------------------------------------------------------

ZCodeParser::Expr2Context::Expr2Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::Expr3Context* ZCodeParser::Expr2Context::expr3() {
  return getRuleContext<ZCodeParser::Expr3Context>(0);
}

ZCodeParser::Expr2Context* ZCodeParser::Expr2Context::expr2() {
  return getRuleContext<ZCodeParser::Expr2Context>(0);
}

tree::TerminalNode* ZCodeParser::Expr2Context::AND() {
  return getToken(ZCodeParser::AND, 0);
}

tree::TerminalNode* ZCodeParser::Expr2Context::OR() {
  return getToken(ZCodeParser::OR, 0);
}


size_t ZCodeParser::Expr2Context::getRuleIndex() const {
  return ZCodeParser::RuleExpr2;
}


std::any ZCodeParser::Expr2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr2(this);
  else
    return visitor->visitChildren(this);
}


ZCodeParser::Expr2Context* ZCodeParser::expr2() {
   return expr2(0);
}

ZCodeParser::Expr2Context* ZCodeParser::expr2(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ZCodeParser::Expr2Context *_localctx = _tracker.createInstance<Expr2Context>(_ctx, parentState);
  ZCodeParser::Expr2Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, ZCodeParser::RuleExpr2, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(285);
    expr3(0);
    _ctx->stop = _input->LT(-1);
    setState(292);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Expr2Context>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr2);
        setState(287);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(288);
        _la = _input->LA(1);
        if (!(_la == ZCodeParser::AND

        || _la == ZCodeParser::OR)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(289);
        expr3(0); 
      }
      setState(294);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr3Context ------------------------------------------------------------------

ZCodeParser::Expr3Context::Expr3Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::Expr4Context* ZCodeParser::Expr3Context::expr4() {
  return getRuleContext<ZCodeParser::Expr4Context>(0);
}

ZCodeParser::Expr3Context* ZCodeParser::Expr3Context::expr3() {
  return getRuleContext<ZCodeParser::Expr3Context>(0);
}

tree::TerminalNode* ZCodeParser::Expr3Context::ADD() {
  return getToken(ZCodeParser::ADD, 0);
}

tree::TerminalNode* ZCodeParser::Expr3Context::SUB() {
  return getToken(ZCodeParser::SUB, 0);
}


size_t ZCodeParser::Expr3Context::getRuleIndex() const {
  return ZCodeParser::RuleExpr3;
}


std::any ZCodeParser::Expr3Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr3(this);
  else
    return visitor->visitChildren(this);
}


ZCodeParser::Expr3Context* ZCodeParser::expr3() {
   return expr3(0);
}

ZCodeParser::Expr3Context* ZCodeParser::expr3(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ZCodeParser::Expr3Context *_localctx = _tracker.createInstance<Expr3Context>(_ctx, parentState);
  ZCodeParser::Expr3Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, ZCodeParser::RuleExpr3, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(296);
    expr4(0);
    _ctx->stop = _input->LT(-1);
    setState(303);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Expr3Context>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr3);
        setState(298);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(299);
        _la = _input->LA(1);
        if (!(_la == ZCodeParser::ADD

        || _la == ZCodeParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(300);
        expr4(0); 
      }
      setState(305);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr4Context ------------------------------------------------------------------

ZCodeParser::Expr4Context::Expr4Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::Expr5Context* ZCodeParser::Expr4Context::expr5() {
  return getRuleContext<ZCodeParser::Expr5Context>(0);
}

ZCodeParser::Expr4Context* ZCodeParser::Expr4Context::expr4() {
  return getRuleContext<ZCodeParser::Expr4Context>(0);
}

tree::TerminalNode* ZCodeParser::Expr4Context::MUL() {
  return getToken(ZCodeParser::MUL, 0);
}

tree::TerminalNode* ZCodeParser::Expr4Context::DIV() {
  return getToken(ZCodeParser::DIV, 0);
}

tree::TerminalNode* ZCodeParser::Expr4Context::MOD() {
  return getToken(ZCodeParser::MOD, 0);
}


size_t ZCodeParser::Expr4Context::getRuleIndex() const {
  return ZCodeParser::RuleExpr4;
}


std::any ZCodeParser::Expr4Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr4(this);
  else
    return visitor->visitChildren(this);
}


ZCodeParser::Expr4Context* ZCodeParser::expr4() {
   return expr4(0);
}

ZCodeParser::Expr4Context* ZCodeParser::expr4(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ZCodeParser::Expr4Context *_localctx = _tracker.createInstance<Expr4Context>(_ctx, parentState);
  ZCodeParser::Expr4Context *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, ZCodeParser::RuleExpr4, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(307);
    expr5();
    _ctx->stop = _input->LT(-1);
    setState(314);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Expr4Context>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleExpr4);
        setState(309);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(310);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 234881024) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(311);
        expr5(); 
      }
      setState(316);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Expr5Context ------------------------------------------------------------------

ZCodeParser::Expr5Context::Expr5Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Expr5Context::NOT() {
  return getToken(ZCodeParser::NOT, 0);
}

ZCodeParser::Expr5Context* ZCodeParser::Expr5Context::expr5() {
  return getRuleContext<ZCodeParser::Expr5Context>(0);
}

ZCodeParser::Expr6Context* ZCodeParser::Expr5Context::expr6() {
  return getRuleContext<ZCodeParser::Expr6Context>(0);
}


size_t ZCodeParser::Expr5Context::getRuleIndex() const {
  return ZCodeParser::RuleExpr5;
}


std::any ZCodeParser::Expr5Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr5(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Expr5Context* ZCodeParser::expr5() {
  Expr5Context *_localctx = _tracker.createInstance<Expr5Context>(_ctx, getState());
  enterRule(_localctx, 48, ZCodeParser::RuleExpr5);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(320);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ZCodeParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(317);
        match(ZCodeParser::NOT);
        setState(318);
        expr5();
        break;
      }

      case ZCodeParser::TRUE:
      case ZCodeParser::FALSE:
      case ZCodeParser::ADD:
      case ZCodeParser::SUB:
      case ZCodeParser::LR:
      case ZCodeParser::LS:
      case ZCodeParser::ID:
      case ZCodeParser::NUM_LIT:
      case ZCodeParser::STR_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(319);
        expr6();
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

//----------------- Expr6Context ------------------------------------------------------------------

ZCodeParser::Expr6Context::Expr6Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::Expr6Context* ZCodeParser::Expr6Context::expr6() {
  return getRuleContext<ZCodeParser::Expr6Context>(0);
}

tree::TerminalNode* ZCodeParser::Expr6Context::ADD() {
  return getToken(ZCodeParser::ADD, 0);
}

tree::TerminalNode* ZCodeParser::Expr6Context::SUB() {
  return getToken(ZCodeParser::SUB, 0);
}

ZCodeParser::Expr7Context* ZCodeParser::Expr6Context::expr7() {
  return getRuleContext<ZCodeParser::Expr7Context>(0);
}


size_t ZCodeParser::Expr6Context::getRuleIndex() const {
  return ZCodeParser::RuleExpr6;
}


std::any ZCodeParser::Expr6Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr6(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Expr6Context* ZCodeParser::expr6() {
  Expr6Context *_localctx = _tracker.createInstance<Expr6Context>(_ctx, getState());
  enterRule(_localctx, 50, ZCodeParser::RuleExpr6);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(325);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ZCodeParser::ADD:
      case ZCodeParser::SUB: {
        enterOuterAlt(_localctx, 1);
        setState(322);
        _la = _input->LA(1);
        if (!(_la == ZCodeParser::ADD

        || _la == ZCodeParser::SUB)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(323);
        expr6();
        break;
      }

      case ZCodeParser::TRUE:
      case ZCodeParser::FALSE:
      case ZCodeParser::LR:
      case ZCodeParser::LS:
      case ZCodeParser::ID:
      case ZCodeParser::NUM_LIT:
      case ZCodeParser::STR_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(324);
        expr7();
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

//----------------- Expr7Context ------------------------------------------------------------------

ZCodeParser::Expr7Context::Expr7Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ZCodeParser::Array_cellContext* ZCodeParser::Expr7Context::array_cell() {
  return getRuleContext<ZCodeParser::Array_cellContext>(0);
}

ZCodeParser::OperandsContext* ZCodeParser::Expr7Context::operands() {
  return getRuleContext<ZCodeParser::OperandsContext>(0);
}


size_t ZCodeParser::Expr7Context::getRuleIndex() const {
  return ZCodeParser::RuleExpr7;
}


std::any ZCodeParser::Expr7Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr7(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Expr7Context* ZCodeParser::expr7() {
  Expr7Context *_localctx = _tracker.createInstance<Expr7Context>(_ctx, getState());
  enterRule(_localctx, 52, ZCodeParser::RuleExpr7);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(327);
      array_cell();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(328);
      operands();
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

//----------------- Array_cellContext ------------------------------------------------------------------

ZCodeParser::Array_cellContext::Array_cellContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Array_cellContext::LS() {
  return getToken(ZCodeParser::LS, 0);
}

ZCodeParser::Expr_listContext* ZCodeParser::Array_cellContext::expr_list() {
  return getRuleContext<ZCodeParser::Expr_listContext>(0);
}

tree::TerminalNode* ZCodeParser::Array_cellContext::RS() {
  return getToken(ZCodeParser::RS, 0);
}

tree::TerminalNode* ZCodeParser::Array_cellContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

ZCodeParser::Func_callContext* ZCodeParser::Array_cellContext::func_call() {
  return getRuleContext<ZCodeParser::Func_callContext>(0);
}


size_t ZCodeParser::Array_cellContext::getRuleIndex() const {
  return ZCodeParser::RuleArray_cell;
}


std::any ZCodeParser::Array_cellContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitArray_cell(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Array_cellContext* ZCodeParser::array_cell() {
  Array_cellContext *_localctx = _tracker.createInstance<Array_cellContext>(_ctx, getState());
  enterRule(_localctx, 54, ZCodeParser::RuleArray_cell);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(333);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(331);
      match(ZCodeParser::ID);
      break;
    }

    case 2: {
      setState(332);
      func_call();
      break;
    }

    default:
      break;
    }
    setState(335);
    match(ZCodeParser::LS);
    setState(336);
    expr_list();
    setState(337);
    match(ZCodeParser::RS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_callContext ------------------------------------------------------------------

ZCodeParser::Func_callContext::Func_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Func_callContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

tree::TerminalNode* ZCodeParser::Func_callContext::LR() {
  return getToken(ZCodeParser::LR, 0);
}

tree::TerminalNode* ZCodeParser::Func_callContext::RR() {
  return getToken(ZCodeParser::RR, 0);
}

ZCodeParser::Expr_listContext* ZCodeParser::Func_callContext::expr_list() {
  return getRuleContext<ZCodeParser::Expr_listContext>(0);
}


size_t ZCodeParser::Func_callContext::getRuleIndex() const {
  return ZCodeParser::RuleFunc_call;
}


std::any ZCodeParser::Func_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitFunc_call(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Func_callContext* ZCodeParser::func_call() {
  Func_callContext *_localctx = _tracker.createInstance<Func_callContext>(_ctx, getState());
  enterRule(_localctx, 56, ZCodeParser::RuleFunc_call);
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
    setState(339);
    match(ZCodeParser::ID);
    setState(340);
    match(ZCodeParser::LR);
    setState(342);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 31473545577984) != 0)) {
      setState(341);
      expr_list();
    }
    setState(344);
    match(ZCodeParser::RR);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandsContext ------------------------------------------------------------------

ZCodeParser::OperandsContext::OperandsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::OperandsContext::ID() {
  return getToken(ZCodeParser::ID, 0);
}

tree::TerminalNode* ZCodeParser::OperandsContext::LR() {
  return getToken(ZCodeParser::LR, 0);
}

ZCodeParser::ExprContext* ZCodeParser::OperandsContext::expr() {
  return getRuleContext<ZCodeParser::ExprContext>(0);
}

tree::TerminalNode* ZCodeParser::OperandsContext::RR() {
  return getToken(ZCodeParser::RR, 0);
}

ZCodeParser::LiteralsContext* ZCodeParser::OperandsContext::literals() {
  return getRuleContext<ZCodeParser::LiteralsContext>(0);
}

ZCodeParser::Func_callContext* ZCodeParser::OperandsContext::func_call() {
  return getRuleContext<ZCodeParser::Func_callContext>(0);
}


size_t ZCodeParser::OperandsContext::getRuleIndex() const {
  return ZCodeParser::RuleOperands;
}


std::any ZCodeParser::OperandsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitOperands(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::OperandsContext* ZCodeParser::operands() {
  OperandsContext *_localctx = _tracker.createInstance<OperandsContext>(_ctx, getState());
  enterRule(_localctx, 58, ZCodeParser::RuleOperands);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(353);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(346);
      match(ZCodeParser::ID);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(347);
      match(ZCodeParser::LR);
      setState(348);
      expr();
      setState(349);
      match(ZCodeParser::RR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(351);
      literals();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(352);
      func_call();
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

//----------------- LiteralsContext ------------------------------------------------------------------

ZCodeParser::LiteralsContext::LiteralsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::LiteralsContext::NUM_LIT() {
  return getToken(ZCodeParser::NUM_LIT, 0);
}

tree::TerminalNode* ZCodeParser::LiteralsContext::STR_LIT() {
  return getToken(ZCodeParser::STR_LIT, 0);
}

tree::TerminalNode* ZCodeParser::LiteralsContext::TRUE() {
  return getToken(ZCodeParser::TRUE, 0);
}

tree::TerminalNode* ZCodeParser::LiteralsContext::FALSE() {
  return getToken(ZCodeParser::FALSE, 0);
}

ZCodeParser::Array_litContext* ZCodeParser::LiteralsContext::array_lit() {
  return getRuleContext<ZCodeParser::Array_litContext>(0);
}


size_t ZCodeParser::LiteralsContext::getRuleIndex() const {
  return ZCodeParser::RuleLiterals;
}


std::any ZCodeParser::LiteralsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitLiterals(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::LiteralsContext* ZCodeParser::literals() {
  LiteralsContext *_localctx = _tracker.createInstance<LiteralsContext>(_ctx, getState());
  enterRule(_localctx, 60, ZCodeParser::RuleLiterals);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(360);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ZCodeParser::NUM_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(355);
        match(ZCodeParser::NUM_LIT);
        break;
      }

      case ZCodeParser::STR_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(356);
        match(ZCodeParser::STR_LIT);
        break;
      }

      case ZCodeParser::TRUE: {
        enterOuterAlt(_localctx, 3);
        setState(357);
        match(ZCodeParser::TRUE);
        break;
      }

      case ZCodeParser::FALSE: {
        enterOuterAlt(_localctx, 4);
        setState(358);
        match(ZCodeParser::FALSE);
        break;
      }

      case ZCodeParser::LS: {
        enterOuterAlt(_localctx, 5);
        setState(359);
        array_lit();
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

//----------------- Array_litContext ------------------------------------------------------------------

ZCodeParser::Array_litContext::Array_litContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ZCodeParser::Array_litContext::LS() {
  return getToken(ZCodeParser::LS, 0);
}

ZCodeParser::Expr_listContext* ZCodeParser::Array_litContext::expr_list() {
  return getRuleContext<ZCodeParser::Expr_listContext>(0);
}

tree::TerminalNode* ZCodeParser::Array_litContext::RS() {
  return getToken(ZCodeParser::RS, 0);
}


size_t ZCodeParser::Array_litContext::getRuleIndex() const {
  return ZCodeParser::RuleArray_lit;
}


std::any ZCodeParser::Array_litContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitArray_lit(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Array_litContext* ZCodeParser::array_lit() {
  Array_litContext *_localctx = _tracker.createInstance<Array_litContext>(_ctx, getState());
  enterRule(_localctx, 62, ZCodeParser::RuleArray_lit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    match(ZCodeParser::LS);
    setState(363);
    expr_list();
    setState(364);
    match(ZCodeParser::RS);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expr_listContext ------------------------------------------------------------------

ZCodeParser::Expr_listContext::Expr_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ZCodeParser::ExprContext *> ZCodeParser::Expr_listContext::expr() {
  return getRuleContexts<ZCodeParser::ExprContext>();
}

ZCodeParser::ExprContext* ZCodeParser::Expr_listContext::expr(size_t i) {
  return getRuleContext<ZCodeParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> ZCodeParser::Expr_listContext::COMMA() {
  return getTokens(ZCodeParser::COMMA);
}

tree::TerminalNode* ZCodeParser::Expr_listContext::COMMA(size_t i) {
  return getToken(ZCodeParser::COMMA, i);
}


size_t ZCodeParser::Expr_listContext::getRuleIndex() const {
  return ZCodeParser::RuleExpr_list;
}


std::any ZCodeParser::Expr_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ZCodeVisitor*>(visitor))
    return parserVisitor->visitExpr_list(this);
  else
    return visitor->visitChildren(this);
}

ZCodeParser::Expr_listContext* ZCodeParser::expr_list() {
  Expr_listContext *_localctx = _tracker.createInstance<Expr_listContext>(_ctx, getState());
  enterRule(_localctx, 64, ZCodeParser::RuleExpr_list);
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
    setState(366);
    expr();
    setState(371);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ZCodeParser::COMMA) {
      setState(367);
      match(ZCodeParser::COMMA);
      setState(368);
      expr();
      setState(373);
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

bool ZCodeParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 21: return expr2Sempred(antlrcpp::downCast<Expr2Context *>(context), predicateIndex);
    case 22: return expr3Sempred(antlrcpp::downCast<Expr3Context *>(context), predicateIndex);
    case 23: return expr4Sempred(antlrcpp::downCast<Expr4Context *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ZCodeParser::expr2Sempred(Expr2Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool ZCodeParser::expr3Sempred(Expr3Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool ZCodeParser::expr4Sempred(Expr4Context *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void ZCodeParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  zcodeParserInitialize();
#else
  ::antlr4::internal::call_once(zcodeParserOnceFlag, zcodeParserInitialize);
#endif
}

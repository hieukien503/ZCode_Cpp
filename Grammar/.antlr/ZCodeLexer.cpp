
#include "./lexererr.hpp"


// Generated from c:/Users/VOSTRO 3490/OneDrive/Desktop/ZCode/Grammar/ZCode.g4 by ANTLR 4.13.1


#include "ZCodeLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct ZCodeLexerStaticData final {
  ZCodeLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  ZCodeLexerStaticData(const ZCodeLexerStaticData&) = delete;
  ZCodeLexerStaticData(ZCodeLexerStaticData&&) = delete;
  ZCodeLexerStaticData& operator=(const ZCodeLexerStaticData&) = delete;
  ZCodeLexerStaticData& operator=(ZCodeLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag zcodelexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
ZCodeLexerStaticData *zcodelexerLexerStaticData = nullptr;

void zcodelexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (zcodelexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(zcodelexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<ZCodeLexerStaticData>(
    std::vector<std::string>{
      "BREAK", "CONTINUE", "IF", "ELSE", "ELIF", "FOR", "UNTIL", "BY", "TRUE", 
      "FALSE", "NUMBER", "BOOL", "STRING", "RETURN", "DYNAMIC", "NOT", "AND", 
      "VAR", "OR", "BEGIN", "END", "FUNC", "ADD", "SUB", "MUL", "DIV", "MOD", 
      "STR_EQ", "EQ", "NOT_EQ", "REV_ARROW", "LT", "LTE", "GT", "GTE", "CONCAT", 
      "LR", "RR", "LS", "RS", "COMMA", "ID", "DOT", "FInt", "FDec", "FExp", 
      "CHAR", "NUM_LIT", "STR_LIT", "NEWLINE", "CMT", "WS", "ERROR_CHAR", 
      "UNCLOSED_STRING", "ILLEGAL_ESCAPE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,50,377,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,1,0,1,0,1,0,1,
  	0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,3,1,3,1,3,
  	1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,
  	7,1,7,1,7,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,10,1,10,1,10,
  	1,10,1,10,1,10,1,10,1,11,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,13,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,
  	1,14,1,14,1,14,1,15,1,15,1,15,1,15,1,16,1,16,1,16,1,16,1,17,1,17,1,17,
  	1,17,1,18,1,18,1,18,1,19,1,19,1,19,1,19,1,19,1,19,1,20,1,20,1,20,1,20,
  	1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,23,1,23,1,24,1,24,1,25,1,25,1,26,
  	1,26,1,27,1,27,1,27,1,28,1,28,1,29,1,29,1,29,1,30,1,30,1,30,1,31,1,31,
  	1,32,1,32,1,32,1,33,1,33,1,34,1,34,1,34,1,35,1,35,1,35,1,35,1,36,1,36,
  	1,37,1,37,1,38,1,38,1,39,1,39,1,40,1,40,1,41,1,41,5,41,275,8,41,10,41,
  	12,41,278,9,41,1,42,1,42,1,43,4,43,283,8,43,11,43,12,43,284,1,44,1,44,
  	5,44,289,8,44,10,44,12,44,292,9,44,1,45,1,45,3,45,296,8,45,1,45,4,45,
  	299,8,45,11,45,12,45,300,1,46,1,46,1,46,1,46,1,46,3,46,308,8,46,1,47,
  	1,47,3,47,312,8,47,1,47,3,47,315,8,47,1,48,1,48,5,48,319,8,48,10,48,12,
  	48,322,9,48,1,48,1,48,1,48,1,49,3,49,328,8,49,1,49,1,49,1,49,1,50,1,50,
  	1,50,1,50,5,50,337,8,50,10,50,12,50,340,9,50,1,50,1,50,1,51,4,51,345,
  	8,51,11,51,12,51,346,1,51,1,51,1,52,1,52,1,52,1,53,1,53,5,53,356,8,53,
  	10,53,12,53,359,9,53,1,53,3,53,362,8,53,1,53,1,53,1,54,1,54,5,54,368,
  	8,54,10,54,12,54,371,9,54,1,54,1,54,1,54,1,54,1,54,0,0,55,1,1,3,2,5,3,
  	7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,29,15,31,16,
  	33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,26,53,27,55,
  	28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,75,38,77,39,
  	79,40,81,41,83,42,85,0,87,0,89,0,91,0,93,0,95,43,97,44,99,45,101,46,103,
  	47,105,48,107,49,109,50,1,0,9,3,0,65,90,95,95,97,122,4,0,48,57,65,90,
  	95,95,97,122,1,0,48,57,2,0,69,69,101,101,2,0,43,43,45,45,3,0,10,10,34,
  	34,92,92,7,0,39,39,92,92,98,98,102,102,110,110,114,114,116,116,2,0,10,
  	10,13,13,3,0,8,9,12,12,32,32,387,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,
  	0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,
  	0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,
  	0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,
  	39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,
  	0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,
  	0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,
  	71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,1,0,0,0,0,81,1,
  	0,0,0,0,83,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,0,101,1,0,0,
  	0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,1,111,1,0,0,
  	0,3,117,1,0,0,0,5,126,1,0,0,0,7,129,1,0,0,0,9,134,1,0,0,0,11,139,1,0,
  	0,0,13,143,1,0,0,0,15,149,1,0,0,0,17,152,1,0,0,0,19,157,1,0,0,0,21,163,
  	1,0,0,0,23,170,1,0,0,0,25,175,1,0,0,0,27,182,1,0,0,0,29,189,1,0,0,0,31,
  	197,1,0,0,0,33,201,1,0,0,0,35,205,1,0,0,0,37,209,1,0,0,0,39,212,1,0,0,
  	0,41,218,1,0,0,0,43,222,1,0,0,0,45,227,1,0,0,0,47,229,1,0,0,0,49,231,
  	1,0,0,0,51,233,1,0,0,0,53,235,1,0,0,0,55,237,1,0,0,0,57,240,1,0,0,0,59,
  	242,1,0,0,0,61,245,1,0,0,0,63,248,1,0,0,0,65,250,1,0,0,0,67,253,1,0,0,
  	0,69,255,1,0,0,0,71,258,1,0,0,0,73,262,1,0,0,0,75,264,1,0,0,0,77,266,
  	1,0,0,0,79,268,1,0,0,0,81,270,1,0,0,0,83,272,1,0,0,0,85,279,1,0,0,0,87,
  	282,1,0,0,0,89,286,1,0,0,0,91,293,1,0,0,0,93,307,1,0,0,0,95,309,1,0,0,
  	0,97,316,1,0,0,0,99,327,1,0,0,0,101,332,1,0,0,0,103,344,1,0,0,0,105,350,
  	1,0,0,0,107,353,1,0,0,0,109,365,1,0,0,0,111,112,5,98,0,0,112,113,5,114,
  	0,0,113,114,5,101,0,0,114,115,5,97,0,0,115,116,5,107,0,0,116,2,1,0,0,
  	0,117,118,5,99,0,0,118,119,5,111,0,0,119,120,5,110,0,0,120,121,5,116,
  	0,0,121,122,5,105,0,0,122,123,5,110,0,0,123,124,5,117,0,0,124,125,5,101,
  	0,0,125,4,1,0,0,0,126,127,5,105,0,0,127,128,5,102,0,0,128,6,1,0,0,0,129,
  	130,5,101,0,0,130,131,5,108,0,0,131,132,5,115,0,0,132,133,5,101,0,0,133,
  	8,1,0,0,0,134,135,5,101,0,0,135,136,5,108,0,0,136,137,5,105,0,0,137,138,
  	5,102,0,0,138,10,1,0,0,0,139,140,5,102,0,0,140,141,5,111,0,0,141,142,
  	5,114,0,0,142,12,1,0,0,0,143,144,5,117,0,0,144,145,5,110,0,0,145,146,
  	5,116,0,0,146,147,5,105,0,0,147,148,5,108,0,0,148,14,1,0,0,0,149,150,
  	5,98,0,0,150,151,5,121,0,0,151,16,1,0,0,0,152,153,5,116,0,0,153,154,5,
  	114,0,0,154,155,5,117,0,0,155,156,5,101,0,0,156,18,1,0,0,0,157,158,5,
  	102,0,0,158,159,5,97,0,0,159,160,5,108,0,0,160,161,5,115,0,0,161,162,
  	5,101,0,0,162,20,1,0,0,0,163,164,5,110,0,0,164,165,5,117,0,0,165,166,
  	5,109,0,0,166,167,5,98,0,0,167,168,5,101,0,0,168,169,5,114,0,0,169,22,
  	1,0,0,0,170,171,5,98,0,0,171,172,5,111,0,0,172,173,5,111,0,0,173,174,
  	5,108,0,0,174,24,1,0,0,0,175,176,5,115,0,0,176,177,5,116,0,0,177,178,
  	5,114,0,0,178,179,5,105,0,0,179,180,5,110,0,0,180,181,5,103,0,0,181,26,
  	1,0,0,0,182,183,5,114,0,0,183,184,5,101,0,0,184,185,5,116,0,0,185,186,
  	5,117,0,0,186,187,5,114,0,0,187,188,5,110,0,0,188,28,1,0,0,0,189,190,
  	5,100,0,0,190,191,5,121,0,0,191,192,5,110,0,0,192,193,5,97,0,0,193,194,
  	5,109,0,0,194,195,5,105,0,0,195,196,5,99,0,0,196,30,1,0,0,0,197,198,5,
  	110,0,0,198,199,5,111,0,0,199,200,5,116,0,0,200,32,1,0,0,0,201,202,5,
  	97,0,0,202,203,5,110,0,0,203,204,5,100,0,0,204,34,1,0,0,0,205,206,5,118,
  	0,0,206,207,5,97,0,0,207,208,5,114,0,0,208,36,1,0,0,0,209,210,5,111,0,
  	0,210,211,5,114,0,0,211,38,1,0,0,0,212,213,5,98,0,0,213,214,5,101,0,0,
  	214,215,5,103,0,0,215,216,5,105,0,0,216,217,5,110,0,0,217,40,1,0,0,0,
  	218,219,5,101,0,0,219,220,5,110,0,0,220,221,5,100,0,0,221,42,1,0,0,0,
  	222,223,5,102,0,0,223,224,5,117,0,0,224,225,5,110,0,0,225,226,5,99,0,
  	0,226,44,1,0,0,0,227,228,5,43,0,0,228,46,1,0,0,0,229,230,5,45,0,0,230,
  	48,1,0,0,0,231,232,5,42,0,0,232,50,1,0,0,0,233,234,5,47,0,0,234,52,1,
  	0,0,0,235,236,5,37,0,0,236,54,1,0,0,0,237,238,5,61,0,0,238,239,5,61,0,
  	0,239,56,1,0,0,0,240,241,5,61,0,0,241,58,1,0,0,0,242,243,5,33,0,0,243,
  	244,5,61,0,0,244,60,1,0,0,0,245,246,5,60,0,0,246,247,5,45,0,0,247,62,
  	1,0,0,0,248,249,5,60,0,0,249,64,1,0,0,0,250,251,5,60,0,0,251,252,5,61,
  	0,0,252,66,1,0,0,0,253,254,5,62,0,0,254,68,1,0,0,0,255,256,5,62,0,0,256,
  	257,5,61,0,0,257,70,1,0,0,0,258,259,5,46,0,0,259,260,5,46,0,0,260,261,
  	5,46,0,0,261,72,1,0,0,0,262,263,5,40,0,0,263,74,1,0,0,0,264,265,5,41,
  	0,0,265,76,1,0,0,0,266,267,5,91,0,0,267,78,1,0,0,0,268,269,5,93,0,0,269,
  	80,1,0,0,0,270,271,5,44,0,0,271,82,1,0,0,0,272,276,7,0,0,0,273,275,7,
  	1,0,0,274,273,1,0,0,0,275,278,1,0,0,0,276,274,1,0,0,0,276,277,1,0,0,0,
  	277,84,1,0,0,0,278,276,1,0,0,0,279,280,5,46,0,0,280,86,1,0,0,0,281,283,
  	7,2,0,0,282,281,1,0,0,0,283,284,1,0,0,0,284,282,1,0,0,0,284,285,1,0,0,
  	0,285,88,1,0,0,0,286,290,3,85,42,0,287,289,7,2,0,0,288,287,1,0,0,0,289,
  	292,1,0,0,0,290,288,1,0,0,0,290,291,1,0,0,0,291,90,1,0,0,0,292,290,1,
  	0,0,0,293,295,7,3,0,0,294,296,7,4,0,0,295,294,1,0,0,0,295,296,1,0,0,0,
  	296,298,1,0,0,0,297,299,7,2,0,0,298,297,1,0,0,0,299,300,1,0,0,0,300,298,
  	1,0,0,0,300,301,1,0,0,0,301,92,1,0,0,0,302,308,8,5,0,0,303,304,5,92,0,
  	0,304,308,7,6,0,0,305,306,5,39,0,0,306,308,5,34,0,0,307,302,1,0,0,0,307,
  	303,1,0,0,0,307,305,1,0,0,0,308,94,1,0,0,0,309,311,3,87,43,0,310,312,
  	3,89,44,0,311,310,1,0,0,0,311,312,1,0,0,0,312,314,1,0,0,0,313,315,3,91,
  	45,0,314,313,1,0,0,0,314,315,1,0,0,0,315,96,1,0,0,0,316,320,5,34,0,0,
  	317,319,3,93,46,0,318,317,1,0,0,0,319,322,1,0,0,0,320,318,1,0,0,0,320,
  	321,1,0,0,0,321,323,1,0,0,0,322,320,1,0,0,0,323,324,5,34,0,0,324,325,
  	6,48,0,0,325,98,1,0,0,0,326,328,5,13,0,0,327,326,1,0,0,0,327,328,1,0,
  	0,0,328,329,1,0,0,0,329,330,5,10,0,0,330,331,6,49,1,0,331,100,1,0,0,0,
  	332,333,5,35,0,0,333,334,5,35,0,0,334,338,1,0,0,0,335,337,8,7,0,0,336,
  	335,1,0,0,0,337,340,1,0,0,0,338,336,1,0,0,0,338,339,1,0,0,0,339,341,1,
  	0,0,0,340,338,1,0,0,0,341,342,6,50,2,0,342,102,1,0,0,0,343,345,7,8,0,
  	0,344,343,1,0,0,0,345,346,1,0,0,0,346,344,1,0,0,0,346,347,1,0,0,0,347,
  	348,1,0,0,0,348,349,6,51,2,0,349,104,1,0,0,0,350,351,9,0,0,0,351,352,
  	6,52,3,0,352,106,1,0,0,0,353,357,5,34,0,0,354,356,3,93,46,0,355,354,1,
  	0,0,0,356,359,1,0,0,0,357,355,1,0,0,0,357,358,1,0,0,0,358,361,1,0,0,0,
  	359,357,1,0,0,0,360,362,5,10,0,0,361,360,1,0,0,0,361,362,1,0,0,0,362,
  	363,1,0,0,0,363,364,6,53,4,0,364,108,1,0,0,0,365,369,5,34,0,0,366,368,
  	3,93,46,0,367,366,1,0,0,0,368,371,1,0,0,0,369,367,1,0,0,0,369,370,1,0,
  	0,0,370,372,1,0,0,0,371,369,1,0,0,0,372,373,5,92,0,0,373,374,8,6,0,0,
  	374,375,1,0,0,0,375,376,6,54,5,0,376,110,1,0,0,0,16,0,276,284,290,295,
  	300,307,311,314,320,327,338,346,357,361,369,6,1,48,0,1,49,1,6,0,0,1,52,
  	2,1,53,3,1,54,4
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  zcodelexerLexerStaticData = staticData.release();
}

}

ZCodeLexer::ZCodeLexer(CharStream *input) : Lexer(input) {
  ZCodeLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *zcodelexerLexerStaticData->atn, zcodelexerLexerStaticData->decisionToDFA, zcodelexerLexerStaticData->sharedContextCache);
}

ZCodeLexer::~ZCodeLexer() {
  delete _interpreter;
}

std::string ZCodeLexer::getGrammarFileName() const {
  return "ZCode.g4";
}

const std::vector<std::string>& ZCodeLexer::getRuleNames() const {
  return zcodelexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& ZCodeLexer::getChannelNames() const {
  return zcodelexerLexerStaticData->channelNames;
}

const std::vector<std::string>& ZCodeLexer::getModeNames() const {
  return zcodelexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& ZCodeLexer::getVocabulary() const {
  return zcodelexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView ZCodeLexer::getSerializedATN() const {
  return zcodelexerLexerStaticData->serializedATN;
}

const atn::ATN& ZCodeLexer::getATN() const {
  return *zcodelexerLexerStaticData->atn;
}


void ZCodeLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 48: STR_LITAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 49: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 52: ERROR_CHARAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 53: UNCLOSED_STRINGAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 54: ILLEGAL_ESCAPEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

void ZCodeLexer::STR_LITAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: 
    this->_text = this->getText();
    this->_text.erase(this->_text.begin(), this->_text.begin() + 1);
    this->_text.pop_back();
     break;

  default:
    break;
  }
}

void ZCodeLexer::NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: this->_text = "\n"; break;

  default:
    break;
  }
}

void ZCodeLexer::ERROR_CHARAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: 
    throw ErrorToken(this->_text);
     break;

  default:
    break;
  }
}

void ZCodeLexer::UNCLOSED_STRINGAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3: 
    this->_text = this->getText();
    this->_text.erase(this->_text.begin(), this->_text.begin() + 1);
    if (this->_text.back() == '\n') {
        this->_text.pop_back();
        if ((int)this->_text.length() > 0 and this->_text.back() == '\r') {
            this->_text.pop_back();
        }
    }

    throw UncloseString(this->_text);
     break;

  default:
    break;
  }
}

void ZCodeLexer::ILLEGAL_ESCAPEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4: 
    this->_text = this->getText();
    this->_text.erase(this->_text.begin(), this->_text.begin() + 1);
    throw UncloseString(this->_text);
     break;

  default:
    break;
  }
}



void ZCodeLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  zcodelexerLexerInitialize();
#else
  ::antlr4::internal::call_once(zcodelexerLexerOnceFlag, zcodelexerLexerInitialize);
#endif
}

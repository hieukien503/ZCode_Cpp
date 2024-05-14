
#include "./lexererr.hpp"


// Generated from c:/Users/VOSTRO 3490/OneDrive/Desktop/ZCode/Grammar/ZCode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  ZCodeLexer : public antlr4::Lexer {
public:
  enum {
    BREAK = 1, CONTINUE = 2, IF = 3, ELSE = 4, ELIF = 5, FOR = 6, UNTIL = 7, 
    BY = 8, TRUE = 9, FALSE = 10, NUMBER = 11, BOOL = 12, STRING = 13, RETURN = 14, 
    DYNAMIC = 15, NOT = 16, AND = 17, VAR = 18, OR = 19, BEGIN = 20, END = 21, 
    FUNC = 22, ADD = 23, SUB = 24, MUL = 25, DIV = 26, MOD = 27, STR_EQ = 28, 
    EQ = 29, NOT_EQ = 30, REV_ARROW = 31, LT = 32, LTE = 33, GT = 34, GTE = 35, 
    CONCAT = 36, LR = 37, RR = 38, LS = 39, RS = 40, COMMA = 41, ID = 42, 
    NUM_LIT = 43, STR_LIT = 44, NEWLINE = 45, CMT = 46, WS = 47, ERROR_CHAR = 48, 
    UNCLOSED_STRING = 49, ILLEGAL_ESCAPE = 50
  };

  explicit ZCodeLexer(antlr4::CharStream *input);

  ~ZCodeLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  void action(antlr4::RuleContext *context, size_t ruleIndex, size_t actionIndex) override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.
  void STR_LITAction(antlr4::RuleContext *context, size_t actionIndex);
  void NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex);
  void ERROR_CHARAction(antlr4::RuleContext *context, size_t actionIndex);
  void UNCLOSED_STRINGAction(antlr4::RuleContext *context, size_t actionIndex);
  void ILLEGAL_ESCAPEAction(antlr4::RuleContext *context, size_t actionIndex);

  // Individual semantic predicate functions triggered by sempred() above.

};


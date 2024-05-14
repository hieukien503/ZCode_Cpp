
// Generated from ./Grammar/ZCode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"




class  ZCodeParser : public antlr4::Parser {
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

  enum {
    RuleProgram = 0, RuleDecl = 1, RuleVar_decl = 2, RuleNum_list = 3, RuleVartype = 4, 
    RuleFunc_decl = 5, RuleParams = 6, RuleParam = 7, RuleStmt = 8, RuleIf_stmt = 9, 
    RuleAssign_stmt = 10, RuleLhs = 11, RuleElem_array = 12, RuleFor_stmt = 13, 
    RuleBreak_stmt = 14, RuleContinue_stmt = 15, RuleReturn_stmt = 16, RuleFunc_call_stmt = 17, 
    RuleBlock_stmt = 18, RuleExpr = 19, RuleExpr1 = 20, RuleExpr2 = 21, 
    RuleExpr3 = 22, RuleExpr4 = 23, RuleExpr5 = 24, RuleExpr6 = 25, RuleExpr7 = 26, 
    RuleArray_cell = 27, RuleFunc_call = 28, RuleOperands = 29, RuleLiterals = 30, 
    RuleArray_lit = 31, RuleExpr_list = 32
  };

  explicit ZCodeParser(antlr4::TokenStream *input);

  ZCodeParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~ZCodeParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class DeclContext;
  class Var_declContext;
  class Num_listContext;
  class VartypeContext;
  class Func_declContext;
  class ParamsContext;
  class ParamContext;
  class StmtContext;
  class If_stmtContext;
  class Assign_stmtContext;
  class LhsContext;
  class Elem_arrayContext;
  class For_stmtContext;
  class Break_stmtContext;
  class Continue_stmtContext;
  class Return_stmtContext;
  class Func_call_stmtContext;
  class Block_stmtContext;
  class ExprContext;
  class Expr1Context;
  class Expr2Context;
  class Expr3Context;
  class Expr4Context;
  class Expr5Context;
  class Expr6Context;
  class Expr7Context;
  class Array_cellContext;
  class Func_callContext;
  class OperandsContext;
  class LiteralsContext;
  class Array_litContext;
  class Expr_listContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclContext *> decl();
    DeclContext* decl(size_t i);
    antlr4::tree::TerminalNode *EOF();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  DeclContext : public antlr4::ParserRuleContext {
  public:
    DeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declContext *var_decl();
    Func_declContext *func_decl();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclContext* decl();

  class  Var_declContext : public antlr4::ParserRuleContext {
  public:
    Var_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    VartypeContext *vartype();
    antlr4::tree::TerminalNode *DYNAMIC();
    antlr4::tree::TerminalNode *REV_ARROW();
    ExprContext *expr();
    antlr4::tree::TerminalNode *VAR();
    antlr4::tree::TerminalNode *LS();
    Num_listContext *num_list();
    antlr4::tree::TerminalNode *RS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_declContext* var_decl();

  class  Num_listContext : public antlr4::ParserRuleContext {
  public:
    Num_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM_LIT();
    antlr4::tree::TerminalNode *COMMA();
    Num_listContext *num_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Num_listContext* num_list();

  class  VartypeContext : public antlr4::ParserRuleContext {
  public:
    VartypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMBER();
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *STRING();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VartypeContext* vartype();

  class  Func_declContext : public antlr4::ParserRuleContext {
  public:
    Func_declContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LR();
    antlr4::tree::TerminalNode *RR();
    ParamsContext *params();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    Return_stmtContext *return_stmt();
    Block_stmtContext *block_stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_declContext* func_decl();

  class  ParamsContext : public antlr4::ParserRuleContext {
  public:
    ParamsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParamContext *param();
    antlr4::tree::TerminalNode *COMMA();
    ParamsContext *params();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamsContext* params();

  class  ParamContext : public antlr4::ParserRuleContext {
  public:
    ParamContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VartypeContext *vartype();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LS();
    Num_listContext *num_list();
    antlr4::tree::TerminalNode *RS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParamContext* param();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declContext *var_decl();
    If_stmtContext *if_stmt();
    Assign_stmtContext *assign_stmt();
    For_stmtContext *for_stmt();
    Break_stmtContext *break_stmt();
    Continue_stmtContext *continue_stmt();
    Func_call_stmtContext *func_call_stmt();
    Return_stmtContext *return_stmt();
    Block_stmtContext *block_stmt();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  If_stmtContext : public antlr4::ParserRuleContext {
  public:
    If_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    std::vector<antlr4::tree::TerminalNode *> LR();
    antlr4::tree::TerminalNode* LR(size_t i);
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RR();
    antlr4::tree::TerminalNode* RR(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ELIF();
    antlr4::tree::TerminalNode* ELIF(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_stmtContext* if_stmt();

  class  Assign_stmtContext : public antlr4::ParserRuleContext {
  public:
    Assign_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LhsContext *lhs();
    antlr4::tree::TerminalNode *REV_ARROW();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_stmtContext* assign_stmt();

  class  LhsContext : public antlr4::ParserRuleContext {
  public:
    LhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    Elem_arrayContext *elem_array();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LhsContext* lhs();

  class  Elem_arrayContext : public antlr4::ParserRuleContext {
  public:
    Elem_arrayContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LS();
    Expr_listContext *expr_list();
    antlr4::tree::TerminalNode *RS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Elem_arrayContext* elem_array();

  class  For_stmtContext : public antlr4::ParserRuleContext {
  public:
    For_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *UNTIL();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *BY();
    StmtContext *stmt();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_stmtContext* for_stmt();

  class  Break_stmtContext : public antlr4::ParserRuleContext {
  public:
    Break_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BREAK();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Break_stmtContext* break_stmt();

  class  Continue_stmtContext : public antlr4::ParserRuleContext {
  public:
    Continue_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONTINUE();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Continue_stmtContext* continue_stmt();

  class  Return_stmtContext : public antlr4::ParserRuleContext {
  public:
    Return_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *RETURN();
    ExprContext *expr();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Return_stmtContext* return_stmt();

  class  Func_call_stmtContext : public antlr4::ParserRuleContext {
  public:
    Func_call_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LR();
    antlr4::tree::TerminalNode *RR();
    Expr_listContext *expr_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_call_stmtContext* func_call_stmt();

  class  Block_stmtContext : public antlr4::ParserRuleContext {
  public:
    Block_stmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    antlr4::tree::TerminalNode *END();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Block_stmtContext* block_stmt();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr1Context *> expr1();
    Expr1Context* expr1(size_t i);
    antlr4::tree::TerminalNode *CONCAT();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();

  class  Expr1Context : public antlr4::ParserRuleContext {
  public:
    Expr1Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Expr2Context *> expr2();
    Expr2Context* expr2(size_t i);
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *NOT_EQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();
    antlr4::tree::TerminalNode *LTE();
    antlr4::tree::TerminalNode *GTE();
    antlr4::tree::TerminalNode *STR_EQ();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr1Context* expr1();

  class  Expr2Context : public antlr4::ParserRuleContext {
  public:
    Expr2Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr3Context *expr3();
    Expr2Context *expr2();
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr2Context* expr2();
  Expr2Context* expr2(int precedence);
  class  Expr3Context : public antlr4::ParserRuleContext {
  public:
    Expr3Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr4Context *expr4();
    Expr3Context *expr3();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr3Context* expr3();
  Expr3Context* expr3(int precedence);
  class  Expr4Context : public antlr4::ParserRuleContext {
  public:
    Expr4Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr5Context *expr5();
    Expr4Context *expr4();
    antlr4::tree::TerminalNode *MUL();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr4Context* expr4();
  Expr4Context* expr4(int precedence);
  class  Expr5Context : public antlr4::ParserRuleContext {
  public:
    Expr5Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    Expr5Context *expr5();
    Expr6Context *expr6();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr5Context* expr5();

  class  Expr6Context : public antlr4::ParserRuleContext {
  public:
    Expr6Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Expr6Context *expr6();
    antlr4::tree::TerminalNode *ADD();
    antlr4::tree::TerminalNode *SUB();
    Expr7Context *expr7();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr6Context* expr6();

  class  Expr7Context : public antlr4::ParserRuleContext {
  public:
    Expr7Context(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Array_cellContext *array_cell();
    OperandsContext *operands();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr7Context* expr7();

  class  Array_cellContext : public antlr4::ParserRuleContext {
  public:
    Array_cellContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LS();
    Expr_listContext *expr_list();
    antlr4::tree::TerminalNode *RS();
    antlr4::tree::TerminalNode *ID();
    Func_callContext *func_call();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_cellContext* array_cell();

  class  Func_callContext : public antlr4::ParserRuleContext {
  public:
    Func_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LR();
    antlr4::tree::TerminalNode *RR();
    Expr_listContext *expr_list();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Func_callContext* func_call();

  class  OperandsContext : public antlr4::ParserRuleContext {
  public:
    OperandsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LR();
    ExprContext *expr();
    antlr4::tree::TerminalNode *RR();
    LiteralsContext *literals();
    Func_callContext *func_call();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  OperandsContext* operands();

  class  LiteralsContext : public antlr4::ParserRuleContext {
  public:
    LiteralsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUM_LIT();
    antlr4::tree::TerminalNode *STR_LIT();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    Array_litContext *array_lit();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralsContext* literals();

  class  Array_litContext : public antlr4::ParserRuleContext {
  public:
    Array_litContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LS();
    Expr_listContext *expr_list();
    antlr4::tree::TerminalNode *RS();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_litContext* array_lit();

  class  Expr_listContext : public antlr4::ParserRuleContext {
  public:
    Expr_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Expr_listContext* expr_list();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expr2Sempred(Expr2Context *_localctx, size_t predicateIndex);
  bool expr3Sempred(Expr3Context *_localctx, size_t predicateIndex);
  bool expr4Sempred(Expr4Context *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};


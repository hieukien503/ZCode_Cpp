
// Generated from c:/Users/VOSTRO 3490/OneDrive/Desktop/ZCode/Grammar/ZCode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ZCodeParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ZCodeParser.
 */
class  ZCodeListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(ZCodeParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(ZCodeParser::ProgramContext *ctx) = 0;

  virtual void enterDecl(ZCodeParser::DeclContext *ctx) = 0;
  virtual void exitDecl(ZCodeParser::DeclContext *ctx) = 0;

  virtual void enterVar_decl(ZCodeParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(ZCodeParser::Var_declContext *ctx) = 0;

  virtual void enterNum_list(ZCodeParser::Num_listContext *ctx) = 0;
  virtual void exitNum_list(ZCodeParser::Num_listContext *ctx) = 0;

  virtual void enterVartype(ZCodeParser::VartypeContext *ctx) = 0;
  virtual void exitVartype(ZCodeParser::VartypeContext *ctx) = 0;

  virtual void enterFunc_decl(ZCodeParser::Func_declContext *ctx) = 0;
  virtual void exitFunc_decl(ZCodeParser::Func_declContext *ctx) = 0;

  virtual void enterParams(ZCodeParser::ParamsContext *ctx) = 0;
  virtual void exitParams(ZCodeParser::ParamsContext *ctx) = 0;

  virtual void enterParam(ZCodeParser::ParamContext *ctx) = 0;
  virtual void exitParam(ZCodeParser::ParamContext *ctx) = 0;

  virtual void enterStmt(ZCodeParser::StmtContext *ctx) = 0;
  virtual void exitStmt(ZCodeParser::StmtContext *ctx) = 0;

  virtual void enterIf_stmt(ZCodeParser::If_stmtContext *ctx) = 0;
  virtual void exitIf_stmt(ZCodeParser::If_stmtContext *ctx) = 0;

  virtual void enterAssign_stmt(ZCodeParser::Assign_stmtContext *ctx) = 0;
  virtual void exitAssign_stmt(ZCodeParser::Assign_stmtContext *ctx) = 0;

  virtual void enterLhs(ZCodeParser::LhsContext *ctx) = 0;
  virtual void exitLhs(ZCodeParser::LhsContext *ctx) = 0;

  virtual void enterElem_array(ZCodeParser::Elem_arrayContext *ctx) = 0;
  virtual void exitElem_array(ZCodeParser::Elem_arrayContext *ctx) = 0;

  virtual void enterFor_stmt(ZCodeParser::For_stmtContext *ctx) = 0;
  virtual void exitFor_stmt(ZCodeParser::For_stmtContext *ctx) = 0;

  virtual void enterBreak_stmt(ZCodeParser::Break_stmtContext *ctx) = 0;
  virtual void exitBreak_stmt(ZCodeParser::Break_stmtContext *ctx) = 0;

  virtual void enterContinue_stmt(ZCodeParser::Continue_stmtContext *ctx) = 0;
  virtual void exitContinue_stmt(ZCodeParser::Continue_stmtContext *ctx) = 0;

  virtual void enterReturn_stmt(ZCodeParser::Return_stmtContext *ctx) = 0;
  virtual void exitReturn_stmt(ZCodeParser::Return_stmtContext *ctx) = 0;

  virtual void enterFunc_call_stmt(ZCodeParser::Func_call_stmtContext *ctx) = 0;
  virtual void exitFunc_call_stmt(ZCodeParser::Func_call_stmtContext *ctx) = 0;

  virtual void enterBlock_stmt(ZCodeParser::Block_stmtContext *ctx) = 0;
  virtual void exitBlock_stmt(ZCodeParser::Block_stmtContext *ctx) = 0;

  virtual void enterExpr(ZCodeParser::ExprContext *ctx) = 0;
  virtual void exitExpr(ZCodeParser::ExprContext *ctx) = 0;

  virtual void enterExpr1(ZCodeParser::Expr1Context *ctx) = 0;
  virtual void exitExpr1(ZCodeParser::Expr1Context *ctx) = 0;

  virtual void enterExpr2(ZCodeParser::Expr2Context *ctx) = 0;
  virtual void exitExpr2(ZCodeParser::Expr2Context *ctx) = 0;

  virtual void enterExpr3(ZCodeParser::Expr3Context *ctx) = 0;
  virtual void exitExpr3(ZCodeParser::Expr3Context *ctx) = 0;

  virtual void enterExpr4(ZCodeParser::Expr4Context *ctx) = 0;
  virtual void exitExpr4(ZCodeParser::Expr4Context *ctx) = 0;

  virtual void enterExpr5(ZCodeParser::Expr5Context *ctx) = 0;
  virtual void exitExpr5(ZCodeParser::Expr5Context *ctx) = 0;

  virtual void enterExpr6(ZCodeParser::Expr6Context *ctx) = 0;
  virtual void exitExpr6(ZCodeParser::Expr6Context *ctx) = 0;

  virtual void enterExpr7(ZCodeParser::Expr7Context *ctx) = 0;
  virtual void exitExpr7(ZCodeParser::Expr7Context *ctx) = 0;

  virtual void enterArray_cell(ZCodeParser::Array_cellContext *ctx) = 0;
  virtual void exitArray_cell(ZCodeParser::Array_cellContext *ctx) = 0;

  virtual void enterFunc_call(ZCodeParser::Func_callContext *ctx) = 0;
  virtual void exitFunc_call(ZCodeParser::Func_callContext *ctx) = 0;

  virtual void enterOperands(ZCodeParser::OperandsContext *ctx) = 0;
  virtual void exitOperands(ZCodeParser::OperandsContext *ctx) = 0;

  virtual void enterLiterals(ZCodeParser::LiteralsContext *ctx) = 0;
  virtual void exitLiterals(ZCodeParser::LiteralsContext *ctx) = 0;

  virtual void enterArray_lit(ZCodeParser::Array_litContext *ctx) = 0;
  virtual void exitArray_lit(ZCodeParser::Array_litContext *ctx) = 0;

  virtual void enterExpr_list(ZCodeParser::Expr_listContext *ctx) = 0;
  virtual void exitExpr_list(ZCodeParser::Expr_listContext *ctx) = 0;


};


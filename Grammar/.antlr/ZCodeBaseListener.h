
// Generated from c:/Users/VOSTRO 3490/OneDrive/Desktop/ZCode/Grammar/ZCode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ZCodeListener.h"


/**
 * This class provides an empty implementation of ZCodeListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ZCodeBaseListener : public ZCodeListener {
public:

  virtual void enterProgram(ZCodeParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(ZCodeParser::ProgramContext * /*ctx*/) override { }

  virtual void enterDecl(ZCodeParser::DeclContext * /*ctx*/) override { }
  virtual void exitDecl(ZCodeParser::DeclContext * /*ctx*/) override { }

  virtual void enterVar_decl(ZCodeParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(ZCodeParser::Var_declContext * /*ctx*/) override { }

  virtual void enterNum_list(ZCodeParser::Num_listContext * /*ctx*/) override { }
  virtual void exitNum_list(ZCodeParser::Num_listContext * /*ctx*/) override { }

  virtual void enterVartype(ZCodeParser::VartypeContext * /*ctx*/) override { }
  virtual void exitVartype(ZCodeParser::VartypeContext * /*ctx*/) override { }

  virtual void enterFunc_decl(ZCodeParser::Func_declContext * /*ctx*/) override { }
  virtual void exitFunc_decl(ZCodeParser::Func_declContext * /*ctx*/) override { }

  virtual void enterParams(ZCodeParser::ParamsContext * /*ctx*/) override { }
  virtual void exitParams(ZCodeParser::ParamsContext * /*ctx*/) override { }

  virtual void enterParam(ZCodeParser::ParamContext * /*ctx*/) override { }
  virtual void exitParam(ZCodeParser::ParamContext * /*ctx*/) override { }

  virtual void enterStmt(ZCodeParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(ZCodeParser::StmtContext * /*ctx*/) override { }

  virtual void enterIf_stmt(ZCodeParser::If_stmtContext * /*ctx*/) override { }
  virtual void exitIf_stmt(ZCodeParser::If_stmtContext * /*ctx*/) override { }

  virtual void enterAssign_stmt(ZCodeParser::Assign_stmtContext * /*ctx*/) override { }
  virtual void exitAssign_stmt(ZCodeParser::Assign_stmtContext * /*ctx*/) override { }

  virtual void enterLhs(ZCodeParser::LhsContext * /*ctx*/) override { }
  virtual void exitLhs(ZCodeParser::LhsContext * /*ctx*/) override { }

  virtual void enterElem_array(ZCodeParser::Elem_arrayContext * /*ctx*/) override { }
  virtual void exitElem_array(ZCodeParser::Elem_arrayContext * /*ctx*/) override { }

  virtual void enterFor_stmt(ZCodeParser::For_stmtContext * /*ctx*/) override { }
  virtual void exitFor_stmt(ZCodeParser::For_stmtContext * /*ctx*/) override { }

  virtual void enterBreak_stmt(ZCodeParser::Break_stmtContext * /*ctx*/) override { }
  virtual void exitBreak_stmt(ZCodeParser::Break_stmtContext * /*ctx*/) override { }

  virtual void enterContinue_stmt(ZCodeParser::Continue_stmtContext * /*ctx*/) override { }
  virtual void exitContinue_stmt(ZCodeParser::Continue_stmtContext * /*ctx*/) override { }

  virtual void enterReturn_stmt(ZCodeParser::Return_stmtContext * /*ctx*/) override { }
  virtual void exitReturn_stmt(ZCodeParser::Return_stmtContext * /*ctx*/) override { }

  virtual void enterFunc_call_stmt(ZCodeParser::Func_call_stmtContext * /*ctx*/) override { }
  virtual void exitFunc_call_stmt(ZCodeParser::Func_call_stmtContext * /*ctx*/) override { }

  virtual void enterBlock_stmt(ZCodeParser::Block_stmtContext * /*ctx*/) override { }
  virtual void exitBlock_stmt(ZCodeParser::Block_stmtContext * /*ctx*/) override { }

  virtual void enterExpr(ZCodeParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(ZCodeParser::ExprContext * /*ctx*/) override { }

  virtual void enterExpr1(ZCodeParser::Expr1Context * /*ctx*/) override { }
  virtual void exitExpr1(ZCodeParser::Expr1Context * /*ctx*/) override { }

  virtual void enterExpr2(ZCodeParser::Expr2Context * /*ctx*/) override { }
  virtual void exitExpr2(ZCodeParser::Expr2Context * /*ctx*/) override { }

  virtual void enterExpr3(ZCodeParser::Expr3Context * /*ctx*/) override { }
  virtual void exitExpr3(ZCodeParser::Expr3Context * /*ctx*/) override { }

  virtual void enterExpr4(ZCodeParser::Expr4Context * /*ctx*/) override { }
  virtual void exitExpr4(ZCodeParser::Expr4Context * /*ctx*/) override { }

  virtual void enterExpr5(ZCodeParser::Expr5Context * /*ctx*/) override { }
  virtual void exitExpr5(ZCodeParser::Expr5Context * /*ctx*/) override { }

  virtual void enterExpr6(ZCodeParser::Expr6Context * /*ctx*/) override { }
  virtual void exitExpr6(ZCodeParser::Expr6Context * /*ctx*/) override { }

  virtual void enterExpr7(ZCodeParser::Expr7Context * /*ctx*/) override { }
  virtual void exitExpr7(ZCodeParser::Expr7Context * /*ctx*/) override { }

  virtual void enterArray_cell(ZCodeParser::Array_cellContext * /*ctx*/) override { }
  virtual void exitArray_cell(ZCodeParser::Array_cellContext * /*ctx*/) override { }

  virtual void enterFunc_call(ZCodeParser::Func_callContext * /*ctx*/) override { }
  virtual void exitFunc_call(ZCodeParser::Func_callContext * /*ctx*/) override { }

  virtual void enterOperands(ZCodeParser::OperandsContext * /*ctx*/) override { }
  virtual void exitOperands(ZCodeParser::OperandsContext * /*ctx*/) override { }

  virtual void enterLiterals(ZCodeParser::LiteralsContext * /*ctx*/) override { }
  virtual void exitLiterals(ZCodeParser::LiteralsContext * /*ctx*/) override { }

  virtual void enterArray_lit(ZCodeParser::Array_litContext * /*ctx*/) override { }
  virtual void exitArray_lit(ZCodeParser::Array_litContext * /*ctx*/) override { }

  virtual void enterExpr_list(ZCodeParser::Expr_listContext * /*ctx*/) override { }
  virtual void exitExpr_list(ZCodeParser::Expr_listContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};


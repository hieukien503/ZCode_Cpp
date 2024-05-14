
// Generated from ./Grammar/ZCode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ZCodeVisitor.h"


/**
 * This class provides an empty implementation of ZCodeVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ZCodeBaseVisitor : public ZCodeVisitor {
public:

  virtual std::any visitProgram(ZCodeParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDecl(ZCodeParser::DeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVar_decl(ZCodeParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNum_list(ZCodeParser::Num_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVartype(ZCodeParser::VartypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_decl(ZCodeParser::Func_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParams(ZCodeParser::ParamsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParam(ZCodeParser::ParamContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(ZCodeParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIf_stmt(ZCodeParser::If_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssign_stmt(ZCodeParser::Assign_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLhs(ZCodeParser::LhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitElem_array(ZCodeParser::Elem_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFor_stmt(ZCodeParser::For_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBreak_stmt(ZCodeParser::Break_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitContinue_stmt(ZCodeParser::Continue_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitReturn_stmt(ZCodeParser::Return_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_call_stmt(ZCodeParser::Func_call_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock_stmt(ZCodeParser::Block_stmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(ZCodeParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr1(ZCodeParser::Expr1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr2(ZCodeParser::Expr2Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr3(ZCodeParser::Expr3Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr4(ZCodeParser::Expr4Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr5(ZCodeParser::Expr5Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr6(ZCodeParser::Expr6Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr7(ZCodeParser::Expr7Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_cell(ZCodeParser::Array_cellContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunc_call(ZCodeParser::Func_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitOperands(ZCodeParser::OperandsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiterals(ZCodeParser::LiteralsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray_lit(ZCodeParser::Array_litContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr_list(ZCodeParser::Expr_listContext *ctx) override {
    return visitChildren(ctx);
  }


};


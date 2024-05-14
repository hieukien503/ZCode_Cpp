
// Generated from ./Grammar/ZCode.g4 by ANTLR 4.13.1

#pragma once


#include "antlr4-runtime.h"
#include "ZCodeParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ZCodeParser.
 */
class  ZCodeVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ZCodeParser.
   */
    virtual std::any visitProgram(ZCodeParser::ProgramContext *context) = 0;

    virtual std::any visitDecl(ZCodeParser::DeclContext *context) = 0;

    virtual std::any visitVar_decl(ZCodeParser::Var_declContext *context) = 0;

    virtual std::any visitNum_list(ZCodeParser::Num_listContext *context) = 0;

    virtual std::any visitVartype(ZCodeParser::VartypeContext *context) = 0;

    virtual std::any visitFunc_decl(ZCodeParser::Func_declContext *context) = 0;

    virtual std::any visitParams(ZCodeParser::ParamsContext *context) = 0;

    virtual std::any visitParam(ZCodeParser::ParamContext *context) = 0;

    virtual std::any visitStmt(ZCodeParser::StmtContext *context) = 0;

    virtual std::any visitIf_stmt(ZCodeParser::If_stmtContext *context) = 0;

    virtual std::any visitAssign_stmt(ZCodeParser::Assign_stmtContext *context) = 0;

    virtual std::any visitLhs(ZCodeParser::LhsContext *context) = 0;

    virtual std::any visitElem_array(ZCodeParser::Elem_arrayContext *context) = 0;

    virtual std::any visitFor_stmt(ZCodeParser::For_stmtContext *context) = 0;

    virtual std::any visitBreak_stmt(ZCodeParser::Break_stmtContext *context) = 0;

    virtual std::any visitContinue_stmt(ZCodeParser::Continue_stmtContext *context) = 0;

    virtual std::any visitReturn_stmt(ZCodeParser::Return_stmtContext *context) = 0;

    virtual std::any visitFunc_call_stmt(ZCodeParser::Func_call_stmtContext *context) = 0;

    virtual std::any visitBlock_stmt(ZCodeParser::Block_stmtContext *context) = 0;

    virtual std::any visitExpr(ZCodeParser::ExprContext *context) = 0;

    virtual std::any visitExpr1(ZCodeParser::Expr1Context *context) = 0;

    virtual std::any visitExpr2(ZCodeParser::Expr2Context *context) = 0;

    virtual std::any visitExpr3(ZCodeParser::Expr3Context *context) = 0;

    virtual std::any visitExpr4(ZCodeParser::Expr4Context *context) = 0;

    virtual std::any visitExpr5(ZCodeParser::Expr5Context *context) = 0;

    virtual std::any visitExpr6(ZCodeParser::Expr6Context *context) = 0;

    virtual std::any visitExpr7(ZCodeParser::Expr7Context *context) = 0;

    virtual std::any visitArray_cell(ZCodeParser::Array_cellContext *context) = 0;

    virtual std::any visitFunc_call(ZCodeParser::Func_callContext *context) = 0;

    virtual std::any visitOperands(ZCodeParser::OperandsContext *context) = 0;

    virtual std::any visitLiterals(ZCodeParser::LiteralsContext *context) = 0;

    virtual std::any visitArray_lit(ZCodeParser::Array_litContext *context) = 0;

    virtual std::any visitExpr_list(ZCodeParser::Expr_listContext *context) = 0;


};


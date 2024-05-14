#ifndef AST_GENERATION_HPP
#define AST_GENERATION_HPP

#pragma once

#include "./AST.hpp"
#include "../../Grammar/ZCodeParser.h"
#include "../../Grammar/ZCodeVisitor.h"

namespace zcode {
    class ASTGeneration: public ZCodeVisitor {
        std::any visitProgram(ZCodeParser::ProgramContext *ctx) override;
        std::any visitDecl(ZCodeParser::DeclContext *ctx) override;
        std::any visitVar_decl(ZCodeParser::Var_declContext *ctx);
        std::any visitNum_list(ZCodeParser::Num_listContext *ctx);
        std::any visitVartype(ZCodeParser::VartypeContext *ctx);
        std::any visitFunc_decl(ZCodeParser::Func_declContext *ctx);
        std::any visitParams(ZCodeParser::ParamsContext *ctx);
        std::any visitParam(ZCodeParser::ParamContext *ctx) override;
        std::any visitStmt(ZCodeParser::StmtContext *ctx) override;
        std::any visitIf_stmt(ZCodeParser::If_stmtContext *ctx) override;
        std::any visitAssign_stmt(ZCodeParser::Assign_stmtContext *ctx) override;
        std::any visitLhs(ZCodeParser::LhsContext *ctx) override;
        std::any visitElem_array(ZCodeParser::Elem_arrayContext *ctx) override;
        std::any visitFor_stmt(ZCodeParser::For_stmtContext *ctx) override;
        std::any visitBreak_stmt(ZCodeParser::Break_stmtContext *ctx) override;
        std::any visitContinue_stmt(ZCodeParser::Continue_stmtContext *ctx) override;
        std::any visitReturn_stmt(ZCodeParser::Return_stmtContext *ctx) override;
        std::any visitFunc_call_stmt(ZCodeParser::Func_call_stmtContext *ctx) override;
        std::any visitBlock_stmt(ZCodeParser::Block_stmtContext *ctx) override;
        std::any visitExpr(ZCodeParser::ExprContext *ctx) override;
        std::any visitExpr1(ZCodeParser::Expr1Context *ctx) override;
        std::any visitExpr2(ZCodeParser::Expr2Context *ctx) override;
        std::any visitExpr3(ZCodeParser::Expr3Context *ctx) override;
        std::any visitExpr4(ZCodeParser::Expr4Context *ctx) override;
        std::any visitExpr5(ZCodeParser::Expr5Context *ctx) override;
        std::any visitExpr6(ZCodeParser::Expr6Context *ctx) override;
        std::any visitExpr7(ZCodeParser::Expr7Context *ctx) override;
        std::any visitArray_cell(ZCodeParser::Array_cellContext *ctx) override;
        std::any visitFunc_call(ZCodeParser::Func_callContext *ctx) override;
        std::any visitOperands(ZCodeParser::OperandsContext *ctx) override;
        std::any visitLiterals(ZCodeParser::LiteralsContext *ctx) override;
        std::any visitArray_lit(ZCodeParser::Array_litContext *ctx) override;
        std::any visitExpr_list(ZCodeParser::Expr_listContext *ctx) override;
    };
}

#endif
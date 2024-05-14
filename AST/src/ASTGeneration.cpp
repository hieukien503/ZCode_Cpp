#include "../headers/AST.hpp"
#include "../headers/ASTGeneration.hpp"

namespace zcode {
    std::any ASTGeneration::visitProgram(ZCodeParser::ProgramContext *ctx) {
        std::vector<std::shared_ptr<Decl>> decls;
        for (const auto& decl: ctx->decl()) {
            decls.push_back(std::any_cast<std::shared_ptr<Decl>>(this->visit(decl)));
        }
        auto e = std::make_shared<Program>(decls);
        return e;
    }

    std::any ASTGeneration::visitDecl(ZCodeParser::DeclContext *ctx) {
        std::shared_ptr<Decl> decl;
        if (ctx->func_decl()) decl = std::any_cast<std::shared_ptr<FuncDecl>>(this->visit(ctx->func_decl()));
        else decl = std::any_cast<std::shared_ptr<VarDecl>>(this->visit(ctx->var_decl()));
        return decl;
    }

    std::any ASTGeneration::visitVar_decl(ZCodeParser::Var_declContext *ctx) {
        std::shared_ptr<Type> varType = (ctx->LS()? std::make_shared<ArrayType>(std::any_cast<std::vector<double>>(this->visit(ctx->num_list())), std::any_cast<std::shared_ptr<Type>>(this->visit(ctx->vartype()))) : (ctx->vartype()? std::any_cast<std::shared_ptr<Type>>(this->visit(ctx->vartype())) : nullptr));
        std::shared_ptr<Id> varName = std::make_shared<Id>(ctx->ID()->getText());
        std::string modifier = (ctx->VAR()? "var" : (ctx->DYNAMIC()? "dynamic" : ""));
        std::shared_ptr<Expr> varInit = (ctx->expr()? std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr())) : nullptr);
        return std::make_shared<VarDecl>(varName, modifier, varType, varInit);
    }

    std::any ASTGeneration::visitFunc_decl(ZCodeParser::Func_declContext *ctx) {
        std::shared_ptr<Id> varName = std::make_shared<Id>(ctx->ID()->getText());
        std::vector<std::shared_ptr<VarDecl>> params = (ctx->params()? std::any_cast<std::vector<std::shared_ptr<VarDecl>>> (this->visit(ctx->params())) : std::vector<std::shared_ptr<VarDecl>>());
        std::shared_ptr<Stmt> body = (ctx->return_stmt()? std::any_cast<std::shared_ptr<Stmt>>(this->visit(ctx->return_stmt())) : (ctx->block_stmt()? std::any_cast<std::shared_ptr<Stmt>>(this->visit(ctx->block_stmt())) : nullptr));
        return std::make_shared<FuncDecl>(varName, params, body);
    }

    std::any ASTGeneration::visitVartype(ZCodeParser::VartypeContext *ctx) {
        std::shared_ptr<Type> e;
        if (ctx->NUMBER()) e = std::make_shared<NumberType>();
        else if (ctx->STRING()) e = std::make_shared<StringType>();
        else e = std::make_shared<BoolType>();
        return e;
    }

    std::any ASTGeneration::visitParams(ZCodeParser::ParamsContext *ctx) {
        std::vector<std::shared_ptr<VarDecl>> params = std::vector<std::shared_ptr<VarDecl>> ({std::any_cast<std::shared_ptr<VarDecl>>(this->visit(ctx->param()))});
        if (ctx->params()) {
            std::vector<std::shared_ptr<VarDecl>> param = std::any_cast<std::vector<std::shared_ptr<VarDecl>>> (this->visit(ctx->params()));
            params.insert(params.end(), param.begin(), param.end());
        }

        return params;
    }

    std::any ASTGeneration::visitParam(ZCodeParser::ParamContext *ctx) {
        std::shared_ptr<Type> varType = (ctx->LS()? std::make_shared<ArrayType>(std::any_cast<std::vector<double>>(this->visit(ctx->num_list())), std::any_cast<std::shared_ptr<Type>>(this->visit(ctx->vartype()))) : std::any_cast<std::shared_ptr<Type>>(this->visit(ctx->vartype())));
        std::shared_ptr<Id> varName = std::make_shared<Id>(ctx->ID()->getText());
        return std::make_shared<VarDecl>(varName, "", varType, nullptr);
    }

    std::any ASTGeneration::visitNum_list(ZCodeParser::Num_listContext *ctx) {
        std::vector<double> numLists = {std::stod(ctx->NUM_LIT()->getText())};
        if (ctx->num_list()) {
            std::vector<double> numList = std::any_cast<std::vector<double>> (this->visit(ctx->num_list()));
            numLists.insert(numLists.end(), numList.begin(), numList.end());
        }

        return numLists;
    }

    std::any ASTGeneration::visitLiterals(ZCodeParser::LiteralsContext *ctx) {
        std::shared_ptr<Expr> e;
        if (ctx->array_lit()) e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->array_lit()));
        else if (ctx->NUM_LIT()) e = std::make_shared<NumberLiteral>(std::stod(ctx->NUM_LIT()->getText()));
        else if (ctx->STR_LIT()) e = std::make_shared<StringLiteral>(ctx->STR_LIT()->getText());
        else e = std::make_shared<BooleanLiteral>(ctx->TRUE()? true : false);
        return e;
    }

    std::any ASTGeneration::visitArray_lit(ZCodeParser::Array_litContext *ctx) {
        std::shared_ptr<Expr> e = std::make_shared<ArrayLiteral>(std::any_cast<std::vector<std::shared_ptr<Expr>>>(this->visit(ctx->expr_list())));
        return e;
    }

    std::any ASTGeneration::visitExpr_list(ZCodeParser::Expr_listContext *ctx) {
        std::vector<std::shared_ptr<Expr>> exprs;
        for (const auto& expr: ctx->expr()) {
            exprs.push_back(std::any_cast<std::shared_ptr<Expr>>(this->visit(expr)));
        }

        return exprs;
    }

    std::any ASTGeneration::visitStmt(ZCodeParser::StmtContext *ctx) {
        std::shared_ptr<Stmt> stmt;
        if (ctx->var_decl()) stmt = std::any_cast<std::shared_ptr<VarDecl>>(this->visit(ctx->var_decl()));
        else stmt = std::any_cast<std::shared_ptr<Stmt>>(this->visitChildren(ctx));
        return stmt;
    }

    std::any ASTGeneration::visitIf_stmt(ZCodeParser::If_stmtContext *ctx) {
        std::shared_ptr<Expr> condExpr = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr(0)));
        std::shared_ptr<Stmt> thenStmt = std::any_cast<std::shared_ptr<Stmt>>(this->visit(ctx->stmt(0)));
        std::vector<std::tuple<std::shared_ptr<Expr>, std::shared_ptr<Stmt>>> elifStmt = std::vector<std::tuple<std::shared_ptr<Expr>, std::shared_ptr<Stmt>>>();
        std::shared_ptr<Stmt> elseStmt = nullptr;
        for (int i = 1; i < (int)ctx->expr().size(); i++) {
            std::shared_ptr<Expr> e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr(i)));
            std::shared_ptr<Stmt> stmt = std::any_cast<std::shared_ptr<Stmt>>(this->visit(ctx->stmt(i)));
            elifStmt.push_back(std::tuple<std::shared_ptr<Expr>, std::shared_ptr<Stmt>>(e, stmt));
        }

        if ((int)ctx->expr().size() < (int)ctx->stmt().size()) {
            elseStmt = std::any_cast<std::shared_ptr<Stmt>>(this->visit(ctx->stmt().back()));
        }

        std::shared_ptr<Stmt> e = std::make_shared<If>(condExpr, thenStmt, elifStmt, elseStmt);
        return e;
    }

    std::any ASTGeneration::visitFor_stmt(ZCodeParser::For_stmtContext *ctx) {
        std::shared_ptr<Id> name = std::make_shared<Id>(ctx->ID()->getText());
        std::shared_ptr<Expr> condExpr = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr(0))), updExpr = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr(1)));
        std::shared_ptr<Stmt> body = std::any_cast<std::shared_ptr<Stmt>>(this->visit(ctx->stmt()));
        std::shared_ptr<Stmt> e = std::make_shared<For>(name, condExpr, updExpr, body);
        return e;
    }

    std::any ASTGeneration::visitAssign_stmt(ZCodeParser::Assign_stmtContext *ctx) {
        std::shared_ptr<Expr> lhs = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->lhs())), rhs = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr()));
        std::shared_ptr<Stmt> e = std::make_shared<Assign>(lhs, rhs);
        return e;
    }

    std::any ASTGeneration::visitBreak_stmt(ZCodeParser::Break_stmtContext *ctx) {
        std::shared_ptr<Stmt> e = std::make_shared<Break>();
        return e;
    }

    std::any ASTGeneration::visitContinue_stmt(ZCodeParser::Continue_stmtContext *ctx) {
        std::shared_ptr<Stmt> e = std::make_shared<Continue>();
        return e;
    }

    std::any ASTGeneration::visitReturn_stmt(ZCodeParser::Return_stmtContext *ctx) {
        std::shared_ptr<Stmt> e = std::make_shared<Return>(ctx->expr()? std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr())) : nullptr);
        return e;
    }

    std::any ASTGeneration::visitBlock_stmt(ZCodeParser::Block_stmtContext *ctx) {
        std::vector<std::shared_ptr<Stmt>> stmts;
        for (const auto& stmt: ctx->stmt()) {
            stmts.push_back(std::any_cast<std::shared_ptr<Stmt>>(this->visit(stmt)));
            
        }

        std::shared_ptr<Stmt> blockStmt = std::make_shared<Block>(stmts);
        return blockStmt;
    }

    std::any ASTGeneration::visitFunc_call_stmt(ZCodeParser::Func_call_stmtContext *ctx) {
        std::shared_ptr<Stmt> e = std::make_shared<CallStmt>(std::make_shared<Id>(ctx->ID()->getText()), ctx->expr_list()? std::any_cast<std::vector<std::shared_ptr<Expr>>>(this->visit(ctx->expr_list())) : std::vector<std::shared_ptr<Expr>>());
        return e;
    }

    std::any ASTGeneration::visitLhs(ZCodeParser::LhsContext *ctx) {
        std::shared_ptr<Expr> e;
        if (ctx->ID()) e = std::make_shared<Id>(ctx->ID()->getText());
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->elem_array()));
        return e;
    }

    std::any ASTGeneration::visitElem_array(ZCodeParser::Elem_arrayContext *ctx) {
        std::shared_ptr<Expr> e = std::make_shared<ArrayCell>(std::make_shared<Id>(ctx->ID()->getText()), std::any_cast<std::vector<std::shared_ptr<Expr>>>(this->visit(ctx->expr_list())));
        return e;
    }

    std::any ASTGeneration::visitExpr(ZCodeParser::ExprContext *ctx) {
        std::shared_ptr<Expr> e;
        if (ctx->CONCAT()) e = std::make_shared<BinaryOp>(ctx->CONCAT()->getText(), std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr1(0))), std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr1(1))));
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visitChildren(ctx));
        return e;
    }

    std::any ASTGeneration::visitExpr1(ZCodeParser::Expr1Context *ctx) {
        std::shared_ptr<Expr> e;
        bool hasOp = ctx->LT() or ctx->LTE() or ctx->GTE() or ctx->GT() or ctx->GTE() or ctx->EQ() or ctx->NOT_EQ() or ctx->STR_EQ();
        if (hasOp) {
            std::shared_ptr<Expr> e1 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr2(0))), e2 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr2(1)));
            if (ctx->LT()) e = std::make_shared<BinaryOp>(ctx->LT()->getText(), e1, e2);
            else if (ctx->LTE()) e = std::make_shared<BinaryOp>(ctx->LTE()->getText(), e1, e2);
            else if (ctx->GTE()) e = std::make_shared<BinaryOp>(ctx->GTE()->getText(), e1, e2);
            else if (ctx->GT()) e = std::make_shared<BinaryOp>(ctx->GT()->getText(), e1, e2);
            else if (ctx->EQ()) e = std::make_shared<BinaryOp>(ctx->EQ()->getText(), e1, e2);
            else if (ctx->NOT_EQ()) e = std::make_shared<BinaryOp>(ctx->NOT_EQ()->getText(), e1, e2);
            else e = std::make_shared<BinaryOp>(ctx->STR_EQ()->getText(), e1, e2);
        }

        else e = std::any_cast<std::shared_ptr<Expr>>(this->visitChildren(ctx));
        return e;
    }

    std::any ASTGeneration::visitExpr2(ZCodeParser::Expr2Context *ctx) {
        std::shared_ptr<Expr> e;
        bool hasOp = ctx->AND() or ctx->OR();
        if (hasOp) {
            std::shared_ptr<Expr> e1 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr2())), e2 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr3()));
            if (ctx->AND()) e = std::make_shared<BinaryOp>(ctx->AND()->getText(), e1, e2);
            else e = std::make_shared<BinaryOp>(ctx->OR()->getText(), e1, e2);
        }
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visitChildren(ctx));
        return e;
    }

    std::any ASTGeneration::visitExpr3(ZCodeParser::Expr3Context *ctx) {
        std::shared_ptr<Expr> e;
        bool hasOp = ctx->ADD() or ctx->SUB();
        if (hasOp) {
            std::shared_ptr<Expr> e1 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr3())), e2 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr4()));
            if (ctx->ADD()) e = std::make_shared<BinaryOp>(ctx->ADD()->getText(), e1, e2);
            else e = std::make_shared<BinaryOp>(ctx->SUB()->getText(), e1, e2);
        }
        
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visitChildren(ctx));
        return e;
    }

    std::any ASTGeneration::visitExpr4(ZCodeParser::Expr4Context *ctx) {
        std::shared_ptr<Expr> e;
        bool hasOp = ctx->MUL() or ctx->DIV() or ctx->MOD();
        if (hasOp) {
            std::shared_ptr<Expr> e1 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr4())), e2 = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr5()));
            if (ctx->MUL()) e = std::make_shared<BinaryOp>(ctx->MUL()->getText(), e1, e2);
            else if (ctx->DIV()) e = std::make_shared<BinaryOp>(ctx->DIV()->getText(), e1, e2);
            else e = std::make_shared<BinaryOp>(ctx->MOD()->getText(), e1, e2);
        } 
        
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visitChildren(ctx));
        return e;
    }

    std::any ASTGeneration::visitExpr5(ZCodeParser::Expr5Context *ctx) {
        bool hasOp = ctx->NOT();
        std::shared_ptr<Expr> e;
        if (ctx->NOT()) {
            std::shared_ptr<Expr> op = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr5()));
            e = std::make_shared<UnaryOp>(ctx->NOT()->getText(), op);
        }
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr6()));
        return e;
    }

    std::any ASTGeneration::visitExpr6(ZCodeParser::Expr6Context *ctx) {
        bool hasOp = ctx->ADD() or ctx->SUB();
        std::shared_ptr<Expr> e;
        if (hasOp) {
            std::shared_ptr<Expr> op = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr6()));
            if (ctx->ADD()) e = std::make_shared<UnaryOp>(ctx->ADD()->getText(), op);
            else e = std::make_shared<UnaryOp>(ctx->SUB()->getText(), op);
        }
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr7()));
        return e;
    }

    std::any ASTGeneration::visitExpr7(ZCodeParser::Expr7Context *ctx) {
        std::shared_ptr<Expr> e;
        if (ctx->array_cell()) e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->array_cell()));
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->operands()));
        return e;
    }

    std::any ASTGeneration::visitArray_cell(ZCodeParser::Array_cellContext *ctx) {
        std::shared_ptr<Expr> e;
        std::vector<std::shared_ptr<Expr>> exprs = std::any_cast<std::vector<std::shared_ptr<Expr>>>(this->visit(ctx->expr_list()));
        if (ctx->ID()) e = std::make_shared<ArrayCell>(std::make_shared<Id>(ctx->ID()->getText()), exprs);
        else e = std::make_shared<ArrayCell>(std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->func_call())), exprs);
        return e;
    }

    std::any ASTGeneration::visitFunc_call(ZCodeParser::Func_callContext *ctx) {
        std::shared_ptr<Expr> e = std::make_shared<CallExpr>(std::make_shared<Id>(ctx->ID()->getText()), ctx->expr_list()? std::any_cast<std::vector<std::shared_ptr<Expr>>>(this->visit(ctx->expr_list())) : std::vector<std::shared_ptr<Expr>>());
        return e;
    }

    std::any ASTGeneration::visitOperands(ZCodeParser::OperandsContext *ctx) {
        std::shared_ptr<Expr> e;
        if (ctx->ID()) e = std::make_shared<Id>(ctx->ID()->getText());
        else if (ctx->literals()) e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->literals()));
        else if (ctx->expr()) e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->expr()));
        else e = std::any_cast<std::shared_ptr<Expr>>(this->visit(ctx->func_call()));
        return e;
    }
}
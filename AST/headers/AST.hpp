#ifndef AST_HPP
#define AST_HPP

#pragma once
#include "../../main.hpp"

class Visitor;

namespace zcode {
    class AST {
    public:
        virtual std::any accept(Visitor* visitor) = 0;
        virtual operator std::string() const = 0;
    };

    class Decl: virtual public AST {

    };

    class Stmt: virtual public AST {

    };

    class Expr: virtual public AST {

    };

    class LHS: virtual public Expr {

    };

    class Type: virtual public AST {

    };

    class Id: public LHS {
    public:
        std::string name;
    
    public:
        Id(std::string name);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class BinaryOp: public Expr {
    public:
        std::shared_ptr<Expr> left, right;
        std::string op;
    
    public:
        BinaryOp(std::string op, std::shared_ptr<Expr> left, std::shared_ptr<Expr> right);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class UnaryOp: public Expr {
    public:
        std::shared_ptr<Expr> operand;
        std::string op;
    
    public:
        UnaryOp(std::string op, std::shared_ptr<Expr> operand);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class CallExpr: public Expr {
    public:
        std::shared_ptr<Id> name;
        std::vector<std::shared_ptr<Expr>> args;
    
    public:
        CallExpr(std::shared_ptr<Id> name, std::vector<std::shared_ptr<Expr>> args);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class ArrayCell: public LHS {
    public:
        std::shared_ptr<Expr> arr;
        std::vector<std::shared_ptr<Expr>> idx;
    
    public:
        ArrayCell(std::shared_ptr<Expr> name, std::vector<std::shared_ptr<Expr>> idx);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class Literal: public Expr {

    };

    class NumberLiteral: public Literal {
    public:
        double val;
    
    public:
        NumberLiteral(double val);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class BooleanLiteral: public Literal {
    public:
        bool val;
    
    public:
        BooleanLiteral(bool val);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class StringLiteral: public Literal {
    public:
        std::string val;
    
    public:
        StringLiteral(std::string val);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class ArrayLiteral: public Literal {
    public:
        std::vector<std::shared_ptr<Expr>> value;
    
    public:
        ArrayLiteral(std::vector<std::shared_ptr<Expr>> value);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class Assign: public Stmt {
    public:
        std::shared_ptr<Expr> lhs, exp;
    
    public:
        Assign(std::shared_ptr<Expr> lhs, std::shared_ptr<Expr> exp);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class If: public Stmt {
    public:
        std::shared_ptr<Expr> expr;
        std::shared_ptr<Stmt> thenStmt;
        std::vector<std::tuple<std::shared_ptr<Expr>, std::shared_ptr<Stmt>>> elifStmt;
        std::shared_ptr<Stmt> elseStmt;
    
    public:
        If(std::shared_ptr<Expr> expr, std::shared_ptr<Stmt> thenStmt, std::vector<std::tuple<std::shared_ptr<Expr>, std::shared_ptr<Stmt>>> elifStmt = {}, std::shared_ptr<Stmt> elseStmt = nullptr);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class For: public Stmt {
    public:
        std::shared_ptr<Id> name;
        std::shared_ptr<Expr> condExpr, updExpr;
        std::shared_ptr<Stmt> body;
    
    public:
        For(std::shared_ptr<Id> name, std::shared_ptr<Expr> condExpr, std::shared_ptr<Expr> updExpr, std::shared_ptr<Stmt> body);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class Break: public Stmt {
    public:
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class Continue: public Stmt {
    public:
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class Return: public Stmt {
    public:
        std::shared_ptr<Expr> expr;
    public:
        Return(std::shared_ptr<Expr> expr = nullptr);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class Block: public Stmt {
    public:
        std::vector<std::shared_ptr<Stmt>> stmt;
    
    public:
        Block(std::vector<std::shared_ptr<Stmt>> stmt = {});
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class CallStmt: public Stmt {
    public:
        std::shared_ptr<Id> name;
        std::vector<std::shared_ptr<Expr>> args;
    
    public:
        CallStmt(std::shared_ptr<Id> name, std::vector<std::shared_ptr<Expr>> args);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class VarDecl: public Decl, public Stmt {
    public:
        std::shared_ptr<Id> name;
        std::string modifier;
        std::shared_ptr<Type> varType;
        std::shared_ptr<Expr> varInit;
    
    public:
        VarDecl(std::shared_ptr<Id> name, std::string modifiler = "", std::shared_ptr<Type> varType = nullptr, std::shared_ptr<Expr> varInit = nullptr);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class FuncDecl: public Decl, public Stmt {
    public:
        std::shared_ptr<Id> name;
        std::vector<std::shared_ptr<VarDecl>> params;
        std::shared_ptr<Stmt> body;
    
    public:
        FuncDecl(std::shared_ptr<Id> name, std::vector<std::shared_ptr<VarDecl>> params = {}, std::shared_ptr<Stmt> body = nullptr);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class NumberType: public Type {
    public:
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class BoolType: public Type {
    public:
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class StringType: public Type {
    public:
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class VoidType: public Type {
    public:
        operator std::string() const;
        std::any accept(Visitor* v);
    };

    class ArrayType: public Type {
    public:
        std::vector<double> size;
        std::shared_ptr<Type> eleType;
    public:
        ArrayType(std::vector<double> size, std::shared_ptr<Type> eleType);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };

    class Program: public AST {
    public:
        std::vector<std::shared_ptr<Decl>> decls;

    public:
        Program(std::vector<std::shared_ptr<Decl>> decls);
        std::any accept(Visitor* v) override;
        operator std::string() const override;
    };
}

class Visitor {
public:
    std::any visit(std::shared_ptr<zcode::AST> ast) {
        return ast->accept(this);
    }

    virtual std::any visitNumberType(std::shared_ptr<zcode::NumberType> ast) = 0;
    virtual std::any visitBoolType(std::shared_ptr<zcode::BoolType> ast) = 0;
    virtual std::any visitStringType(std::shared_ptr<zcode::StringType> ast) = 0;
    virtual std::any visitArrayType(std::shared_ptr<zcode::ArrayType> ast) = 0;

    virtual std::any visitIf(std::shared_ptr<zcode::If> ast) = 0;
    virtual std::any visitFor(std::shared_ptr<zcode::For> ast) = 0;
    virtual std::any visitBreak(std::shared_ptr<zcode::Break> ast) = 0;
    virtual std::any visitContinue(std::shared_ptr<zcode::Continue> ast) = 0;
    virtual std::any visitReturn(std::shared_ptr<zcode::Return> ast) = 0;
    virtual std::any visitBlock(std::shared_ptr<zcode::Block> ast) = 0;
    virtual std::any visitAssign(std::shared_ptr<zcode::Assign> ast) = 0;
    virtual std::any visitCallStmt(std::shared_ptr<zcode::CallStmt> ast) = 0;

    virtual std::any visitNumberLiteral(std::shared_ptr<zcode::NumberLiteral> ast) = 0;
    virtual std::any visitBooleanLiteral(std::shared_ptr<zcode::BooleanLiteral> ast) = 0;
    virtual std::any visitStringLiteral(std::shared_ptr<zcode::StringLiteral> ast) = 0;
    virtual std::any visitArrayLiteral(std::shared_ptr<zcode::ArrayLiteral> ast) = 0;

    virtual std::any visitArrayCell(std::shared_ptr<zcode::ArrayCell> ast) = 0;
    virtual std::any visitCallExpr(std::shared_ptr<zcode::CallExpr> ast) = 0;
    virtual std::any visitUnaryOp(std::shared_ptr<zcode::UnaryOp> ast) = 0;
    virtual std::any visitBinaryOp(std::shared_ptr<zcode::BinaryOp> ast) = 0;
    virtual std::any visitId(std::shared_ptr<zcode::Id> ast) = 0;

    virtual std::any visitVarDecl(std::shared_ptr<zcode::VarDecl> ast) = 0;
    virtual std::any visitFuncDecl(std::shared_ptr<zcode::FuncDecl> ast) = 0;

    virtual std::any visitProgram(std::shared_ptr<zcode::Program> ast) = 0;
};

#endif
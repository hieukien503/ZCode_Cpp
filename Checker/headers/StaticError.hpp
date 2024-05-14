#ifndef STATIC_ERROR_HPP
#define STATIC_ERROR_HPP

#pragma once

#include "../../AST/headers/AST.hpp"

namespace zcode {
    class Kind {
    public:
        virtual operator std::string() const = 0;
    };

    class Identifier: public Kind {
    public:
        operator std::string() const;
    };

    class Variable: public Kind {
    public:
        operator std::string() const;
    };

    class Function: public Kind {
    public:
        operator std::string() const;
    };

    class Parameter: public Kind {
    public:
        operator std::string() const;
    };

    class StaticError: public std::exception {
    public:
        virtual const char* what() const throw() = 0;
    };

    class Redeclared: public StaticError {
    private:
        std::string msg;

    public:
        Redeclared(std::shared_ptr<Kind> kind, std::string name);
        const char* what() const throw();
    };

    class Undeclared: public StaticError {
    private:
        std::string msg;

    public:
        Undeclared(std::shared_ptr<Kind> kind, std::string name);
        const char* what() const throw();
    };

    class TypeMismatchInExpression: public StaticError {
    private:
        std::string msg;

    public:
        TypeMismatchInExpression(std::shared_ptr<Expr> expr);
        const char* what() const throw();
    };

    class TypeMismatchInStatement: public StaticError {
    private:
        std::string msg;

    public:
        TypeMismatchInStatement(std::shared_ptr<Stmt> stmt);
        const char* what() const throw();
    };

    class TypeCannotBeInferred: public StaticError {
    private:
        std::string msg;
        
    public:
        TypeCannotBeInferred(std::shared_ptr<Stmt> stmt);
        const char* what() const throw();
    };

    class InvalidArrayLiteral: public StaticError {
    private:
        std::string msg;

    public:
        InvalidArrayLiteral(std::shared_ptr<Expr> expr);
        const char* what() const throw();
    };

    class NotImplemented: public StaticError {
    private:
        std::string msg;

    public:
        NotImplemented(std::string name);
        const char* what() const throw();
    };

    class NoEntryPoint: public StaticError {
    public:
        const char* what() const throw();
    };

    class UnreachableStatement: public StaticError {
    private:
        std::string msg;

    public:
        UnreachableStatement(std::shared_ptr<Stmt> stmt);
        const char* what() const throw();
    };

    class MustInLoop: public StaticError {
    private:
        std::string msg;

    public:
        MustInLoop(std::shared_ptr<Stmt> stmt);
        const char* what() const throw();
    };

    class FunctionNotReturn: public StaticError {
    private:
        std::string msg;

    public:
        FunctionNotReturn(std::string name);
        const char* what() const throw();
    };
}

#endif
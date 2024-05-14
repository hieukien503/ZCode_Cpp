#include "../headers/StaticError.hpp"

namespace zcode {
    Identifier::operator std::string() const {
        return "Identifier";
    }

    Variable::operator std::string() const {
        return "Variable";
    }

    Parameter::operator std::string() const {
        return "Parameter";
    }

    Function::operator std::string() const {
        return "Function";
    }

    Redeclared::Redeclared (std::shared_ptr<Kind> kind, std::string name) {
        this->msg = "Redeclared " + std::string(*kind) + ": " + name;
    }

    const char* Redeclared::what() const throw() {
        return this->msg.c_str();
    }

    Undeclared::Undeclared (std::shared_ptr<Kind> kind, std::string name) {
        this->msg = "Undeclared " + std::string(*kind) + ": " + name;
    }

    const char* Undeclared::what() const throw() {
        return this->msg.c_str();
    }

    TypeMismatchInExpression::TypeMismatchInExpression (std::shared_ptr<Expr> expr) {
        this->msg = "Type Mismatch In Expression:\n" + std::string(*expr);
    }

    const char* TypeMismatchInExpression::what() const throw() {
        return this->msg.c_str();
    }

    TypeMismatchInStatement::TypeMismatchInStatement (std::shared_ptr<Stmt> stmt) {
        this->msg = "Type Mismatch In Statement:\n" + std::string(*stmt);
    }

    const char* TypeMismatchInStatement::what() const throw() {
        return this->msg.c_str();
    }

    TypeCannotBeInferred::TypeCannotBeInferred (std::shared_ptr<Stmt> stmt) {
        this->msg = "Type Cannot Be Inferred:\n" + std::string(*stmt);
    }

    const char* TypeCannotBeInferred::what() const throw() {
        return this->msg.c_str();
    }

    InvalidArrayLiteral::InvalidArrayLiteral (std::shared_ptr<Expr> expr) {
        this->msg = "Invalid Array Literal:\n" + std::string(*expr);
    }

    const char* InvalidArrayLiteral::what() const throw() {
        return this->msg.c_str();
    }

    NotImplemented::NotImplemented (std::string name) {
        this->msg = "No Function Definition: " + name;
    }

    const char* NotImplemented::what() const throw() {
        return this->msg.c_str();
    }

    const char* NoEntryPoint::what() const throw() {
        std::string msg = "No Entry Point";
        return msg.c_str();
    }

    UnreachableStatement::UnreachableStatement (std::shared_ptr<Stmt> stmt) {
        this->msg = "Unreachable Statement:\n" + std::string(*stmt);
    }

    const char* UnreachableStatement::what() const throw() {
        return this->msg.c_str();
    }

    MustInLoop::MustInLoop (std::shared_ptr<Stmt> stmt) {
        std::string val = "";
        if (typeid(*stmt).name() == typeid(Break).name()) {
            val = "Break";
        }
        else {
            val = "Continue";
        }
        this->msg = val + " Must In Loop";
    }

    const char* MustInLoop::what() const throw() {
        return this->msg.c_str();
    }

    FunctionNotReturn::FunctionNotReturn (std::string name) {
        this->msg = "Function Not Return: " + name;
    }

    const char* FunctionNotReturn::what() const throw() {
        return this->msg.c_str();
    }
}
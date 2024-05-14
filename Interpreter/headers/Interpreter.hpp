#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#pragma once
#include "../../AST/headers/AST.hpp"
#include "./Emitter.hpp"
#include "./Frame.hpp"

namespace zcode {
    class Val {
        
    };

    class CName: public Val {
    public:
        std::string value;
        CName(std::string value);
    };

    class Index: public Val {
        int value;
        Index(int val);
    };

    class MType {
    public:
        std::vector<std::shared_ptr<Type>> parType;
        std::shared_ptr<Type> rettype;
        MType(std::vector<std::shared_ptr<Type>> parType, std::shared_ptr<Type> rettype);
    };

    class Symbol {
    public:
        std::string name;
        MType mtype;
        std::shared_ptr<Val> value;
        Symbol(std::string name, MType mtype, std::shared_ptr<Val> value = nullptr);
    };

    class SubBody {
    public:
        Frame frame;
        std::vector<Symbol> sym;
        SubBody(Frame frame, std::vector<Symbol> sym);
    };

    class Access {
    public:
        Frame frame;
        std::vector<Symbol> sym;
        bool isLeft;
        Access(Frame frame, std::vector<Symbol> sym, bool isLeft);
    };

    class Interpreter {
    private:
        std::string libName;
        std::vector<Symbol> symbolTable;
        std::shared_ptr<AST> ast;
        std::string path;
        std::string className;
    
    public:
        Emitter emit;
        Interpreter(std::string libName = "io");
        void gen();
    };
}

#endif
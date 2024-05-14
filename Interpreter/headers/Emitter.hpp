#ifndef EMITTER_HPP
#define EMITTER_HPP

#pragma once

#include "./MachineCode.hpp"
#include "./Exception.hpp"
#include "../../AST/headers/AST.hpp"
#include "./Interpreter.hpp"

namespace zcode {
    class Emitter {
    private:
        std::string fileName;
        std::vector<std::string> buffer;
        JasminCode jvm;
    
    public:
        Emitter(std::string fileName);
        std::string getJVMType(std::variant<std::shared_ptr<Type>, MType, std::string> inType);
        std::string emitPUSHICONST(std::variant<int, std::string> in_, Frame& frame);
        std::string emitPUSHFCONST(std::string in_, Frame& frame);
        std::string emitPUSHCONST(std::string in_, std::shared_ptr<Type> typ, Frame& frame);
    };
}

#endif
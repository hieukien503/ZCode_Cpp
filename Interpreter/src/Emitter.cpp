#include "../headers/Emitter.hpp"
#include "../headers/Interpreter.hpp"

namespace zcode {
    Emitter::Emitter(std::string fileName) {
        this->fileName = fileName;
        this->buffer = {};
        this->jvm = JasminCode();
    }

    std::string Emitter::getJVMType(std::variant<std::shared_ptr<Type>, MType, std::string> inType) {
        if (std::holds_alternative<std::shared_ptr<Type>>(inType)) {
            std::shared_ptr<Type> e = std::get<0>(inType);
            if (typeid(*e).name() == typeid(StringType).name()) {
                return "Ljava/lang/String;";
            }

            else if (typeid(*e).name() == typeid(BoolType).name()) {
                return "Z";
            }

            else if (typeid(*e).name() == typeid(NumberType).name()) {
                return "F";
            }

            else if (typeid(*e).name() == typeid(VoidType).name()) {
                return "F";
            }

            else {
                std::shared_ptr<ArrayType> arrType = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(e.get())));
                std::string arr = "";
                for (int i = 0; i < (int)arrType->size.size(); i++) {
                    arr += "[";
                }   
                return arr + this->getJVMType(arrType->eleType);
            }
        }

        else if (std::holds_alternative<MType>(inType)) {
            MType e = std::get<1>(inType);
            std::string arr = "(";
            for (const auto& x: e.parType) {
                arr += this->getJVMType(x);
            }
            arr += ")" + this->getJVMType(e.rettype);
        }

        else {
            return std::get<2>(inType);
        }
    }

    std::string Emitter::emitPUSHICONST(std::variant<int, std::string> in_, Frame& frame) {
        frame.push();
        if (std::holds_alternative<int>(in_)) {
            int i = std::get<int>(in_);
            if (i >= -1 and i <= 5) {
                return this->jvm.emitICONST(i);
            }

            else if (i >= -128 and i <= 127) {
                return this->jvm.emitBIPUSH(i);
            }

            else if (i >= -32768 and i <= 32767) {
                return this->jvm.emitSIPUSH(i);
            }

            else {
                return this->jvm.emitLDC(std::to_string(i));
            }
        }

        else {
            std::string val = std::get<1>(in_);
            if (val == "true") {
                return this->emitPUSHICONST(1, frame);
            }

            else if (val == "false") {
                return this->emitPUSHICONST(0, frame);
            }

            else {
                throw IllegalOperandException(val);
            }
        }
    }

    std::string Emitter::emitPUSHFCONST(std::string in_, Frame& frame) {
        float f = std::stof(in_);
        std::stringstream ss;
        ss << std::setprecision(4) << f;
        std::string rst = ss.str();
        if (rst == "0.0" or rst == "1.0" or rst == "2.0") {
            return this->jvm.emitFCONST(rst);
        }

        else {
            return this->jvm.emitLDC(in_);
        }
    }

    std::string Emitter::emitPUSHCONST(std::string in_, std::shared_ptr<Type> typ, Frame& frame) {
        if (typeid(*typ).name() == typeid(NumberType).name()) {
            return this->emitPUSHFCONST(in_, frame);
        }

        else if (typeid(*typ).name() == typeid(StringType).name()) {
            frame.push();
            return this->jvm.emitLDC(in_);
        }

        else {
            throw IllegalOperandException(in_);
        }
    }
}
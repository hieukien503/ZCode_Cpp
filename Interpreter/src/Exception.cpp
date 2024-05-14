#include "../headers/Exception.hpp"

namespace zcode {
    IllegalOperandException::IllegalOperandException(std::string msg) {
        this->msg = "Illegal Operand: " + msg + "\n";
    }

    const char* IllegalOperandException::what() const throw() {
        return this->msg.c_str();
    }

    IllegalRuntimeException::IllegalRuntimeException(std::string msg) {
        this->msg = "Illegal Runtime: " + msg + "\n";
    }

    const char* IllegalOperandException::what() const throw() {
        return this->msg.c_str();
    }
}
#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#pragma once
#include "../../main.hpp"

namespace zcode {
    class IllegalOperandException: public std::exception {
    private:
        std::string msg;
        
    public:
        IllegalOperandException(std::string msg);
        const char* what() const throw();
    };

    class IllegalRuntimeException: public std::exception {
    private:
        std::string msg;

    public:
        IllegalRuntimeException(std::string msg);
        const char* what() const throw();
    };
}

#endif
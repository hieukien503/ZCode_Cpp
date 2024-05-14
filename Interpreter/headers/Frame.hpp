#ifndef FRAME_HPP
#define FRAME_HPP

#pragma once

#include "../../AST/headers/AST.hpp"
#include "./Exception.hpp"

namespace zcode {
    class Frame {
    private:
        int currIndex, maxIndex,currOpStackSize, maxOpStackSize;

    public:
        std::string name;
        std::shared_ptr<Type> return_type;
        int currentLabel;
        std::vector<int> startLabel, endLabel, indexLocal, conLabel, brkLabel;
        Frame(std::string name, std::shared_ptr<Type> return_type);
        int getCurrIdx();
        void setCurrIdx(int idx);
        int getNewLabel();
        void push();
        void pop();
        int getStackSize();
        int getMaxOpStackSize();
        void checkOpStack();
        void enterScope(bool isProc);
        void exitScope();
        int getStartLabel();
        int getEndLabel();
        int getNewIndex();
        int getMaxIndex();
        void enterLoop();
        void exitLoop();
        int getContinueLabel();
        int getBreakLabel();
    };
}

#endif
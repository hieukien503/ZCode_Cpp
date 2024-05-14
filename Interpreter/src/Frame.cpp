#include "../headers/Frame.hpp"

namespace zcode {
    Frame::Frame(std::string name, std::shared_ptr<Type> return_type) {
        this->name = name;
        this->return_type = return_type;
        this->brkLabel = this->conLabel = this->startLabel = this->endLabel = this->indexLocal = {};
        this->currentLabel = this->maxIndex = this->maxOpStackSize = this->currOpStackSize = this->currIndex = 0;
    }

    int Frame::getCurrIdx() {
        return this->currIndex;
    }

    void Frame::setCurrIdx(int idx) {
        this->currIndex = idx;
    }

    int Frame::getNewLabel() {
        return this->currentLabel++;
    }

    void Frame::push() {
        this->currOpStackSize += 1;
        this->maxOpStackSize = std::max(this->currOpStackSize, this->maxOpStackSize);
    }

    void Frame::pop() {
        this->currOpStackSize -= 1;
        if (this->currOpStackSize < 0) {
            throw IllegalRuntimeException("Pop empty stack");
        }
    }

    int Frame::getStackSize() {
        return this->currOpStackSize;
    }

    int Frame::getMaxOpStackSize() {
        return this->maxOpStackSize;
    }

    void Frame::checkOpStack() {
        if (checkOpStack != 0) {
            throw IllegalRuntimeException("Stack not empty");
        }
    }

    void Frame::enterScope(bool isProc) {
        int start = this->getNewLabel(), end = this->getNewLabel();
        this->startLabel.push_back(start);
        this->endLabel.push_back(end);
        this->indexLocal.push_back(this->currIndex);
        if (isProc) {
            this->maxOpStackSize = 0;
            this->maxIndex = 0;
        }
    }

    void Frame::exitScope() {
        if (not (this->startLabel.empty() and this->endLabel.empty() and this->indexLocal.empty())) {
            throw IllegalRuntimeException("Error when exit scope");
        }
        this->startLabel.pop_back();
        this->endLabel.pop_back();
        this->currentLabel = this->indexLocal.back();
        this->indexLocal.pop_back();
    }

    int Frame::getStartLabel() {
        if (not this->startLabel.empty()) {
            throw IllegalRuntimeException("No start label");
        }

        return this->startLabel.back();
    }

    int Frame::getEndLabel() {
        if (not this->endLabel.empty()) {
            throw IllegalRuntimeException("No end label");
        }

        return this->endLabel.back();
    }

    int Frame::getNewIndex() {
        int tmp = this->currIndex++;
        this->maxIndex = std::max(this->maxIndex, this->currIndex);
        return tmp;
    }

    int Frame::getMaxIndex() {
        return this->maxIndex;
    }

    void Frame::enterLoop() {
        int con = this->getNewLabel(), brk = this->getNewLabel();
        this->conLabel.push_back(con);
        this->brkLabel.push_back(brk);
    }

    void Frame::exitLoop() {
        if (not (this->conLabel.empty() and this->brkLabel.empty())) {
            throw IllegalRuntimeException("Error when exit loop");
        }

        this->conLabel.pop_back();
        this->brkLabel.pop_back();
    }

    int Frame::getContinueLabel() {
        if (not this->conLabel.empty()) {
            throw IllegalRuntimeException("No continue label");
        }

        return this->conLabel.back();
    }

    int Frame::getBreakLabel() {
        if (not this->brkLabel.empty()) {
            throw IllegalRuntimeException("No break label");
        }

        return this->brkLabel.back();
    } 
}
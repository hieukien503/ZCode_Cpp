#include "./AST/headers/AST.hpp"
#include "./Grammar/ZCodeLexer.h"
#include "./Grammar/ZCodeParser.h"
#include "./AST/headers/ASTGeneration.hpp"
#include "./Grammar/ConsoleErrorListener.h"
#include "./Grammar/Recognizer.h"
#include "./Checker/headers/StaticError.hpp"
#include "./Checker/headers/StaticChecker.hpp"

using namespace zcode;

class SyntaxException: public std::exception {
private:
    std::string msg;
public:
    SyntaxException(std::string msg) {
        this->msg = msg;
    }

    const char* what() const throw() {
        return this->msg.c_str();
    }
};

class NewErrorListener: public antlr4::ConsoleErrorListener {
public:
    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token * offendingSymbol, size_t line, size_t charPositionInLine, const std::string &msg, std::exception_ptr e) {
        throw SyntaxException("Error on line " + std::to_string(line) + ", col " + std::to_string(charPositionInLine) + ": " + offendingSymbol->getText());
    }
};

int main() {
    std::ifstream stream("./main.zc");
    antlr4::ANTLRInputStream input(stream);
    try {
        ZCodeLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);
        ZCodeParser parser(&tokens);
        NewErrorListener listener = NewErrorListener();
        parser.removeErrorListeners();
        parser.addErrorListener(&listener);
        antlr4::tree::ParseTree* tree = parser.program();
        std::shared_ptr<AST> astTree = std::any_cast<std::shared_ptr<Program>>(ASTGeneration().visit(tree));
        StaticChecker checker = StaticChecker(astTree);
        checker.check();
        std::cout << "Success";
    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
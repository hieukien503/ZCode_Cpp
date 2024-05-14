#include "../../AST/headers/AST.hpp"
#include "./StaticError.hpp"

namespace zcode {
    class Symbol {
    public:
        virtual operator std::string() const = 0;
    };

    class Utils {
    public:
        std::shared_ptr<Symbol> lookup(const std::string& name, const std::vector<std::shared_ptr<Symbol>>& v, std::string (*f)(std::shared_ptr<Symbol> x));
    };

    class VarSym: public Symbol {
    public:
        std::string name;
        std::shared_ptr<Type> typ;
    public:
        VarSym(std::string name, std::shared_ptr<Type> typ = nullptr);
        operator std::string() const;
    };

    class FuncSym: public Symbol {
    public:
        std::string name;
        std::vector<std::shared_ptr<VarSym>> params;
        std::shared_ptr<Type> typ;
        std::shared_ptr<Stmt> body;
    public:
        FuncSym(std::string name, std::vector<std::shared_ptr<VarSym>> params = {}, std::shared_ptr<Type> typ = nullptr, std::shared_ptr<Stmt> body = nullptr);
        operator std::string() const;
    };

    class StaticChecker: public Visitor, public Utils {
    public:
        std::shared_ptr<AST> ast;
        std::vector<std::vector<std::shared_ptr<Symbol>>> symTable;
        bool has_return;
        std::string func_name;
        bool resolved;
        std::vector<std::shared_ptr<FuncDecl>> no_body;
        std::vector<int> in_loop;
        std::vector<std::shared_ptr<Return>> return_list;
        std::vector<std::shared_ptr<ArrayLiteral>> arr_ast;
        std::string curr_var_name;
        int scope;
    
    private:
        void resolve_type(std::shared_ptr<Expr> expr, std::shared_ptr<Type> typeToResolve);
        void resolve_typeCallStmt(std::shared_ptr<CallStmt> call_stmt);
    
    public:
        StaticChecker(std::shared_ptr<AST> ast);
        void check();

        std::any visitNumberType(std::shared_ptr<NumberType> ast);
        std::any visitBoolType(std::shared_ptr<BoolType> ast);
        std::any visitStringType(std::shared_ptr<StringType> ast);
        std::any visitArrayType(std::shared_ptr<ArrayType> ast);

        std::any visitIf(std::shared_ptr<If> ast);
        std::any visitFor(std::shared_ptr<For> ast);
        std::any visitBreak(std::shared_ptr<Break> ast);
        std::any visitContinue(std::shared_ptr<Continue> ast);
        std::any visitReturn(std::shared_ptr<Return> ast);
        std::any visitBlock(std::shared_ptr<Block> ast);
        std::any visitAssign(std::shared_ptr<Assign> ast);
        std::any visitCallStmt(std::shared_ptr<CallStmt> ast);

        std::any visitNumberLiteral(std::shared_ptr<NumberLiteral> ast);
        std::any visitBooleanLiteral(std::shared_ptr<BooleanLiteral> ast);
        std::any visitStringLiteral(std::shared_ptr<StringLiteral> ast);
        std::any visitArrayLiteral(std::shared_ptr<ArrayLiteral> ast);

        std::any visitArrayCell(std::shared_ptr<ArrayCell> ast);
        std::any visitCallExpr(std::shared_ptr<CallExpr> ast);
        std::any visitUnaryOp(std::shared_ptr<UnaryOp> ast);
        std::any visitBinaryOp(std::shared_ptr<BinaryOp> ast);
        std::any visitId(std::shared_ptr<Id> ast);

        std::any visitVarDecl(std::shared_ptr<VarDecl> ast);
        std::any visitFuncDecl(std::shared_ptr<FuncDecl> ast);

        std::any visitProgram(std::shared_ptr<Program> ast);
    };
}
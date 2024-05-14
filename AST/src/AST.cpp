#include "../headers/AST.hpp"

namespace zcode {
    auto indent = [](std::string& value) -> void {
        int level = 0, prev_count = -1;
        for (int i = 0; i < (int)value.length() - 1; i++) {
            if ((value[i] == '{' or value[i] == '[') and value[i + 1] == '\n') {
                level += 1;
            }

            else if (value[i] == '\n' and (value[i + 1] == '}' or value[i + 1] == ']')) {
                level -= 1;
            }

            if (value[i] == '\n') {
                int countSpace = 0, j = i + 1;
                while(j < (int)value.length()) {
                    if (value[j] == ' ') {
                        countSpace++;
                        j++;
                    }

                    else {
                        break;
                    }
                }

                if (countSpace == 0) {
                    value.insert(value.begin() + i + 1, level, ' ');
                    prev_count = level - countSpace;
                }

                else {
                    if (prev_count == -1) prev_count = level - countSpace;
                    else {
                        if (prev_count < level - countSpace) {
                            while (level - countSpace > prev_count) {
                                level -= 1;
                            }
                        }
                        value.insert(value.begin() + i + 1, level - countSpace, ' ');
                        prev_count = level - countSpace;
                    }
                }
                
                i += level;
            }
        }
    };

    Id::Id(std::string name) {
        this->name = name;
    }

    Id::operator std::string() const {
        return "{ NodeType: \"Identifier\", Name: \"" + this->name + "\" }";
    }

    std::any Id::accept(Visitor* v) {
        return v->visitId(std::make_shared<Id>(*this));
    }

    BinaryOp::BinaryOp(std::string op, std::shared_ptr<Expr> left, std::shared_ptr<Expr> right) {
        this->op = op;
        this->left = (left);
        this->right = (right);
    }

    BinaryOp::operator std::string() const {
        std::string str = "{\nNodeType: \"BinaryExpr\",\nLeftExpr: " + std::string(*this->left) + ",\nRightExpr: " + std::string(*this->right) + ",\nOperator: \"" + this->op + "\"\n}";
        indent(str);
        return str;
    }

    std::any BinaryOp::accept(Visitor* v) {
        return v->visitBinaryOp(std::make_shared<BinaryOp>(*this));
    }

    UnaryOp::UnaryOp(std::string op, std::shared_ptr<Expr> operand) {
        this->op = op;
        this->operand = (operand);
    }

    UnaryOp::operator std::string() const {
        std::string str = "{\nNodeType: \"UnaryExpr\",\nOperand: " + std::string(*this->operand) + ",\nOperator: \"" + this->op + "\"\n}";
        indent(str);
        return str;
    }

    std::any UnaryOp::accept(Visitor* v) {
        return v->visitUnaryOp(std::make_shared<UnaryOp>(*this));
    }

    CallExpr::CallExpr(std::shared_ptr<Id> name, std::vector<std::shared_ptr<Expr>> args) {
        this->name = (name);
        this->args = args;
    }

    CallExpr::operator std::string() const {
        std::string str = "{\nNodeType: \"CallExpr\",\nId: " + std::string(*this->name) + ",\nArgument: [\n";
        for (int i = 0; i < (int)this->args.size(); i++) {
            str += std::string(*this->args[i]) + (i == (int)this->args.size() - 1? "" : ",\n");
        }
        str += "\n]\n}";
        indent(str);
        return str;
    }

    std::any CallExpr::accept(Visitor* v) {
        return v->visitCallExpr(std::make_shared<CallExpr>(*this));
    }

    ArrayCell::ArrayCell(std::shared_ptr<Expr> arr, std::vector<std::shared_ptr<Expr>> idx) {
        this->arr = (arr);
        this->idx = idx;
    }

    ArrayCell::operator std::string() const {
        std::string str = "{\nNodeType: \"ArrayCell\",\nExpr: " + std::string(*this->arr) + ",\nIndex: [\n";
        for (int i = 0; i < (int)this->idx.size(); i++) {
            str += std::string(*this->idx[i]) + (i == (int)this->idx.size() - 1? "" : ",\n");
        }
        str += "\n]\n}";
        indent(str);
        return str;
    }

    std::any ArrayCell::accept(Visitor* v) {
        return v->visitArrayCell(std::make_shared<ArrayCell>(*this));
    }

    NumberLiteral::NumberLiteral(double val) {
        this->val = val;
    }

    NumberLiteral::operator std::string() const {
        return "{ NodeType: \"NumberLiteral\", Value: " + std::to_string(this->val) + " }";
    }
    
    std::any NumberLiteral::accept(Visitor* v) {
        return v->visitNumberLiteral(std::make_shared<NumberLiteral>(*this));
    }

    StringLiteral::StringLiteral(std::string val) {
        this->val = val;
    }

    StringLiteral::operator std::string() const {
        return "{ NodeType: \"StringLiteral\", Value: \"" + this->val + "\" }";
    }

    std::any StringLiteral::accept(Visitor* v) {
        return v->visitStringLiteral(std::make_shared<StringLiteral>(*this));
    }

    BooleanLiteral::BooleanLiteral(bool val) {
        this->val = val;
    }

    BooleanLiteral::operator std::string() const {
        const std::string value = (this->val? "true" : "false");
        return "{ NodeType: \"BooleanLiteral\", Value: " + value + " }";
    }

    std::any BooleanLiteral::accept(Visitor* v) {
        return v->visitBooleanLiteral(std::make_shared<BooleanLiteral>(*this));
    }

    ArrayLiteral::ArrayLiteral(std::vector<std::shared_ptr<Expr>> value) {
        this->value = value;
    }

    ArrayLiteral::operator std::string() const {
        std::string str = "{\nNodeType: \"ArrayLiteral\", \nElements: [\n";
        for (int i = 0; i < (int)this->value.size(); i++) {
            str += std::string(*this->value[i]) + (i == (int)this->value.size() - 1? "" : ",\n");
        }
        str += "\n]\n}";
        indent(str);
        return str;
    }

    std::any ArrayLiteral::accept(Visitor* v) {
        return v->visitArrayLiteral(std::make_shared<ArrayLiteral>(*this));
    }

    Assign::Assign(std::shared_ptr<Expr> lhs, std::shared_ptr<Expr> rhs) {
        this->lhs = (lhs);
        this->exp = (rhs);
    }

    Assign::operator std::string() const {
        std::string str = "{\nNodeType: \"AssignStmt\", \nLHS: " + std::string(*this->lhs) + ",\nRHS: " + std::string(*this->exp) + "\n}";
        indent(str);
        return str;
    }

    std::any Assign::accept(Visitor* v) {
        return v->visitAssign(std::make_shared<Assign>(*this));
    }

    If::If(std::shared_ptr<Expr> expr, std::shared_ptr<Stmt> thenStmt, std::vector<std::tuple<std::shared_ptr<Expr>, std::shared_ptr<Stmt>>> elifStmt, std::shared_ptr<Stmt> elseStmt) {
        this->expr = (expr);
        this->thenStmt = (thenStmt);
        this->elifStmt = elifStmt;
        this->elseStmt = (elseStmt);
    }

    If::operator std::string() const {
        std::string str = "{\nNodeType: \"IfStmt\", \nCondition: " + std::string(*this->expr) + ",\nStmt: " + std::string(*this->thenStmt);
        for (int i = 0; i < (int)this->elifStmt.size(); i++) {
            str += (",\nElifStmt: {\nCondition: " + std::string(*std::get<0>(this->elifStmt[i])) + ",\nStmt: " + std::string(*std::get<1>(this->elifStmt[i])) + "\n}");
        }

        if (this->elseStmt) {
            str += ",\nElseStmt: {\nStmt: " + std::string(*this->elseStmt) + "\n}";
        }
        str += "\n}";
        indent(str);
        return str;
    }

    std::any If::accept(Visitor* v) {
        return v->visitIf(std::make_shared<If>(*this));
    }

    For::For(std::shared_ptr<Id> name, std::shared_ptr<Expr> condExpr, std::shared_ptr<Expr> updExpr, std::shared_ptr<Stmt> body) {
        this->name = (name);
        this->condExpr = (condExpr);
        this->updExpr = (updExpr);
        this->body = (body);
    }

    For::operator std::string() const {
        std::string str = "{\nNodeType: \"ForStmt\", \nId: " + std::string(*this->name) + ",\nCondition: " + std::string(*this->condExpr) + ",\nUpdate: " + std::string(*this->updExpr) + ",\nStmt: " + std::string(*this->body) + "\n}";
        indent(str);
        return str;
    }

    std::any For::accept(Visitor* v) {
        return v->visitFor(std::make_shared<For>(*this));
    }

    Break::operator std::string() const {
        std::string str = "{\nNodeType: BreakStmt\n}";
        indent(str);
        return str;
    }

    std::any Break::accept(Visitor* v) {
        return v->visitBreak(std::make_shared<Break>(*this));
    }

    Continue::operator std::string() const {
        std::string str = "{\nNodeType: ContinueStmt\n}";
        indent(str);
        return str;
    }

    std::any Continue::accept(Visitor* v) {
        return v->visitContinue(std::make_shared<Continue>(*this));
    }

    Return::Return(std::shared_ptr<Expr> expr) {
        this->expr = (expr);
    }

    Return::operator std::string() const {
        std::string str = "";
        if (this->expr) {
            str = "{\nNodeType: ReturnStmt\nExpr: " + std::string(*this->expr) + "\n}";
        }
        
        else str = "{\nNodeType: ReturnStmt\n}";
        indent(str);
        return str;
    }

    std::any Return::accept(Visitor* v) {
        return v->visitReturn(std::make_shared<Return>(*this));
    }

    Block::Block(std::vector<std::shared_ptr<Stmt>> stmt) {
        this->stmt = stmt;
    }

    Block::operator std::string() const {
        std::string str = "{\nNodeType: BlockStmt\nStmt: [\n";
        for (int i = 0; i < (int)this->stmt.size(); i++) {
            str += std::string(*this->stmt[i]) + (i == (int)this->stmt.size() - 1? "" : ",\n");
        }
        str += "\n]\n}";
        indent(str);
        return str;
    }

    std::any Block::accept(Visitor* v) {
        return v->visitBlock(std::make_shared<Block>(*this));
    }

    CallStmt::CallStmt(std::shared_ptr<Id> name, std::vector<std::shared_ptr<Expr>> args) {
        this->name = (name);
        this->args = args;
    }

    CallStmt::operator std::string() const {
        std::string str = "{\nNodeType: \"CallStmt\",\nId: " + std::string(*this->name) + ",\nArgument: [\n";
        for (int i = 0; i < (int)this->args.size(); i++) {
            str += std::string(*this->args[i]) + (i == (int)this->args.size() - 1? "" : ",\n");
        }
        str += "\n]\n}";
        indent(str);
        return str;
    }

    std::any CallStmt::accept(Visitor* v) {
        return v->visitCallStmt(std::make_shared<CallStmt>(*this));
    }

    VoidType::operator std::string() const {
        return "VoidType";
    }

    std::any VoidType::accept(Visitor* v) {
        return std::make_any<std::shared_ptr<VoidType>>(nullptr);
    }

    NumberType::operator std::string() const {
        return "NumberType";
    }

    std::any NumberType::accept(Visitor* v) {
        return v->visitNumberType(std::make_shared<NumberType>(*this));
    }

    BoolType::operator std::string() const {
        return "BoolType";
    }

    std::any BoolType::accept(Visitor* v) {
        return v->visitBoolType(std::make_shared<BoolType>(*this));
    }

    StringType::operator std::string() const {
        return "StringType";
    }

    std::any StringType::accept(Visitor* v) {
        return v->visitStringType(std::make_shared<StringType>(*this));
    }

    ArrayType::ArrayType(std::vector<double> size, std::shared_ptr<Type> eleType) {
        this->size = size;
        this->eleType = eleType;
    }

    ArrayType::operator std::string() const {
        std::string str = "ArrayType: { Size: [";
        for (int i = 0; i < (int)this->size.size(); i++) {
            str += std::to_string(this->size[i]) + (i == (int)this->size.size() - 1? "" : ", ");
        }
        str += "], ElemType: " + (this->eleType == nullptr? "None" : std::string(*this->eleType)) + " }";
        return str;
    }

    std::any ArrayType::accept(Visitor* v) {
        return v->visitArrayType(std::make_shared<ArrayType>(*this));
    }

    VarDecl::VarDecl(std::shared_ptr<Id> name, std::string modifier, std::shared_ptr<Type> varType, std::shared_ptr<Expr> varInit) {
        this->name = name;
        this->modifier = modifier;
        this->varType = varType;
        this->varInit = varInit;
    }

    VarDecl::operator std::string() const {
        std::string str = "{\nNodeType: \"VarDecl\", \nModifier: " + (this->modifier == ""? "None" : this->modifier) + ",\nId: " + std::string(*this->name) + ",\nType: ";
        str += (this->varType? std::string(*this->varType) : "None") + ",\nExpr: ";
        str += (this->varInit? std::string(*this->varInit) : "None") + "\n}";
        indent(str);
        return str;
    }

    std::any VarDecl::accept(Visitor* v) {
        return v->visitVarDecl(std::make_shared<VarDecl>(*this));
    }

    FuncDecl::FuncDecl(std::shared_ptr<Id> name, std::vector<std::shared_ptr<VarDecl>> params, std::shared_ptr<Stmt> body) {
        this->name = (name);
        this->params = params;
        this->body = (body);
    }

    FuncDecl::operator std::string() const {
        std::string str = "{\nNodeType: \"FuncDecl\",\nId: " + std::string(*this->name) + ",\nParams: [\n";
        for (int i = 0; i < (int)this->params.size(); i++) {
            str += std::string(*this->params[i]) + (i == (int)this->params.size() - 1? "" : ",\n");
        }
        str += "\n],\nStmt:";
        str += (this->body? "\n" + std::string(*this->body) : " None") + "\n}";
        indent(str);
        return str;
    }

    std::any FuncDecl::accept(Visitor* v) {
        return v->visitFuncDecl(std::make_shared<FuncDecl>(*this));
    }

    Program::Program(std::vector<std::shared_ptr<Decl>> decls) {
        this->decls = decls;
    }

    Program::operator std::string() const {
        std::string str = "{\nNodeType: \"Program\",\nDecls: [\n";
        for (int i = 0; i < (int)this->decls.size(); i++) {
            str += std::string(*this->decls[i]) + (i == (int)this->decls.size() - 1? "" : ",\n");
        }
        str += "\n]\n}";
        indent(str);
        return str;
    }

    std::any Program::accept(Visitor* v) {
        return v->visitProgram(std::make_shared<Program>(*this));
    }
}
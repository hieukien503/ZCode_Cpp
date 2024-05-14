#include "../headers/StaticChecker.hpp"

namespace zcode {
    std::shared_ptr<Symbol> Utils::lookup(const std::string& name, const std::vector<std::shared_ptr<Symbol>>& v, std::string (*f)(std::shared_ptr<Symbol> x)) {
        for (const auto& obj: v) {
            if (f(obj) == name) {
                return obj;
            }
        }
        return nullptr;
    }

    VarSym::VarSym(std::string name, std::shared_ptr<Type> typ) {
        this->name = name;
        this->typ = typ;
    }

    VarSym::operator std::string() const {
        return "VarSym(" + this->name + ", " + std::string(*this->typ) + ")";
    }

    FuncSym::FuncSym(std::string name, std::vector<std::shared_ptr<VarSym>> params, std::shared_ptr<Type> typ, std::shared_ptr<Stmt> body) {
        this->name = name;
        this->params = params;
        this->typ = typ;
        this->body = body;
    }

    FuncSym::operator std::string() const {
        std::string str = "FuncSym(" + this->name + ",(";
        for (const auto& sym: params) {
            str += std::string(*sym) + ",";
        }
        str.pop_back();
        str += ")," + (this->typ? std::string(*this->typ) : "None");
        return str;
    }

    StaticChecker::StaticChecker(std::shared_ptr<AST> ast) {
        this->ast = ast;
        this->symTable = std::vector<std::vector<std::shared_ptr<Symbol>>>(1, std::vector<std::shared_ptr<Symbol>>());
        this->symTable[0].push_back(std::make_shared<FuncSym>("writeNumber", std::vector<std::shared_ptr<VarSym>>(1, std::make_shared<VarSym>("", std::make_shared<NumberType>())), std::make_shared<VoidType>()));
        this->symTable[0].push_back(std::make_shared<FuncSym>("writeString", std::vector<std::shared_ptr<VarSym>>(1, std::make_shared<VarSym>("", std::make_shared<StringType>())), std::make_shared<VoidType>()));
        this->symTable[0].push_back(std::make_shared<FuncSym>("writeBool", std::vector<std::shared_ptr<VarSym>>(1, std::make_shared<VarSym>("", std::make_shared<BoolType>())), std::make_shared<VoidType>()));
        this->symTable[0].push_back(std::make_shared<FuncSym>("readNumber", std::vector<std::shared_ptr<VarSym>>(), std::make_shared<NumberType>()));
        this->symTable[0].push_back(std::make_shared<FuncSym>("readString", std::vector<std::shared_ptr<VarSym>>(), std::make_shared<StringType>()));
        this->symTable[0].push_back(std::make_shared<FuncSym>("readBool", std::vector<std::shared_ptr<VarSym>>(), std::make_shared<BoolType>()));
        this->in_loop = {};
        this->arr_ast = {};
        this->curr_var_name = "";
        this->func_name = "";
        this->has_return = false;
        this->no_body = {};
        this->resolved = false;
        this->return_list = {};
        this->scope = 0;
    }

    void StaticChecker::check() {
        this->visit(this->ast);
    }

    void StaticChecker::resolve_type(std::shared_ptr<Expr> expr, std::shared_ptr<Type> typeToResolve) {
        if (typeid(*expr).name() == typeid(Id).name()) {
            std::shared_ptr<Id> e = std::make_shared<Id>(*(dynamic_cast<Id*>(expr.get())));
            int idx = -1;
            for(int i = 0; i < (int)this->symTable.size(); i++) {
                std::shared_ptr<Symbol> sym = this->lookup(e->name, this->symTable[i], [](std::shared_ptr<Symbol> x) -> std::string {
                    if (typeid(*x).name() == typeid(VarSym).name()) {
                        std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (x.get())));
                        return e->name;
                    }
                    std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*> (x.get())));
                    return e->name;
                });

                if (sym and typeid(*sym).name() == typeid(VarSym).name()) {
                    idx = i;
                    break;
                }
            }

            if (idx != -1) {
                for (int i = 0; i < (int)this->symTable[idx].size(); i++) {
                    if (typeid(*(this->symTable[idx][i])).name() == typeid(VarSym).name()) {
                        std::shared_ptr<VarSym> v = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (this->symTable[idx][i].get())));
                        if (v->name == e->name) {
                            this->symTable[idx][i] = std::make_shared<VarSym>(e->name, typeToResolve);
                            return;
                        }
                    }
                }
            }
        }

        else if (typeid(*expr).name() == typeid(CallExpr).name()) {
            std::shared_ptr<CallExpr> e = std::make_shared<CallExpr>(*(dynamic_cast<CallExpr *>(expr.get())));
            for (int i = 0; i < (int)this->symTable.back().size(); i++) {
                if (typeid(*(this->symTable.back()[i])).name() == typeid(FuncSym).name()) {
                    std::shared_ptr<FuncSym> v = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *> (this->symTable.back()[i].get())));
                    if (v->name == e->name->name) {
                        this->symTable.back()[i] = std::make_shared<FuncSym>(v->name, v->params, typeToResolve, v->body);
                        return;
                    }
                }
            }
        }

        else if (typeid(*expr).name() == typeid(ArrayLiteral).name()){
            if (typeid(*typeToResolve).name() != typeid(ArrayType).name()) {
                this->resolved = false;
            }

            else {
                std::shared_ptr<ArrayType> typ = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(typeToResolve.get())));
                std::shared_ptr<ArrayLiteral> e = std::make_shared<ArrayLiteral>(*(dynamic_cast<ArrayLiteral *>(expr.get())));
                for (const auto& val: e->value) {
                    std::vector<double> v = typ->size;
                    v.erase(v.begin(), v.begin() + 1);
                    std::shared_ptr<Type> type = (int)typ->size.size() == 1? typ->eleType : std::make_shared<ArrayType>(v, typ->eleType);
                    this->resolve_type(val, type);
                }
            }
        }
        else {
            this->resolved = false;
        }
    }

    void StaticChecker::resolve_typeCallStmt(std::shared_ptr<CallStmt> call_stmt) {
        std::shared_ptr<CallStmt> e = std::make_shared<CallStmt>(*(dynamic_cast<CallStmt*>(call_stmt.get())));
        for (int i = 0; i < (int)this->symTable.back().size(); i++) {
            if (typeid(*this->symTable.back()[i]).name() == typeid(FuncSym).name()) {
                std::shared_ptr<FuncSym> v = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *> (this->symTable.back()[i].get())));
                if (v->name == e->name->name) {
                    this->symTable.back()[i] = std::make_shared<FuncSym>(v->name, v->params, std::shared_ptr<VoidType>(), v->body);
                    return;
                }
            }
        }
    }

    std::any StaticChecker::visitProgram(std::shared_ptr<Program> ast) {
        for (const auto& decl: ast->decls) {
            this->visit(decl);
        }

        if (!this->no_body.empty()) {
            throw NotImplemented(this->no_body[0]->name->name);
        }

        bool flag = false;
        for (const auto& sym: this->symTable[0]) {
            if (typeid(*sym).name() == typeid(FuncSym).name()) {
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym> (* (dynamic_cast<FuncSym *>(sym.get())));
                if (e->name == "main" and typeid(*(e->typ)).name() == typeid(VoidType).name()) {
                    flag = true;
                    break;
                }
            }
        }

        if (not flag) {
            throw NoEntryPoint();
        }

        return std::make_any<std::shared_ptr<Program>>(nullptr);
    }

    std::any StaticChecker::visitVarDecl(std::shared_ptr<VarDecl> ast) {
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        if (this->lookup(ast->name->name, this->symTable[0], [](std::shared_ptr<Symbol> x) -> std::string {
            if (typeid(*x).name() == typeid(VarSym).name()) {
                std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*>(x.get())));
                return e->name;
            }
            std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*>(x.get())));
            return e->name;
        }) != nullptr) {
            throw Redeclared(std::make_shared<Variable>(), ast->name->name);
        }

        this->curr_var_name = ast->name->name;
        std::shared_ptr<Type> lhsType = ast->varType;
        if (ast->varInit == nullptr) {
            this->symTable[0].push_back(std::make_shared<VarSym>(ast->name->name, lhsType));
        }

        else {
            std::shared_ptr<Type> rhsType = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->varInit));
            std::cout << std::string(*rhsType) << '\n';
            if (lhsType != nullptr and rhsType != nullptr) {
                if (typeid(*lhsType).name() != typeid(*rhsType).name()) {
                    throw TypeMismatchInStatement(ast);
                }

                else {
                    if (typeid(*lhsType).name() == typeid(ArrayType).name()) {
                        std::shared_ptr<ArrayType> e1 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(lhsType.get())));
                        std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(rhsType.get())));
                        if (e2->size.size() > e1->size.size()) throw TypeMismatchInStatement(ast);
                        if (e2->size.size() == e1->size.size() and e2->size != e1->size) throw TypeMismatchInStatement(ast);
                        if (e2->eleType == nullptr) {
                            this->resolve_type(ast->varInit, lhsType);
                            if (not this->resolved) throw TypeCannotBeInferred(ast);
                            else e2 = e1;
                        }

                        if (typeid(*(e1->eleType)).name() != typeid(*(e2->eleType)).name() or e1->size != e2->size) {
                            throw TypeMismatchInStatement(ast); 
                        }
                    }
                    this->symTable[0].push_back(std::make_shared<VarSym>(ast->name->name, lhsType));
                }
            }

            else {
                if (lhsType == nullptr and rhsType == nullptr) {
                    throw TypeCannotBeInferred(ast);
                }

                else if (rhsType != nullptr and typeid(*rhsType).name() == typeid(ArrayType).name() and lhsType == nullptr) {
                    std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(rhsType.get())));
                    if (e2->eleType == nullptr) throw TypeCannotBeInferred(ast);
                }

                else if (rhsType == nullptr and lhsType != nullptr) {
                    if (typeid(*(ast->varInit)).name() == typeid(Id).name() or typeid(*(ast->varInit)).name() == typeid(CallExpr).name() or typeid(*(ast->varInit)).name() == typeid(ArrayLiteral).name()) {
                        this->resolve_type(ast->varInit, lhsType);
                        if (not this->resolved) {
                            throw TypeCannotBeInferred(ast);
                        }

                        this->symTable[0].push_back(std::make_shared<VarSym>(ast->name->name, lhsType));
                    }

                    else {
                        throw TypeCannotBeInferred(ast);
                    }
                }

                else {
                    this->symTable[0].push_back(std::make_shared<VarSym>(ast->name->name, rhsType));
                }
            }
        }

        this->curr_var_name = "";
        return std::make_any<std::shared_ptr<VarDecl>>(nullptr);
    }

    std::any StaticChecker::visitFuncDecl(std::shared_ptr<FuncDecl> ast) {
        std::shared_ptr<Symbol> func = this->lookup(ast->name->name, this->symTable.back(), [](std::shared_ptr<Symbol> x) -> std::string {
            if (typeid(*x).name() == typeid(VarSym).name()) {
                std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym *> (x.get())));
                return e->name;
            }

            std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *> (x.get())));
            return e->name;
        });

        if (func != nullptr) {
            if (typeid(*func).name() == typeid(VarSym).name()) {
                throw Redeclared(std::make_shared<Function>(), ast->name->name);
            }

            else {
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *> (func.get())));
                if (e->body != nullptr or (e->body == nullptr and ast->body == nullptr)) {
                    throw Redeclared(std::make_shared<Function>(), ast->name->name);
                }
            }
        }

        std::vector<std::shared_ptr<Symbol>> params;
        for (const auto& param: ast->params) {
            if (this->lookup(param->name->name, params, [](std::shared_ptr<Symbol> x) -> std::string {
                if (typeid(*x).name() == typeid(VarSym).name()) {
                    std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (x.get())));
                    return e->name;
                }
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*> (x.get())));
                return e->name;
            }) != nullptr) {
                throw Redeclared(std::make_shared<Parameter>(), param->name->name);
            }

            else {
                params.push_back(std::make_shared<VarSym>(param->name->name, param->varType));
            }
        }

        this->symTable.insert(this->symTable.begin(), params);

        std::vector<std::shared_ptr<VarSym>> anotherParams;
        for (int i = 0; i < (int)params.size(); i++) {
            anotherParams.push_back(std::make_shared<VarSym>(*(dynamic_cast<VarSym *>(params[i].get()))));
        }
        if (ast->body == nullptr) {
            this->no_body.push_back(ast);
            this->symTable.back().push_back(std::make_shared<FuncSym>(ast->name->name, anotherParams));
        }

        else {
            this->func_name = ast->name->name;
            for (int i = 0; i < (int)this->no_body.size(); i++) {
                const auto& func = this->no_body[i];
                if (func->name->name == this->func_name) {
                    this->no_body.erase(this->no_body.begin() + i, this->no_body.begin() + i + 1);
                    break;
                }
            }

            bool func_found = false;
            for (int idx = 0; idx < (int)this->symTable.back().size(); idx++) {
                if (typeid(*(this->symTable.back()[idx])).name() == typeid(FuncSym).name()) {
                    std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *>(this->symTable.back()[idx].get())));
                    if (e->name == this->func_name) {
                        func_found = true;
                        if (e->params.size() != anotherParams.size()) {
                            throw Redeclared(std::make_shared<Function>(), ast->name->name);
                        }

                        for (int i = 0; i < (int)anotherParams.size(); i++) {
                            if (typeid(*(e->params[i]->typ)).name() != typeid(*(anotherParams[i]->typ)).name()) {
                                throw Redeclared(std::make_shared<Function>(), ast->name->name);
                            }

                            else {
                                if (typeid(*(anotherParams[i]->typ)).name() == typeid(ArrayType).name()) {
                                    std::shared_ptr<ArrayType> e1 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (e->params[i]->typ.get())));
                                    std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (anotherParams[i]->typ.get())));
                                    if (typeid(*(e1->eleType)).name() != typeid(*(e2->eleType)).name() or e1->size != e2->size) {
                                        throw Redeclared(std::make_shared<Function>(), ast->name->name); 
                                    }
                                }
                            }
                        }
                        this->visit(ast->body);
                        break;
                    }
                }
            }

            if (not func_found) {
                this->symTable.back().push_back(std::make_shared<FuncSym>(this->func_name, anotherParams, nullptr, ast->body));
                this->visit(ast->body);
            }
        }
        this->has_return = false;
        this->symTable.erase(this->symTable.begin(), this->symTable.begin() + 1);
        this->return_list = {};
        return std::make_any<std::shared_ptr<FuncDecl>>(nullptr);
    }

    std::any StaticChecker::visitId(std::shared_ptr<Id> ast) {
        if (ast->name == this->curr_var_name) {
            throw Undeclared(std::make_shared<Identifier>(), ast->name);
        }
        
        this->resolved = true;
        std::vector<std::shared_ptr<Symbol>> found = {};
        for (const auto& param: this->symTable) {
            std::shared_ptr<Symbol> sym = this->lookup(ast->name, param, [](std::shared_ptr<Symbol> x) -> std::string {
                if (typeid(*x).name() == typeid(VarSym).name()) {
                    std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (x.get())));
                    return e->name;
                }
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*> (x.get())));
                return e->name;
            });

            if (sym and typeid(*sym).name() == typeid(VarSym).name()) {
                found = param;
                break;
            }
        }
        
        if (found.empty()) {
            throw Undeclared(std::make_shared<Identifier>(), ast->name);
        }
        
        else {
            for (const auto& sym: found) {
                if (typeid(*sym).name() == typeid(VarSym).name()) {
                    std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym *>(sym.get())));
                    if (e->name == ast->name) {
                        return e->typ;
                    }
                }
            }

            return std::make_any<std::shared_ptr<Type>>(nullptr);
        }
    }

    std::any StaticChecker::visitBreak(std::shared_ptr<Break> ast) {
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        if (this->in_loop.empty()) {
            throw MustInLoop(ast);
        }

        return std::make_any<std::shared_ptr<Break>>(nullptr);
    }

    std::any StaticChecker::visitContinue(std::shared_ptr<Continue> ast) {
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        if (this->in_loop.empty()) {
            throw MustInLoop(ast);
        }

        return std::make_any<std::shared_ptr<Continue>>(nullptr);
    }

    std::any StaticChecker::visitBlock(std::shared_ptr<Block> ast) {
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        this->symTable.insert(this->symTable.begin(), std::vector<std::shared_ptr<Symbol>>());
        this->scope += 1;
        for (const auto& stmt: ast->stmt) {
            this->visit(stmt);
        }
        
        if (this->return_list.empty() and this->scope == 1) {
            for (int idx = 0; idx < (int)this->symTable.back().size(); idx++) {
                if (typeid(*(this->symTable.back()[idx])).name() == typeid(FuncSym).name()) {
                    std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *> (this->symTable.back()[idx].get())));
                    if (e->name == this->func_name) {
                        if (e->typ == nullptr) {
                            this->symTable.back()[idx] = std::make_shared<FuncSym>(e->name, e->params, std::make_shared<VoidType>(), e->body);
                            break;
                        }

                        else if (typeid(*(e->typ)).name() != typeid(VoidType).name()) {
                            throw FunctionNotReturn(this->func_name);
                        }
                    }
                }
            }
        }

        this->scope -= 1;
        this->has_return = false;
        this->symTable.erase(this->symTable.begin(), this->symTable.begin() + 1);
        return std::make_any<std::shared_ptr<Block>>(nullptr);
    }

    std::any StaticChecker::visitIf(std::shared_ptr<If> ast) {
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        std::shared_ptr<Type> cond_typ = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->expr));
        if (cond_typ == nullptr) {
            if (typeid(*(ast->expr)).name() == typeid(Id).name() or typeid(*(ast->expr)).name() == typeid(CallExpr).name()) {
                this->resolve_type(ast->expr, std::make_shared<BoolType>());
                if (not this->resolved) {
                    throw TypeCannotBeInferred(ast);
                }

                cond_typ = std::make_shared<BoolType>();
            }

            else {
                throw TypeCannotBeInferred(ast);
            }
        }

        if (typeid(*cond_typ).name() != typeid(BoolType).name()) {
            throw TypeMismatchInStatement(ast);
        }

        this->visit(ast->thenStmt);
        if (not this->return_list.empty() and this->scope == 1) {
            this->return_list = {};
        }

        this->has_return = false;
        for (const auto& tup: ast->elifStmt) {
            std::shared_ptr<Expr> e = std::get<0>(tup);
            std::shared_ptr<Stmt> stmt = std::get<1>(tup);
            cond_typ = std::any_cast<std::shared_ptr<Type>>(this->visit(e));
            if (cond_typ == nullptr) {
                if (typeid(*e).name() == typeid(Id).name() or typeid(*e).name() == typeid(CallExpr).name()) {
                    this->resolve_type(e, std::make_shared<BoolType>());
                    if (not this->resolved) {
                        throw TypeCannotBeInferred(ast);
                    }

                    cond_typ = std::make_shared<BoolType>();
                }

                else {
                    throw TypeCannotBeInferred(ast);
                }
            }

            if (typeid(*cond_typ).name() != typeid(BoolType).name()) {
                throw TypeMismatchInStatement(ast);
            }

            this->visit(stmt);
            if (not this->return_list.empty() and this->scope == 1) {
                this->return_list = {};
            }
            this->has_return = false;
        }

        if (ast->elseStmt) {
            this->visit(ast->elseStmt);
        }
        return std::make_any<std::shared_ptr<If>>(nullptr);
    }

    std::any StaticChecker::visitFor(std::shared_ptr<For> ast) {
        this->in_loop.push_back(1);
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        std::shared_ptr<Type> scala_typ = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->name));
        if (scala_typ == nullptr) {
            this->resolve_type(ast->name, std::make_shared<NumberType>());
            scala_typ = std::make_shared<NumberType>();
        }

        if (typeid(*scala_typ).name() != typeid(NumberType).name()) {
            throw TypeMismatchInStatement(ast);
        }

        std::shared_ptr<Type> cond_typ = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->condExpr));
        if (cond_typ == nullptr) {
            if (typeid(*(ast->condExpr)).name() == typeid(Id).name() or typeid(*(ast->condExpr)).name() == typeid(CallExpr).name()) {
                this->resolve_type(ast->condExpr, std::make_shared<BoolType>());
                if (not this->resolved) {
                    throw TypeCannotBeInferred(ast);
                }

                cond_typ = std::make_shared<BoolType>();
            }

            else {
                throw TypeCannotBeInferred(ast);
            }
        }

        if (typeid(*cond_typ).name() != typeid(BoolType).name()) {
            throw TypeMismatchInStatement(ast);
        }

        std::shared_ptr<Type> update_typ = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->updExpr));
        if (update_typ == nullptr) {
            if (typeid(*(ast->updExpr)).name() == typeid(Id).name() or typeid(*(ast->updExpr)).name() == typeid(CallExpr).name()) {
                this->resolve_type(ast->updExpr, std::make_shared<NumberType>());
                if (not this->resolved) {
                    throw TypeCannotBeInferred(ast);
                }

                update_typ = std::make_shared<NumberType>();
            }

            else {
                throw TypeCannotBeInferred(ast);
            }
        }

        if (typeid(*update_typ).name() != typeid(NumberType).name()) {
            throw TypeMismatchInStatement(ast);
        }

        this->visit(ast->body);
        if (not this->return_list.empty() and this->scope == 1) {
            this->return_list = {};
        }

        this->in_loop.pop_back();
        return std::make_any<std::shared_ptr<For>>(nullptr);
    }

    std::any StaticChecker::visitNumberType(std::shared_ptr<NumberType> ast) {
        std::shared_ptr<Type> e = std::make_shared<NumberType>();
        return e;
    }

    std::any StaticChecker::visitStringType(std::shared_ptr<StringType> ast) {
        std::shared_ptr<Type> e = std::make_shared<StringType>();
        return e;
    }

    std::any StaticChecker::visitBoolType(std::shared_ptr<BoolType> ast) {
        std::shared_ptr<Type> e = std::make_shared<BoolType>();
        return e;
    }

    std::any StaticChecker::visitArrayType(std::shared_ptr<ArrayType> ast) {
        std::shared_ptr<Type> e = std::make_shared<ArrayType>(ast->size, ast->eleType);
        return e;
    }

    std::any StaticChecker::visitNumberLiteral(std::shared_ptr<NumberLiteral> ast) {
        std::shared_ptr<Type> e = std::make_shared<NumberType>();
        return e;
    }

    std::any StaticChecker::visitStringLiteral(std::shared_ptr<StringLiteral> ast) {
        std::shared_ptr<Type> e = std::make_shared<StringType>();
        return e;
    }

    std::any StaticChecker::visitBooleanLiteral(std::shared_ptr<BooleanLiteral> ast) {
        std::shared_ptr<Type> e = std::make_shared<BoolType>();
        return e;
    }

    std::any StaticChecker::visitArrayLiteral(std::shared_ptr<ArrayLiteral> ast) {
        bool flag = false;
        for (const auto& arr: this->arr_ast) {
            if (arr == ast) {
                flag = true;
            }
        }
        
        if (not flag) {
            this->arr_ast.push_back(ast);
        }
        
        std::shared_ptr<Type> typ = nullptr;
        for (const auto& v: ast->value) {
            typ = std::any_cast<std::shared_ptr<Type>>(this->visit(v));
            if (typ != nullptr) {
                break;
            }
        }

        if (typ != nullptr) {
            for (const auto& val: ast->value) {
                std::shared_ptr<Type> val_typ = std::any_cast<std::shared_ptr<Type>>(this->visit(val));
                if (val_typ == nullptr) {
                    if (typeid(*val).name() == typeid(Id).name() or typeid(*val).name() == typeid(CallExpr).name() or typeid(*val).name() == typeid(ArrayLiteral).name()) {
                        this->resolve_type(val, typ);
                        if (not this->resolved) {
                            return std::make_any<std::shared_ptr<Type>>(nullptr);
                        }

                        val_typ = typ;
                    }

                    else {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }
                }

                if (typeid(*val_typ).name() != typeid(*typ).name()) {
                    throw InvalidArrayLiteral(this->arr_ast[0]);
                }

                else {
                    if (typeid(*val_typ).name() == typeid(ArrayType).name()) {
                        std::shared_ptr<ArrayType> e1 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (typ.get())));
                        std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (val_typ.get())));
                        if (e2->size.size() == e1->size.size() and e2->size != e1->size) throw InvalidArrayLiteral(this->arr_ast[0]);
                        if (e2->eleType != nullptr) {
                            for (const auto& value: ast->value) {
                                std::shared_ptr<Type> valType = std::any_cast<std::shared_ptr<Type>>(this->visit(value));
                                if (valType == nullptr) {
                                    this->resolve_type(value, e2);
                                    if (not this->resolved) return std::make_any<std::shared_ptr<Type>>(nullptr);
                                }

                                else if (typeid(*valType).name() == typeid(ArrayType).name()) {
                                    std::shared_ptr<ArrayType> x = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(valType.get())));
                                    if (x->eleType == nullptr) {
                                        this->resolve_type(value, e2);
                                        if (not this->resolved) return std::make_any<std::shared_ptr<Type>>(nullptr);
                                    }
                                }
                            }
                            if (e1->eleType == nullptr) {
                                e1 = e2;
                            }
                        }

                        else {
                            if (e1->eleType != nullptr) {
                                this->resolve_type(val, e1);
                                if (not this->resolved) return std::make_any<std::shared_ptr<ArrayLiteral>>(nullptr);
                                e2 = e1;
                            }

                            else {
                                if ((int)e1->size.size() <= (int)e2->size.size() and std::vector<double> (e2->size.begin(), e2->size.begin() + e1->size.size()) == e1->size) {
                                    e1 = e2;
                                }

                                else if ((int)e1->size.size() > (int)e2->size.size() and std::vector<double> (e1->size.begin(), e1->size.begin() + e2->size.size()) == e2->size) {
                                    e2 = e1;
                                }

                                else {
                                    throw InvalidArrayLiteral(this->arr_ast[0]);
                                }
                            }
                        }

                        if (e1->eleType != nullptr and e2->eleType != nullptr and (typeid(*(e1->eleType)).name() != typeid(*(e2->eleType)).name() or e1->size != e2->size)) {
                            throw InvalidArrayLiteral(this->arr_ast[0]);
                        }

                        typ = e1;
                    }
                }
            }

            std::shared_ptr<Type> e;
            this->arr_ast.pop_back();
            if (typeid(*typ).name() != typeid(ArrayType).name()) {
                e = std::make_shared<ArrayType>(std::vector<double>(1, (int)ast->value.size()), typ);
            }
            
            else {
                std::shared_ptr<ArrayType> t = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(typ.get())));
                std::vector<double> initialSize(1, (int)ast->value.size());
                initialSize.insert(initialSize.end(), t->size.begin(), t->size.end());
                e = std::make_shared<ArrayType>(initialSize, t->eleType);
            }
            
            return e;
        }

        else {
            this->arr_ast.pop_back();
            std::shared_ptr<Type> e = std::make_shared<ArrayType>(std::vector<double>(1, (int)ast->value.size()), nullptr);
            return e;
        }
        
    }

    std::any StaticChecker::visitAssign(std::shared_ptr<Assign> ast) {
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        std::shared_ptr<Type> rhs = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->exp)), lhs = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->lhs));
        if (lhs == nullptr and rhs == nullptr) {
            throw TypeCannotBeInferred(ast);
        }

        else if (rhs != nullptr and typeid(*rhs).name() == typeid(ArrayType).name() and lhs == nullptr) {
            std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(rhs.get())));
            if (e2->eleType == nullptr) throw TypeCannotBeInferred(ast);
        }

        else if (rhs != nullptr and lhs == nullptr) {
            if (typeid(*(ast->lhs)).name() == typeid(Id).name()) {
                this->resolve_type(ast->lhs, rhs);
            }

            else {
                throw TypeCannotBeInferred(ast);
            }
        }

        else if (rhs == nullptr and lhs != nullptr) {
            if (typeid(*(ast->exp)).name() == typeid(Id).name() or typeid(*(ast->exp)).name() == typeid(CallExpr).name() or typeid(*(ast->exp)).name() == typeid(ArrayLiteral).name()) {
                this->resolve_type(ast->exp, lhs);
                if (not this->resolved) {
                    throw TypeCannotBeInferred(ast);
                }
            }

            else {
                throw TypeCannotBeInferred(ast);
            }
        }

        else {
            if (typeid(*lhs).name() == typeid(VoidType).name()) {
                throw TypeMismatchInStatement(ast);
            }

            else if (typeid(*lhs).name() != typeid(*rhs).name()) {
                throw TypeMismatchInStatement(ast);
            }

            else {
                if (typeid(*rhs).name() == typeid(ArrayType).name()) {
                    std::shared_ptr<ArrayType> e1 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (lhs.get())));
                    std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (rhs.get())));
                    if (e2->size.size() > e1->size.size()) throw TypeMismatchInStatement(ast);
                    if (e2->size.size() == e1->size.size() and e2->size != e1->size) throw TypeMismatchInStatement(ast);
                    if (e2->eleType == nullptr) {
                        this->resolve_type(ast->exp, e1);
                        if (not this->resolved) throw TypeCannotBeInferred(ast);
                        else e2 = e1;
                    }

                    if (typeid(*(e1->eleType)).name() != typeid(*(e2->eleType)).name()) {
                        throw TypeMismatchInStatement(ast); 
                    }
                }
            }
        }
        return std::make_any<std::shared_ptr<Assign>>(nullptr);
    }

    std::any StaticChecker::visitUnaryOp(std::shared_ptr<UnaryOp> ast) {
        std::shared_ptr<Type> e = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->operand));
        if (ast->op == "-") {
            if (e == nullptr) {
                if (typeid(*(ast->operand)).name() == typeid(Id).name() or typeid(*(ast->operand)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->operand, std::make_shared<NumberType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e = std::make_shared<NumberType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (typeid(*e).name() != typeid(NumberType).name()) {
                throw TypeMismatchInExpression(ast);
            }
        }

        else {
            if (e == nullptr) {
                if (typeid(*(ast->operand)).name() == typeid(Id).name() or typeid(*(ast->operand)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->operand, std::make_shared<BoolType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e = std::make_shared<BoolType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (typeid(*e).name() != typeid(BoolType).name()) {
                throw TypeMismatchInExpression(ast);
            }
        }
        return e;
    }

    std::any StaticChecker::visitBinaryOp(std::shared_ptr<BinaryOp> ast) {
        std::shared_ptr<Type> e1 = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->left)), e2 = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->right));
        std::vector<std::string> numberOp = {"+", "-", "*", "/", "%", "=", ">=", "<=", ">", "<", "!="}, boolOp = {"and", "or"}, stringOp = {"...", "=="};
        if (std::find(numberOp.begin(), numberOp.end(), ast->op) != numberOp.end()) {
            if (e1 == nullptr) {
                if (typeid(*(ast->left)).name() == typeid(Id).name() or typeid(*(ast->left)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->left, std::make_shared<NumberType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e1 = std::make_shared<NumberType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (e2 == nullptr) {
                if (typeid(*(ast->right)).name() == typeid(Id).name() or typeid(*(ast->right)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->right, std::make_shared<NumberType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e2 = std::make_shared<NumberType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (typeid(*e1).name() != typeid(NumberType).name() or typeid(*e2).name() != typeid(NumberType).name()) {
                throw TypeMismatchInExpression(ast);
            }

            std::vector<std::string> numberNumberOp = std::vector<std::string>(numberOp.begin(), numberOp.begin() + 5), numberBoolOp = std::vector<std::string>(numberOp.begin() + 5, numberOp.end());
            std::shared_ptr<Type> e;
            if (std::find(numberNumberOp.begin(), numberNumberOp.end(), ast->op) != numberNumberOp.end()) {
                e = std::make_shared<NumberType>();
            }
            else {
                e = std::make_shared<BoolType>();
            }

            return e;
        }

        else if (std::find(boolOp.begin(), boolOp.end(), ast->op) != boolOp.end()) {
            if (e1 == nullptr) {
                if (typeid(*(ast->left)).name() == typeid(Id).name() or typeid(*(ast->left)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->left, std::make_shared<BoolType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e1 = std::make_shared<BoolType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (e2 == nullptr) {
                if (typeid(*(ast->right)).name() == typeid(Id).name() or typeid(*(ast->right)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->right, std::make_shared<BoolType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e2 = std::make_shared<BoolType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (typeid(*e1).name() != typeid(BoolType).name() or typeid(*e2).name() != typeid(BoolType).name()) {
                throw TypeMismatchInExpression(ast);
            }

            std::shared_ptr<Type> e = std::make_shared<BoolType>();
            return e;
        }

        else {
            if (e1 == nullptr) {
                if (typeid(*(ast->left)).name() == typeid(Id).name() or typeid(*(ast->left)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->left, std::make_shared<StringType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e1 = std::make_shared<StringType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (e2 == nullptr) {
                if (typeid(*(ast->right)).name() == typeid(Id).name() or typeid(*(ast->right)).name() == typeid(CallExpr).name()) {
                    this->resolve_type(ast->right, std::make_shared<StringType>());
                    if (not this->resolved) {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }

                    e2 = std::make_shared<StringType>();
                }

                else {
                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                }
            }

            if (typeid(*e1).name() != typeid(StringType).name() or typeid(*e2).name() != typeid(StringType).name()) {
                throw TypeMismatchInExpression(ast);
            }

            std::shared_ptr<Type> e;
            if (ast->op == "...") e = std::make_shared<StringType>();
            else e = std::make_shared<BoolType>();
            return e;
        }
    }

    std::any StaticChecker::visitArrayCell(std::shared_ptr<ArrayCell> ast) {
        this->resolved = true;
        std::shared_ptr<Type> arr = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->arr));
        if (arr == nullptr) {
            return std::make_any<std::shared_ptr<Type>>(nullptr);
        }

        if (typeid(*arr).name() != typeid(ArrayType).name()) {
            throw TypeMismatchInExpression(ast);
        }

        else {
            std::shared_ptr<ArrayType> e = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *>(arr.get())));
            if ((int)e->size.size() < (int)ast->idx.size()) {
                throw TypeMismatchInExpression(ast); 
            }

            for (const auto& val: ast->idx) {
                std::shared_ptr<Type> valType = std::any_cast<std::shared_ptr<Type>>(this->visit(val));
                if (valType == nullptr) {
                    if (typeid(*(val)).name() == typeid(Id).name() or typeid(*(val)).name() == typeid(CallExpr).name()) {
                        this->resolve_type(val, std::make_shared<NumberType>());
                        if (not this->resolved) {
                            return std::make_any<std::shared_ptr<Type>>(nullptr);
                        }

                        valType = std::make_shared<NumberType>();
                    }

                    else {
                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                    }
                }

                if (typeid(*valType).name() != typeid(NumberType).name()) {
                    throw TypeMismatchInExpression(ast);
                }
            }

            std::shared_ptr<Type> arrType;
            if ((int)e->size.size() == (int)ast->idx.size()) {
                arrType = e->eleType;
            }

            else {
                std::vector<double> idx = std::vector<double>(e->size.begin() + (int)ast->idx.size(), e->size.end());
                arrType = std::make_shared<ArrayType>(idx, e->eleType);
            }

            return arrType;
        }
    }

    std::any StaticChecker::visitReturn(std::shared_ptr<Return> ast) {
        if (this->has_return) {
            throw UnreachableStatement(ast);
        }

        this->has_return = true;
        this->return_list.push_back(ast);
        if (ast->expr == nullptr) {
            for (int idx = 0; idx < (int)this->symTable.back().size(); idx++) {
                if (typeid(*(this->symTable.back()[idx])).name() == typeid(FuncSym).name()) {
                    std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *> (this->symTable.back()[idx].get())));
                    if (e->name == this->func_name) {
                        if (e->typ == nullptr) {
                            this->symTable.back()[idx] = std::make_shared<FuncSym>(e->name, e->params, std::make_shared<VoidType>(), e->body);
                            break;
                        }

                        else if (typeid(*(e->typ)).name() != typeid(VoidType).name()) {
                            throw TypeMismatchInStatement(ast);
                        }
                    }
                }
            }
        }

        else {
            std::shared_ptr<Type> rettype = std::any_cast<std::shared_ptr<Type>>(this->visit(ast->expr));
            for (int idx = 0; idx < (int)this->symTable.back().size(); idx++) {
                if (typeid(*(this->symTable.back()[idx])).name() == typeid(FuncSym).name()) {
                    std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *> (this->symTable.back()[idx].get())));
                    if (e->name == this->func_name) {
                        if (e->typ == nullptr) {
                            if (rettype == nullptr) {
                                throw TypeCannotBeInferred(ast);
                            }
                            
                            else {
                                this->symTable.back()[idx] = std::make_shared<FuncSym>(e->name, e->params, rettype, e->body);
                                break;
                            }
                        }

                        else {
                            if (typeid(*(e->typ)).name() == typeid(VoidType).name()) {
                                throw TypeMismatchInStatement(ast);
                            }

                            if (rettype == nullptr) {
                                if (typeid(*(ast->expr)).name() == typeid(Id).name() or typeid(*(ast->expr)).name() == typeid(CallExpr).name() or typeid(*(ast->expr)).name() == typeid(ArrayLiteral).name()) {
                                    this->resolve_type(ast->expr, rettype);
                                    if (not this->resolved) {
                                        throw TypeCannotBeInferred(ast);
                                    }

                                    else break;
                                }

                                else {
                                    throw TypeCannotBeInferred(ast);
                                }
                            }

                            else {
                                if (typeid(*(e->typ)).name() != typeid(*rettype).name()) {
                                    throw TypeMismatchInStatement(ast);
                                }

                                else {
                                    if (typeid(*(e->typ)).name() == typeid(ArrayType).name()) {
                                        std::shared_ptr<ArrayType> e1 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (e->typ.get())));
                                        std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (rettype.get())));
                                        if (e2->size.size() > e1->size.size()) throw TypeMismatchInStatement(ast);
                                        if (e2->size.size() == e1->size.size() and e2->size != e1->size) throw TypeMismatchInStatement(ast);
                                        if (e2->eleType == nullptr) {
                                            this->resolve_type(ast->expr, e1);
                                            if (not this->resolved) throw TypeCannotBeInferred(ast);
                                            else e2 = e1;
                                        }

                                        if (typeid(*(e1->eleType)).name() != typeid(*(e2->eleType)).name()) {
                                            throw TypeMismatchInStatement(ast); 
                                        }
                                    }

                                    else break;
                                }
                            }
                        }
                    }
                }
            }
        }
        return std::make_any<std::shared_ptr<Return>>(nullptr);
    }

    std::any StaticChecker::visitCallExpr(std::shared_ptr<CallExpr> ast) {
        this->resolved = true;
        if (this->curr_var_name != "" and ast->name->name == this->curr_var_name) {
            throw TypeMismatchInExpression(ast);
        }

        for (int idx = 0; idx < (int)this->symTable.size() - 1; idx++) {
            std::shared_ptr<Symbol> found = this->lookup(ast->name->name, this->symTable[idx], [](std::shared_ptr<Symbol> x) -> std::string {
                if (typeid(*x).name() == typeid(VarSym).name()) {
                    std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (x.get())));
                    return e->name;
                }
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*> (x.get())));
                return e->name;
            });

            if (found != nullptr) {
                throw TypeMismatchInExpression(ast);
            }
        }

        std::shared_ptr<Symbol> found = this->lookup(ast->name->name, this->symTable.back(), [](std::shared_ptr<Symbol> x) -> std::string {
            if (typeid(*x).name() == typeid(VarSym).name()) {
                std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (x.get())));
                return e->name;
            }
            std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*> (x.get())));
            return e->name;
        });

        if (found == nullptr) {
            throw Undeclared(std::make_shared<Function>(), ast->name->name);
        }

        else {
            if (typeid(*found).name() != typeid(FuncSym).name()) {
                throw TypeMismatchInExpression(ast);
            }
        }

        std::shared_ptr<Type> rettype = nullptr;
        bool flag = false;
        for (int idx = 0; idx < (int)this->symTable.back().size(); idx++) {
            std::shared_ptr<Symbol> found = this->symTable.back()[idx];
            if (typeid(*found).name() != typeid(FuncSym).name()) {
                std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym *>(found.get())));
                if (e->name == ast->name->name) throw TypeMismatchInExpression(ast);
            }
            else {
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *>(found.get())));
                if (e->name == ast->name->name) {
                    if (e->typ != nullptr and typeid(*(e->typ)).name() == typeid(VoidType).name()) {
                        throw TypeMismatchInExpression(ast);
                    }

                    else {
                        flag = true;
                        if ((int)e->params.size() != (int)ast->args.size()) {
                            throw TypeMismatchInExpression(ast);
                        }

                        for (int i = 0; i < (int)e->params.size(); i++) {
                            std::shared_ptr<Expr> arg = ast->args[i];
                            std::shared_ptr<Type> argType = std::any_cast<std::shared_ptr<Type>>(this->visit(arg));
                            if (argType == nullptr) {
                                if (typeid(*arg).name() == typeid(Id).name() or typeid(*arg).name() == typeid(CallExpr).name() or typeid(*arg).name() == typeid(ArrayLiteral).name()) {
                                    this->resolve_type(arg, e->params[i]->typ);
                                    if (not this->resolved) {
                                        return std::make_any<std::shared_ptr<Type>>(nullptr);
                                    }

                                    argType = e->params[i]->typ;
                                }

                                else {
                                    return std::make_any<std::shared_ptr<Type>>(nullptr);
                                }
                            }
                            if (typeid(*argType).name() != typeid(*(e->params[i]->typ)).name()) {
                                throw TypeMismatchInExpression(ast);
                            }

                            else {
                                if (typeid(*argType).name() == typeid(ArrayType).name()) {
                                    std::shared_ptr<ArrayType> e1 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (e->params[i]->typ.get())));
                                    std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (argType.get())));
                                    if (e2->size.size() > e1->size.size()) throw TypeMismatchInExpression(ast);
                                    if (e2->size.size() == e1->size.size() and e2->size != e1->size) throw TypeMismatchInExpression(ast);
                                    if (e2->eleType == nullptr) {
                                        this->resolve_type(ast->args[i], e1);
                                        if (not this->resolved) std::make_any<std::shared_ptr<Type>>(nullptr);
                                        else e2 = e1;
                                    }

                                    if (typeid(*(e1->eleType)).name() != typeid(*(e2->eleType)).name()) {
                                        throw TypeMismatchInExpression(ast); 
                                    }
                                }
                            }
                        }
                        rettype = e->typ;
                    }
                }
            }
        }
        if (not flag) {
            throw Undeclared(std::make_shared<Function>(), ast->name->name);
        }

        return rettype;
    }

    std::any StaticChecker::visitCallStmt(std::shared_ptr<CallStmt> ast) {
        this->resolved = true;
        if (this->curr_var_name != "" and ast->name->name == this->curr_var_name) {
            throw TypeMismatchInStatement(ast);
        }

        for (int idx = 0; idx < (int)this->symTable.size() - 1; idx++) {
            std::shared_ptr<Symbol> found = this->lookup(ast->name->name, this->symTable[idx], [](std::shared_ptr<Symbol> x) -> std::string {
                if (typeid(*x).name() == typeid(VarSym).name()) {
                    std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (x.get())));
                    return e->name;
                }
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*> (x.get())));
                return e->name;
            });

            if (found != nullptr) {
                throw TypeMismatchInStatement(ast);
            }
        }

        std::shared_ptr<Symbol> found = this->lookup(ast->name->name, this->symTable.back(), [](std::shared_ptr<Symbol> x) -> std::string {
            if (typeid(*x).name() == typeid(VarSym).name()) {
                std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym*> (x.get())));
                return e->name;
            }
            std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym*> (x.get())));
            return e->name;
        });

        if (found == nullptr) {
            throw Undeclared(std::make_shared<Function>(), ast->name->name);
        }

        else {
            if (typeid(*found).name() != typeid(FuncSym).name()) {
                throw TypeMismatchInStatement(ast);
            }
        }

        bool flag = false;
        for (int idx = 0; idx < (int)this->symTable.back().size(); idx++) {
            std::shared_ptr<Symbol> found = this->symTable.back()[idx];
            if (typeid(*found).name() != typeid(FuncSym).name()) {
                std::shared_ptr<VarSym> e = std::make_shared<VarSym>(*(dynamic_cast<VarSym *>(found.get())));
                if (e->name == ast->name->name) throw TypeMismatchInStatement(ast);
            }
            else {
                std::shared_ptr<FuncSym> e = std::make_shared<FuncSym>(*(dynamic_cast<FuncSym *>(found.get())));
                if (e->name == ast->name->name) {
                    if (e->typ != nullptr and typeid(*(e->typ)).name() != typeid(VoidType).name()) {
                        throw TypeMismatchInStatement(ast);
                    }

                    else {
                        flag = true;
                        if ((int)e->params.size() != (int)ast->args.size()) {
                            throw TypeMismatchInStatement(ast);
                        }

                        for (int i = 0; i < (int)e->params.size(); i++) {
                            std::shared_ptr<Expr> arg = ast->args[i];
                            std::shared_ptr<Type> argType = std::any_cast<std::shared_ptr<Type>>(this->visit(arg));
                            if (argType == nullptr) {
                                if (typeid(*arg).name() == typeid(Id).name() or typeid(*arg).name() == typeid(CallExpr).name() or typeid(*arg).name() == typeid(ArrayLiteral).name()) {
                                    this->resolve_type(arg, e->params[i]->typ);
                                    if (not this->resolved) {
                                        throw TypeCannotBeInferred(ast);
                                    }

                                    argType = e->params[i]->typ;
                                }

                                else {
                                    throw TypeCannotBeInferred(ast);
                                }
                            }

                            if (typeid(*argType).name() != typeid(*(e->params[i]->typ)).name()) {
                                throw TypeMismatchInStatement(ast);
                            }

                            else {
                                if (typeid(*argType).name() == typeid(ArrayType).name()) {
                                    std::shared_ptr<ArrayType> e1 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (e->params[i]->typ.get())));
                                    std::shared_ptr<ArrayType> e2 = std::make_shared<ArrayType>(*(dynamic_cast<ArrayType *> (argType.get())));
                                    if (e2->size.size() > e1->size.size()) throw TypeMismatchInStatement(ast);
                                    if (e2->size.size() == e1->size.size() and e2->size != e1->size) throw TypeMismatchInStatement(ast);
                                    if (e2->eleType == nullptr) {
                                        this->resolve_type(ast->args[i], e1);
                                        if (not this->resolved) throw TypeCannotBeInferred(ast);
                                        else e2 = e1;
                                    }

                                    if (typeid(*(e1->eleType)).name() != typeid(*(e2->eleType)).name()) {
                                        throw TypeMismatchInStatement(ast); 
                                    }
                                }
                                
                            }
                        }
                        break;
                    }
                }
            }
        }
        if (not flag) {
            throw Undeclared(std::make_shared<Function>(), ast->name->name);
        }
        this->resolve_typeCallStmt(ast);
        return std::make_any<std::shared_ptr<CallStmt>>(nullptr);
    }
}
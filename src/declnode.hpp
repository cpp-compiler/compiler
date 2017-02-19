#pragma once

#include "varnode.hpp"
#include "typenode.hpp"

class DeclNode : public ASTNode {
public:
    VarNode* var;
    TypeNode* type;

    virtual void check(std::vector<SymbolTable>& tables);
    virtual void print();
};

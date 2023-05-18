#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode {
  public:
    Mul(const std::string &repr, ASTNode *lhs, ASTNode *rhs);
    
    virtual int value() const;
};
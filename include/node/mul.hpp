#pragma once

#include <string>

#include "astnode.hpp"

class Mul : public ASTNode {
  public:
    Mul(const std::string &repr, ASTNode *lhs, ASTNode *rhs);

    virtual ~Mul();
    
    virtual int value() const;
};
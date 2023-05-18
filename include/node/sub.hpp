#pragma once

#include <string>

#include "astnode.hpp"

class Sub : public ASTNode {
  public:
    Sub(const std::string &repr, ASTNode *lhs, ASTNode *rhs);
    
    virtual int value() const;
};
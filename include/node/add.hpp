#pragma once

#include <string>

#include "astnode.hpp"

class Add : public ASTNode {
  public:
    Add(const std::string &repr, ASTNode *lhs, ASTNode *rhs);
    
    virtual int value() const;
};
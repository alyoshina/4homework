#pragma once

#include <string>

#include "astnode.hpp"

class Div : public ASTNode {
  public:
    Div(const std::string &repr, ASTNode *lhs, ASTNode *rhs);

    virtual ~Div();

    virtual int value() const;
};
#include "div.hpp"

Div:: Div(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
    : ASTNode(repr, lhs, rhs)
    {}

int Div::value() const {
    return lhs_->value() / rhs_->value();
}
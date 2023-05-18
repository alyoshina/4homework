#include "sub.hpp"

Sub::Sub(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
    : ASTNode(repr, lhs, rhs)
    {}

int Sub::value() const {
    return lhs_->value() - rhs_->value();
}
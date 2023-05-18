#include "mul.hpp"

Mul::Mul(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
    : ASTNode(repr, lhs, rhs)
    {}

int Mul::value() const {
    return lhs_->value() * rhs_->value();
}
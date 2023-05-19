#include "add.hpp"

Add::Add(const std::string &repr, ASTNode *lhs, ASTNode *rhs)
    : ASTNode(repr, lhs, rhs)
    {}

Add::~Add() {}

int Add::value() const {
    return lhs_->value() + rhs_->value();
}
#include "parser.hpp"
#include "number.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mul.hpp"
#include "div.hpp"
#include "variable.hpp"

using Token = Lexer::Token;

Parser::Parser(Lexer &lexer)
        : lexer_(lexer)
        {}

ASTNode *Parser::parse() { 
    return expr();
}

void Parser::next_token() {
    tok_ = lexer_.next_token();
}

ASTNode *Parser::expr() {
    // parse addition and subsctruction
    ASTNode *root = term();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '+':
                // Implement Add class and uncomment this line
                root = new Add(op, root, term());
                break;
            case '-':
                // Implement Sub class and uncomment this line
                root = new Sub(op, root, term());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::term() {
    // parse multiplication and division
    ASTNode *root = prim();
    for (;;) {
        switch (tok_) {
        case Token::Operator: {
            std::string op = lexer_.get_operator();
            switch (op.front()) {
            case '*':
                // Implement Mul class and uncomment this line
                root = new Mul(op, root, prim());
                break;
            case '/':
                // Implement Div class and uncomment this line
                root = new Div(op, root, prim());
                break;
            default:
                return root;
            }
            break;
        }
        default:
            return root;
        }
    }
}

ASTNode *Parser::prim() {
    // parse numbers and names
    ASTNode *node = nullptr;
    next_token();
    switch (tok_) {
    case Token::Number:
        node = new Number(lexer_.get_number());
        break;
    case Token::Name:
        // Implement Variable class and uncomment this line
        node = new Variable(lexer_.get_name());
        break;
    case Token::Lbrace:
        node = expr();
        break;
    case Token::Rbrace:
        break;
    default:
        break;
    }
    next_token();
    return node;
}
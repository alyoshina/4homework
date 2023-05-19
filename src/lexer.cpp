// OTUS C++ Basic course homework skeleton.
// Lexer implementation

#include "lexer.hpp"

#include <cctype>

int Lexer::get_number() const { 
    return number_; 
}

std::string Lexer::get_operator() const {
    return operator_;
}

std::string Lexer::get_name() const {
    return name_;
}

Lexer::Error Lexer::get_error() const {
    return error_;
}

bool Lexer::is_error_token() const {
    if (error_ == Error::Ok) {
        return false;
    }
    return true;
}

int Lexer::get_position() const {
    return cur_position_;
}

std::string Lexer::get_error_str() const {
    std::string str;
    switch (get_error()) {
    case Error::Ok:
        str = "";
        break;
    case Error::Number:
        str = "Unexpected number";
        break;
    case Error::Name:
        str = "Unexpected letter";
        break;
    case Error::Lbrace:
        str = "Unexpected left brace";
        break;
    case Error::Rbrace:
        str = "Unexpected right brace";
        break;
    case Error::Operator:
        str = "Unexpected operator";
        break;
    case Error::End:
        str = "Unexpected symbol at the end";
        break;
    default:
        str = "Some error";
        break;
    }
    return str;
}

Lexer::Token Lexer::set_last_token(Token token) {
    last_token = token;
    return last_token;
}

Lexer::Token Lexer::next_token() {
    for (;;) {
        switch (state_) {
        case State::End:
            return set_last_token(Token::End);
        case State::ReadNumber:
            if (end()) {
                state_ = State::End;
                return set_last_token(Token::Number);
            }
            if (std::isdigit(ch_)) {
                number_ = 10 * number_ + (ch_ - '0');
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            state_ = State::Empty;
            return set_last_token(Token::Number);
        case State::ReadName:
            if (end()) {
                state_ = State::End;
                return set_last_token(Token::Name);
            }
            if (std::isalpha(ch_) || std::isdigit(ch_)) {
                name_ += ch_;
                next_char();
                break;
            }
            state_ = State::Empty;
            return set_last_token(Token::Name);
        case State::Empty:
            if (end()) {
                state_ = State::End;
                if (last_token == Token::Begin || last_token == Token::Operator || last_token == Token::Lbrace) {
                    cur_position_--;
                    error_ = Error::End;
                    return set_last_token(Token::Error);
                }
                return set_last_token(Token::End);
            }
            if (std::isspace(ch_)) {
                next_char();
                break;
            }
            if (isoperator(ch_)) {
                operator_ = ch_;
                if (last_token == Token::Begin || last_token == Token::Lbrace || last_token == Token::Operator) {
                    error_ = Error::Operator;
                    return set_last_token(Token::Error);
                }
                next_char();
                return set_last_token(Token::Operator);
            }
            if (ch_ == '(') {
                if (last_token == Token::Number || last_token == Token::Name) {
                    error_ = Error::Lbrace;
                    return set_last_token(Token::Error);
                }
                next_char();
                return set_last_token(Token::Lbrace);
            }
            if (ch_ == ')') {
                if (last_token == Token::Begin || last_token == Token::Operator) {
                    error_ = Error::Rbrace;
                    return set_last_token(Token::Error);
                }
                next_char();
                return set_last_token(Token::Rbrace);
            }
            if (std::isdigit(ch_)) {
                if (last_token == Token::Number || last_token == Token::Name || last_token == Token::Rbrace) {
                    error_ = Error::Number;
                    return set_last_token(Token::Error);
                }
                number_ = ch_ - '0';
                state_ = State::ReadNumber;
                next_char();
                break;
            }
            if (std::isalpha(ch_)) {
                if (last_token == Token::Number || last_token == Token::Name || last_token == Token::Rbrace) {
                    error_ = Error::Name;
                    return set_last_token(Token::Error);
                }
                name_ = ch_;
                state_ = State::ReadName;
                next_char();
                break;
            }
        }
    }
}

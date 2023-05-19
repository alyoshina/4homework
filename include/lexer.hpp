// OTUS C++ Basic course homework skeleton.
// Lexer interface

#pragma once

#include <istream>
#include <string>

class Lexer {
  public:
    enum class Token {
        Begin,
        Error,
        Number,
        Operator,
        End,
        Lbrace,
        Rbrace,
        Name,
    };

    enum class Error {
        Ok,
        Number,
        Operator,
        End,
        Lbrace,
        Rbrace,
        Name,
    };

    explicit Lexer(std::istream &in);

    Lexer(const Lexer &other) = delete;

    Lexer &operator=(const Lexer &other) = delete;

    Token next_token();

    Token set_last_token(Token token);

    Error get_error() const;

    std::string get_error_str() const;

    bool is_error_token() const;

    int get_number() const;

    std::string get_operator() const;

    std::string get_name() const;

    int get_position() const;
    
  protected:
    bool isbrace(char ch) const;

    bool isoperator(char ch) const;

  private:
    enum class State {
        Empty,
        ReadNumber,
        ReadName,
        End,
    };
    char next_char();
    bool end() const;

    State state_;
    Error error_;
    Token last_token;
    std::string name_;
    int number_;
    std::string operator_;
    char ch_;
    std::istream &in_;
    int cur_position_;

};

inline Lexer::Lexer(std::istream &in)
    : state_(State::Empty)
    , error_(Error::Ok)
    , last_token(Token::Begin)
    , number_(0)
    , in_(in)
    , cur_position_(0) {
    next_char();
}

inline char Lexer::next_char() {
    cur_position_++;
    in_.get(ch_);
    return ch_;
}

inline bool Lexer::end() const { return in_.eof() || ch_ == '\n'; }

inline bool Lexer::isbrace(char ch) const { return ch == '(' || ch == ')'; }

inline bool Lexer::isoperator(char ch) const {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

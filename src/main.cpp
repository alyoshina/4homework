// OTUS C++ Basic course homework skeleton.
// Lexer using example

#include <iostream>

#include "astnode.hpp"
#include "lexer.hpp"
#include "parser.hpp"

int main(int argc, char** argv) {
    // TODO
    // Implement the next classes:
    // Add
    // Sub
    // Mul
    // Div
    // Variable

    // Without implementation that classes this application works only with numbers

    bool only_res = false;
    for (int i = 0; i < argc; i++) {
        std::string arg{ argv[i] };
        if (arg == "-result") {
            only_res = true;
        }
    }

    Lexer lexer(std::cin);
    Parser parser(lexer);

    int result = 0;
    ASTNode *ast = parser.parse();
    if (ast) {
        if (only_res) {
            result = ast->value();
            std::cout << result << std::endl;
        } else {
            ast->print(std::cout);
        } 
    }

    return 0;
}

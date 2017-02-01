#include "lexer.hpp"
#include "parser.hpp"
#include "test.hpp"

int main(int argc, char* argv[]) {
    if (argc == 2 && std::string(argv[1]) == "test") {
        Tester tester;
        tester.specify("assign.ed", "decl.ed",
                       "funcargsret.ed", "funcargsvoid.ed",
                       "funcvoidvoid.ed", "if.ed",
                       "ifelse.ed", "nestedif.ed");
        tester.runAll();
    }
    else {
        Lexer lex(true);
        lex.scan("test.ed");
        lex.print();

        Parser par;
        par.parse(lex.tokens);
        std::cout << "Successfully built AST with " << par.root->seq.size() << " top-level nodes.";
    }
}

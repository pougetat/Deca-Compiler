#include <iostream>
#include "lexer/lexer.h"
#include "syntax/SyntaxParser.h"
#include "context/ContextChecker.h"

using namespace std;

int main(int argc, char * argv[])
{
    bool flag_lexer = false;
    bool flag_syntax = false;

    for (int arg_index = 0; arg_index < argc; arg_index++)
    {
        flag_lexer = flag_lexer || (string("-l").compare(argv[arg_index]) == 0);
        flag_syntax = flag_syntax || (string("-p").compare(argv[arg_index]) == 0);
    }

    // stage 1 : lexing
    string filename(argv[1]);
    Lexer lexer(filename);
    vector<Token> tokens = lexer.tokenize();

    if (flag_lexer)
    {
        for (Token token : tokens)
        {
            cout << "<" <<
                token.m_token_string << "," << token_names[token.m_token_type]
            << ">" << endl;
        }
        return 0;
    }

    // stage 2 : syntax parsing : creating AST
    SyntaxParser syntax_parser(tokens);
    syntax_parser.CreateAST();

    if (flag_syntax)
    {
        syntax_parser.DisplayAST();
        return 0;
    }

    // stage 3 : context checking : walking AST
    ContextChecker context_checker;
    context_checker.CheckContext(syntax_parser.m_program);

    // stage 4 : code generating : walking AST

    return 0;
}
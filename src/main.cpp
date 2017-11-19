#include <iostream>
#include "lexer/lexer.h"
#include "parser/SyntaxParser.h"

using namespace std;

int main(int argc, char * argv[])
{
    // stage 1 : lexing
    Lexer lexer("hello.txt");
    vector<Token> tokens = lexer.tokenize();

    for (Token token : tokens)
    {
        cout << "<" <<
			token.m_token_string << "," << token_names[token.m_token_type]
		<< ">" << endl;
    }

    // stage 2 : syntax parsing : creating AST
    SyntaxParser syntax_parser(tokens);
    syntax_parser.CreateAST();
    syntax_parser.DisplayAST();

    // stage 3 : semantics checking : walking AST

    // stage 4 : code generating : walking AST

    return 0;
}
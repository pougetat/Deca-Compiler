#include <iostream>
#include "lexer/lexer.h"

using namespace std;

int main(int argc, char * argv[])
{
    Lexer lexer("hello.txt");
    vector<Token> tokens = lexer.tokenize();

    for (Token token : tokens)
    {
        cout << "<" <<
			token.m_token_string << "," << token_names[token.m_token_type]
		<< ">" << endl;
    }

    return 0;
}
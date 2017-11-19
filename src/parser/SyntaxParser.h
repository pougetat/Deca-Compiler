#ifndef SYNTAX_PARSER_H
#define SYNTAX_PARSER_H

#include <vector>
#include <ostream>
#include "../lexer/token.h"
#include "AST/AbstractInst.h"
#include "AST/AbstractMain.h"
#include "AST/AbstractPrint.h"
#include "AST/EmptyMain.h"
#include "AST/NonEmptyMain.h"
#include "AST/Program.h"

using namespace std;

class SyntaxParser {

    public:
        SyntaxParser(vector<Token> tokens);
        Program CreateAST();

    private:

        vector<Token> m_tokens;
        Program m_program;

        bool MatchToken(TokenType token_type, int cur_token_index);
        void ConsumeToken(int * cur_token_index);

        // Main rules

        AbstractMain * ParseMain(int * cur_token_index);

        bool MatchEmptyMain(int cur_token_index);
        EmptyMain * ParseEmptyMain(int * cur_token_index);

        bool MatchNonEmptyMain(int cur_token_index);
        NonEmptyMain * ParseNonEmptyMain(int * cur_token_index);

        //

};

#endif
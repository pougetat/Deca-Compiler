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

        bool ParseMain(int * cur_token_index, AbstractMain * main);
        bool ParseEmptyMain(int * cur_token_index, AbstractMain * main);
        bool ParseNonEmptyMain(int * cur_token_index, AbstractMain * main);
        bool ParseInst(int * cur_token_index, AbstractInst * inst);

};

#endif
#ifndef SYNTAX_PARSER_H
#define SYNTAX_PARSER_H

#include <vector>
#include <ostream>
#include "../lexer/token.h"
#include "AST/AbstractMain.h"
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

        vector<DeclClass> ParseListDeclClass(int* cur_token_index);
        AbstractMain ParseMain(int* cur_token_index);
        void ParseListDeclVar(int* cur_token_index);
        void ParseListInst(int* cur_token_index);


};

#endif
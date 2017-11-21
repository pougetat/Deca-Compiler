#ifndef SYNTAX_PARSER_H
#define SYNTAX_PARSER_H

#include <vector>
#include <ostream>
#include "../lexer/token.h"
#include "AST/AbstractExpr.h"
#include "AST/AbstractInst.h"
#include "AST/AbstractMain.h"
#include "AST/AbstractPrint.h"
#include "AST/DeclClass.h"
#include "AST/DeclVar.h"
#include "AST/EmptyMain.h"
#include "AST/Identifier.h"
#include "AST/Initialization.h"
#include "AST/NonEmptyMain.h"
#include "AST/Print.h"
#include "AST/Program.h"

using namespace std;

class SyntaxParser {

    public:

        SyntaxParser(vector<Token> tokens);
        void CreateAST();
        void DisplayAST();

    private:

        vector<Token> m_tokens;
        Program * m_program;

        bool MatchToken(TokenType token_type, int cur_token_index);
        void ConsumeToken(int * cur_token_index);

        // Main rules

        AbstractMain * ParseMain(int * cur_token_index);

        bool MatchEmptyMain(int cur_token_index);
        EmptyMain * ParseEmptyMain(int * cur_token_index);

        bool MatchBlock(int cur_token_index);
        NonEmptyMain * ParseBlock(int * cur_token_index);

        bool MatchListDecl(int cur_token_index);
        vector<DeclVar> * ParseListDecl(int * cur_token_index);

        bool MatchDeclVarSet(int cur_toke_index);
        vector<DeclVar> * ParseDeclVarSet(int * cur_token_index);

        vector<DeclVar> * ParseListDeclVar(int * cur_token_index);

        bool MatchDeclVar(int cur_token_index);
        DeclVar * ParseDeclVar(int * cur_token_index);

        bool MatchIdent(int cur_token_index);
        Identifier * ParseIdentifier(int * cur_token_index);

        bool MatchInitialization(int cur_toke_index);
        Initialization * ParseInitialization(int * cur_token_index);

        bool MatchInst(int cur_token_index);
        AbstractInst * ParseInst(int * cur_token_index);
        
};

#endif
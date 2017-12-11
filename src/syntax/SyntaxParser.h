#ifndef SYNTAX_PARSER_H
#define SYNTAX_PARSER_H

#include <string>
#include "../lexer/token.h"
#include "AST/AbstractBinaryExpr.h"
#include "AST/AbstractExpr.h"
#include "AST/AbstractInst.h"
#include "AST/AbstractLValue.h"
#include "AST/AbstractMain.h"
#include "AST/AbstractOpArith.h"
#include "AST/AbstractOpCmp.h"
#include "AST/AbstractOpExactCmp.h"
#include "AST/AbstractOpIneq.h"
#include "AST/AbstractReadExpr.h"
#include "AST/AbstractUnaryExpr.h"
#include "AST/And.h"
#include "AST/Assign.h"
#include "AST/BooleanLiteral.h"
#include "AST/Cast.h"
#include "AST/DeclClass.h"
#include "AST/DeclVar.h"
#include "AST/Divide.h"
#include "AST/EmptyMain.h"
#include "AST/Equals.h"
#include "AST/Greater.h"
#include "AST/GreaterOrEqual.h"
#include "AST/Identifier.h"
#include "AST/IfThenElse.h"
#include "AST/Initialization.h"
#include "AST/InstanceOf.h"
#include "AST/IntLiteral.h"
#include "AST/Lower.h"
#include "AST/LowerOrEqual.h"
#include "AST/Main.h"
#include "AST/MethodCall.h"
#include "AST/Minus.h"
#include "AST/Modulo.h"
#include "AST/Multiply.h"
#include "AST/New.h"
#include "AST/NoInitialization.h"
#include "AST/NoOperation.h"
#include "AST/Not.h"
#include "AST/NotEquals.h"
#include "AST/Null.h"
#include "AST/Or.h"
#include "AST/Plus.h"
#include "AST/Print.h"
#include "AST/Program.h"
#include "AST/ReadFloat.h"
#include "AST/ReadInt.h"
#include "AST/Return.h"
#include "AST/Selection.h"
#include "AST/StringLiteral.h"
#include "AST/This.h"
#include "AST/UnaryMinus.h"
#include "AST/While.h"

class SyntaxParser {

    public:

        Program * m_program;

        SyntaxParser(vector<Token> tokens);
        void CreateAST();
        void DisplayAST();

    private:

        vector<Token> m_tokens;

        bool MatchToken(TokenType token_type, int cur_token_index);
        void ShouldMatchToken(TokenType token_type, int * cur_token_index);
        void ConsumeToken(int * cur_token_index);

        // GRAMMAR RULES => MAIN RULES

        Program * ParseProgram(int * cur_token_index);

        AbstractMain * ParseMain(int * cur_token_index);

        bool MatchEmptyMain(int cur_token_index);
        EmptyMain * ParseEmptyMain(int * cur_token_index);

        bool MatchBlock(int cur_token_index);
        Main * ParseBlock(int * cur_token_index);

        bool MatchListDecl(int cur_token_index);
        vector<DeclVar *> * ParseListDecl(int * cur_token_index);

        bool MatchDeclVarSet(int cur_toke_index);
        vector<DeclVar *> * ParseDeclVarSet(int * cur_token_index);

        bool MatchListDeclVar(int cur_token_index);
        vector<DeclVar *> * ParseListDeclVar(int * cur_token_index);

        bool MatchDeclVar(int cur_token_index);
        DeclVar * ParseDeclVar(int * cur_token_index);

        bool MatchListInst(int cur_token_index);
        vector<AbstractInst *> * ParseListInst(int * cur_token_index);

        bool MatchInst(int cur_token_index);
        AbstractInst * ParseInst(int * cur_token_index);

        bool MatchIfThenElse(int cur_token_index);
        AbstractInst * ParseIfThenElse(int * cur_toke_index);

        bool MatchListExpr(int cur_token_index);
        vector<AbstractExpr *> * ParseListExpr(int * cur_token_index);

        bool MatchExpr(int cur_token_index);
        AbstractExpr * ParseExpr(int * cur_token_index);

        bool MatchAssignExpr(int cur_token_index);
        AbstractExpr * ParseAssignExpr(int * cur_token_index);

        bool MatchOrExpr(int cur_token_index);
        AbstractExpr * ParseOrExpr(int * cur_token_index);

        bool MatchAndExpr(int cur_token_expr);
        AbstractExpr * ParseAndExpr(int * cur_token_index);

        bool MatchEqNeqExpr(int cur_token_expr);
        AbstractExpr * ParseEqNeqExpr(int * cur_token_expr);

        bool MatchInequalityExpr(int cur_token_expr);
        AbstractExpr * ParseInequalityExpr(int * cur_token_expr);

        bool MatchSumExpr(int cur_token_expr);
        AbstractExpr * ParseSumExpr(int * cur_token_expr);

        bool MatchMultExpr(int cur_token_index);
        AbstractExpr * ParseMultExpr(int * cur_token_expr);

        bool MatchUnaryExpr(int cur_token_index);
        AbstractExpr * ParseUnaryExpr(int * cur_token_expr);

        bool MatchSelectExpr(int cur_toke_index);
        AbstractExpr * ParseSelectExpr(int * cur_token_index);

        bool MatchPrimaryExpr(int cur_token_index);
        AbstractExpr * ParsePrimaryExpr(int * cur_toke_index);

        bool MatchType(int cur_token_index);
        Identifier * ParseType(int * cur_token_index);

        bool MatchLiteral(int cur_token_index);
        AbstractExpr * ParseLiteral(int * cur_token_index);

        bool MatchIdentifier(int cur_token_index);
        Identifier * ParseIdentifier(int * cur_token_index); 

        // GRAMMAR => CLASS RELATED RULES

        bool MatchListClasses(int cur_token_index);
        vector<DeclClass *> * ParseListClasses(int * cur_token_index);

        bool MatchClassDecl(int cur_token_index);
        DeclClass * ParseClassDecl(int * cur_token_index);

        bool MatchClassExtension(int cur_token_index);
        Identifier * ParseClassExtension(int * cur_token_index);
};

#endif
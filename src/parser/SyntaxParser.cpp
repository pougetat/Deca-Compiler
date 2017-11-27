#include "SyntaxParser.h"

SyntaxParser::SyntaxParser(vector<Token> tokens)
{
    m_tokens = tokens;
    m_program = new Program();
}

void SyntaxParser::CreateAST()
{
    int cur_token_index = 0;
    m_program->m_main = ParseMain(&cur_token_index);
}

/*
    main ->
    |   E
    |   block
*/

AbstractMain * SyntaxParser::ParseMain(int * cur_token_index)
{
    if (MatchEmptyMain(*cur_token_index))
    {
        return ParseEmptyMain(cur_token_index);
    }

    if (MatchBlock(*cur_token_index))
    {
        return ParseBlock(cur_token_index);
    }
    else
    {
        throw runtime_error("Expected EMPTY MAIN or NON EMPTY MAIN");
    }
}

bool SyntaxParser::MatchEmptyMain(int cur_token_index)
{
    return MatchToken(TOKEN_EOF, cur_token_index);
}

EmptyMain * SyntaxParser::ParseEmptyMain(int * cur_token_index)
{
    MatchToken(TOKEN_EOF, *cur_token_index);
    ConsumeToken(cur_token_index);

    return new EmptyMain();
}

/*
    block ->
        '{' list_decl list_inst '}'
*/

bool SyntaxParser::MatchBlock(int cur_token_index)
{
    return MatchToken(TOKEN_OBRACE, cur_token_index);
}

NonEmptyMain * SyntaxParser::ParseBlock(int * cur_token_index)
{
    NonEmptyMain * block = new NonEmptyMain();

    ShouldMatchToken(TOKEN_OBRACE, cur_token_index);
    
    if (MatchListDecl(*cur_token_index))
    {
        block->list_decl_var = ParseListDecl(cur_token_index);
    }
    else
    {
        block->list_decl_var = new vector<DeclVar *>();
    }
    
    if (MatchListInst(*cur_token_index))
    {
        block->list_inst = ParseListInst(cur_token_index);
    }
    else
    {
        block->list_inst = new vector<AbstractInst *>();
    }

    ShouldMatchToken(TOKEN_CBRACE, cur_token_index);

    return block;
}

/*
    list_decl ->
        decl_var_set*
*/

bool SyntaxParser::MatchListDecl(int cur_token_index)
{
    return MatchDeclVarSet(cur_token_index);
}

vector<DeclVar *> * SyntaxParser::ParseListDecl(int * cur_token_index)
{
    vector<DeclVar *> * list_decl_var = new vector<DeclVar *>();

    while (MatchDeclVarSet(*cur_token_index))
    {
        vector<DeclVar *> * decl_var_set = ParseDeclVarSet(cur_token_index);

        for (DeclVar * decl_var : *decl_var_set)
        {
            list_decl_var->push_back(decl_var);
        }
    }

    return list_decl_var;
}

/*
    decl_var_set ->
        type list_decl_var ';'
*/

bool SyntaxParser::MatchDeclVarSet(int cur_token_index)
{
    return MatchType(cur_token_index) && MatchListDeclVar(cur_token_index+1);
}

vector<DeclVar *> * SyntaxParser::ParseDeclVarSet(int * cur_token_index)
{
    Identifier * type = ParseIdentifier(cur_token_index);
    vector<DeclVar *> * list_decl_var = ParseListDeclVar(cur_token_index);

    for (DeclVar * decl_var : *list_decl_var)
    {
        decl_var->m_type = type;
    }

    ShouldMatchToken(TOKEN_SEMICOLON, cur_token_index);

    return list_decl_var;
}

bool SyntaxParser::MatchListDeclVar(int cur_token_index)
{
    return MatchDeclVar(cur_token_index);
}

/*
    list_decl_var ->
        decl_var (',' decl_var)*
*/

vector<DeclVar *> * SyntaxParser::ParseListDeclVar(int * cur_token_index)
{
    vector<DeclVar *> * list_decl_var = new vector<DeclVar *>();
    DeclVar * decl_var = ParseDeclVar(cur_token_index);
    list_decl_var->push_back(decl_var);

    while (MatchToken(TOKEN_COMMA, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        list_decl_var->push_back(ParseDeclVar(cur_token_index));
    }

    return list_decl_var;
}

/*
    decl_var ->
        ident ('=' expr)?
*/

bool SyntaxParser::MatchDeclVar(int cur_token_index)
{
    return MatchIdentifier(cur_token_index);
}

DeclVar * SyntaxParser::ParseDeclVar(int * cur_token_index)
{
    DeclVar * decl_var = new DeclVar();

    Identifier * ident = ParseIdentifier(cur_token_index);
    decl_var->m_symbol = ident;

    return decl_var;
}

/*
    list_inst ->
        (inst)*
*/

bool SyntaxParser::MatchListInst(int cur_token_index)
{
    return MatchInst(cur_token_index);
}

vector<AbstractInst *> * SyntaxParser::ParseListInst(int * cur_token_index)
{
    vector<AbstractInst *> * list_inst = new vector<AbstractInst *>();

    while (MatchInst(*cur_token_index))
    {
        AbstractInst * inst = ParseInst(cur_token_index);
        if (inst != NULL)
        {
            list_inst->push_back(inst);
        }

    }

    return list_inst;
}

/*
    inst ->
        | expr ';'
        | ';'
        | 'println' '(' list_expr ')'
        | 'printx' '(' list_expr ')'
        | 'printlnx' '(' list_expr ')'
        | if_then_else
        | 'while' '(' expr ')' '{' list_inst '}'
        | 'return'expr ';'
*/

bool SyntaxParser::MatchInst(int cur_token_index)
{
    return (
        MatchExpr(cur_token_index) ||
        MatchToken(TOKEN_SEMICOLON, cur_token_index) ||
        MatchToken(TOKEN_PRINT, cur_token_index) ||
        MatchToken(TOKEN_PRINTLN, cur_token_index) ||
        MatchToken(TOKEN_PRINTX, cur_token_index) ||
        MatchToken(TOKEN_PRINTLNX, cur_token_index) ||
        MatchToken(TOKEN_WHILE, cur_token_index) ||
        MatchToken(TOKEN_RETURN, cur_token_index)
    );
}

AbstractInst * SyntaxParser::ParseInst(int * cur_token_index)
{
    if (MatchExpr(*cur_token_index))
    {
        AbstractExpr * expr = ParseExpr(cur_token_index);
        ShouldMatchToken(TOKEN_SEMICOLON, cur_token_index);
        return expr;
    }
    if (MatchToken(TOKEN_SEMICOLON, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        // return new NoOperation();
        return NULL;
    }
    else if (
        MatchToken(TOKEN_PRINT, *cur_token_index) ||
        MatchToken(TOKEN_PRINTLN, *cur_token_index) ||
        MatchToken(TOKEN_PRINTX, *cur_token_index) ||
        MatchToken(TOKEN_PRINTLNX, *cur_token_index)
    )
    {
        Print * printInst = new Print(m_tokens.at(*cur_token_index).m_token_type);
        ConsumeToken(cur_token_index);
        
        ShouldMatchToken(TOKEN_OPARENT, cur_token_index);
        //printInst->list_expr = ParseListExpr(cur_token_index);

        ShouldMatchToken(TOKEN_CPARENT, cur_token_index);
        ShouldMatchToken(TOKEN_SEMICOLON, cur_token_index);

        return printInst;
    }
}

/*
    list_expr ->
        (expr
            (',' expr)* )?
*/

bool SyntaxParser::MatchListExpr(int cur_token_index)
{
    return MatchExpr(cur_token_index);
}

vector<AbstractExpr *> * SyntaxParser::ParseListExpr(int * cur_token_index)
{
    vector<AbstractExpr *> * list_expr = new vector<AbstractExpr *>();

    while(MatchExpr(*cur_token_index))
    {
        list_expr->push_back(ParseExpr(cur_token_index));
    }

    return list_expr;
}

/*
    expr ->
        assign_expr
*/

bool SyntaxParser::MatchExpr(int cur_token_index)
{
    return MatchAssignExpr(cur_token_index);
}

AbstractExpr * SyntaxParser::ParseExpr(int * cur_token_index)
{
    return ParseAssignExpr(cur_token_index);
}

/*
    assign_expr ->
        or_expr (
            { condition: expression e must be a "lvalue"}
            '=' assign_expr
        | E )
*/

bool SyntaxParser::MatchAssignExpr(int cur_token_index)
{
    return MatchOrExpr(cur_token_index);
}

AbstractExpr * SyntaxParser::ParseAssignExpr(int * cur_token_index)
{
    return ParseOrExpr(cur_token_index);
}

/*
    or_expr ->
        | and_expr
        | or_expr '||' and_expr
*/

bool SyntaxParser::MatchOrExpr(int cur_token_index)
{
    return MatchAndExpr(cur_token_index);
}

AbstractExpr * SyntaxParser::ParseOrExpr(int * cur_token_index)
{
    AbstractExpr * expr1 = ParseAndExpr(cur_token_index);
    
    if (MatchToken(TOKEN_OR, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        AbstractExpr * expr2 = ParseOrExpr(cur_token_index);
        return new OrExpr(expr1, expr2);
    }
    else
    {
        return expr1;
    }
}

/*
    and_expr ->
        | eq_neq_expr
        | and_expr '&&' eq_neq_expr
*/

AbstractExpr * SyntaxParser::ParseAndExpr(int * cur_token_index)
{
    AbstractExpr * expr1 = ParseEqNeqExpr(cur_token_index);

    if (MatchToken(TOKEN_AND, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        AbstractExpr * expr2 = ParseAndExpr(cur_token_index);
        return new AndExpr(expr1, expr2);
    }
    else {
        return expr1;
    }
}

bool SyntaxParser::MatchAndExpr(int cur_token_index)
{
    return MatchEqNeqExpr(cur_token_index);
}

/*
    eq_neq_expr ->
        | inequality_expr
        | eq_neq_expr '==' inequality_expr
        | eq_neq_expr '!=' inequality_expr
*/

AbstractExpr * SyntaxParser::ParseEqNeqExpr(int * cur_token_index)
{
    AbstractExpr * expr1 = ParseInequalityExpr(cur_token_index);

    if (MatchToken(TOKEN_COMP_EQ, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        AbstractExpr * expr2 = ParseInequalityExpr(cur_token_index);
        return new EqualityExpr(expr1, expr2);
    }
    else if (MatchToken(TOKEN_COMP_NEQ, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        AbstractExpr * expr2 = ParseInequalityExpr(cur_token_index);
        return new InequalityExpr(expr1, expr2);
    }
    else {
        return expr1;
    }
}

bool SyntaxParser::MatchEqNeqExpr(int cur_token_index)
{
    return MatchInequalityExpr(cur_token_index);
}

/*
    inequality_expr ->
        | sum_expr
        | inequality_expr '<=' sum_expr
        | inequality_expr '>=' sum_expr
        | inequality_expr '<' sum_expr
        | inequality_expr '>' sum_expr
        | inequality_expr 'instanceof' type
*/

AbstractExpr * SyntaxParser::ParseInequalityExpr(int * cur_token_index)
{
    return ParseSumExpr(cur_token_index);
}

bool SyntaxParser::MatchInequalityExpr(int cur_token_index)
{
    return MatchSumExpr(cur_token_index);
}

/*
    sum_expr ->
        | mult_expr
        | sum_expr '+' mult_expr
        | sum_expr '-' mult_expr
*/

AbstractExpr * SyntaxParser::ParseSumExpr(int * cur_token_index)
{
    return ParseMultExpr(cur_token_index);
}

bool SyntaxParser::MatchSumExpr(int cur_token_index)
{
    return MatchMultExpr(cur_token_index);
}

/*
    mult_expr ->
        | unary_expr
        | mult_expr '*' unary_expr
        | mult_expr '/' unary_expr
        | mult_expr '%' unary_expr
*/

AbstractExpr * SyntaxParser::ParseMultExpr(int * cur_token_index)
{
    return ParseUnaryExpr(cur_token_index);
}

bool SyntaxParser::MatchMultExpr(int cur_token_index)
{
    return MatchUnaryExpr(cur_token_index);
}

/*
    unary_expr ->
        | '-' unary_expr
        | '!' unary_expr
        | select_expr
*/

AbstractExpr * SyntaxParser::ParseUnaryExpr(int * cur_token_index)
{
    return ParseSelectExpr(cur_token_index);
}

bool SyntaxParser::MatchUnaryExpr(int cur_token_index)
{
    return (
        MatchToken(TOKEN_OP_MINUS, cur_token_index) ||
        MatchToken(TOKEN_NOT, cur_token_index) ||
        MatchSelectExpr(cur_token_index)
    );
}

/*
    select_expr ->
        | primary_expr
        | select_expr '.' ident
            ('(' list_expr ')'
            | E )
*/

AbstractExpr * SyntaxParser::ParseSelectExpr(int * cur_token_index)
{
    return ParsePrimaryExpr(cur_token_index);
}

bool SyntaxParser::MatchSelectExpr(int cur_token_index)
{
    return MatchPrimaryExpr(cur_token_index);
}

/*
    primary_expr ->
        | ident
        | ident '(' list_expr ')'
        | '(' expr ')'
        | 'readInt' '(' ')'
        | 'readFloat' '(' ')'
        | 'new' ident '(' ')'
        | '(' type ')' '(' expr ')'
        | literal
*/

AbstractExpr * SyntaxParser::ParsePrimaryExpr(int * cur_token_index)
{
    if (MatchIdentifier(*cur_token_index))
    {
        return ParseIdentifier(cur_token_index);
    }
    if (MatchLiteral(*cur_token_index))
    {
        return ParseLiteral(cur_token_index);
    }
}

bool SyntaxParser::MatchPrimaryExpr(int cur_token_index)
{
    return (
        MatchIdentifier(cur_token_index) ||
        MatchToken(TOKEN_OPARENT, cur_token_index) ||
        MatchToken(TOKEN_READINT, cur_token_index) ||
        MatchToken(TOKEN_READFLOAT, cur_token_index) ||
        MatchToken(TOKEN_NEW, cur_token_index) ||
        MatchLiteral(cur_token_index)
    );
}

/*
    type ->
        ident
*/

bool SyntaxParser::MatchType(int cur_token_index)
{
    return MatchIdentifier(cur_token_index);
}

Identifier * SyntaxParser::ParseType(int * cur_token_index)
{
    return ParseIdentifier(cur_token_index);
}

/*
    literal ->
        | INT
        | FLOAT
        | STRING
        | 'true''
        | 'false'
        | 'this'
        | 'null'
*/

bool SyntaxParser::MatchLiteral(int cur_token_index)
{
    return (
        MatchToken(TOKEN_LITERAL_INT, cur_token_index) ||
        MatchToken(TOKEN_LITERAL_FLOAT, cur_token_index) ||
        MatchToken(TOKEN_LITERAL_STRING, cur_token_index) ||
        MatchToken(TOKEN_TRUE, cur_token_index) ||
        MatchToken(TOKEN_FALSE, cur_token_index) ||
        MatchToken(TOKEN_THIS, cur_token_index) ||
        MatchToken(TOKEN_NULL, cur_token_index)
    );
}

AbstractExpr * SyntaxParser::ParseLiteral(int * cur_token_index)
{
    if (MatchToken(TOKEN_TRUE, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        return new BooleanLiteral(true);
    }
    if (MatchToken(TOKEN_FALSE, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        return new BooleanLiteral(false);
    }
}

/*
    ident ->
        IDENT
*/

bool SyntaxParser::MatchIdentifier(int cur_token_index)
{
    return MatchToken(TOKEN_IDENT, cur_token_index);
}

Identifier * SyntaxParser::ParseIdentifier(int * cur_token_index)
{
    Identifier * ident = new Identifier(
        m_tokens.at(*cur_token_index).m_token_string
    );
    ConsumeToken(cur_token_index);

    return ident;
}


// Utility methods

bool SyntaxParser::MatchToken(TokenType token_type, int cur_token_index)
{
    return (m_tokens.at(cur_token_index).m_token_type == token_type);
}

void SyntaxParser::ShouldMatchToken(TokenType token_type, int * cur_token_index)
{
    if (!MatchToken(token_type, *cur_token_index))
    {
        throw runtime_error("Expected " + string(token_names[token_type]));
    }
    ConsumeToken(cur_token_index);
}

void SyntaxParser::ConsumeToken(int * cur_token_index)
{
    (*cur_token_index)++;
}

void SyntaxParser::DisplayAST()
{
    m_program->Display("-");
}
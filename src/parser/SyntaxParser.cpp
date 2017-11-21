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

    MatchToken(TOKEN_OBRACE, *cur_token_index);
    ConsumeToken(cur_token_index);

    if (MatchListDecl(*cur_token_index)) {
        block->list_decl_var = ParseListDecl(cur_token_index);
    }

    if (!MatchToken(TOKEN_CBRACE, *cur_token_index))
    {
        throw runtime_error("Expected '}'");
    }
    ConsumeToken(cur_token_index);

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

vector<DeclVar> * SyntaxParser::ParseListDecl(int * cur_token_index)
{
    vector<DeclVar> * list_decl_var = new vector<DeclVar>();

    while (MatchDeclVarSet(*cur_token_index))
    {
        vector<DeclVar> * decl_var_set = ParseDeclVarSet(cur_token_index);

        for (DeclVar & decl_var : *decl_var_set)
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
    return MatchIdent(cur_token_index) && MatchIdent(cur_token_index+1);
}

vector<DeclVar> * SyntaxParser::ParseDeclVarSet(int * cur_token_index)
{
    Identifier * type = ParseIdentifier(cur_token_index);
    vector<DeclVar> * list_decl_var = ParseListDeclVar(cur_token_index);


    for (DeclVar & decl_var : *list_decl_var)
    {
        decl_var.m_type = type;
    }

    if (!MatchToken(TOKEN_SEMICOLON, *cur_token_index))
    {
        throw runtime_error("Expected ';'");
    }
    ConsumeToken(cur_token_index);

    return list_decl_var;
}

/*
    list_decl_var ->
        decl_var (',' decl_var)*
*/

vector<DeclVar> * SyntaxParser::ParseListDeclVar(int * cur_token_index)
{
    vector<DeclVar> * list_decl_var = new vector<DeclVar>();
    DeclVar * decl_var = ParseDeclVar(cur_token_index);
    list_decl_var->push_back(*decl_var);

    while (MatchToken(TOKEN_COMMA, *cur_token_index))
    {
        ConsumeToken(cur_token_index);
        list_decl_var->push_back(*ParseDeclVar(cur_token_index));
    }

    return list_decl_var;
}

/*
    decl_var ->
        ident ('=' expr)?
*/
DeclVar * SyntaxParser::ParseDeclVar(int * cur_token_index)
{
    DeclVar * decl_var = new DeclVar();

    Identifier * ident = ParseIdentifier(cur_token_index);
    decl_var->m_symbol = ident;

    return decl_var;
}

/*


*/

bool SyntaxParser::MatchIdent(int cur_token_index)
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

void SyntaxParser::ConsumeToken(int * cur_token_index)
{
    (*cur_token_index)++;
}

void SyntaxParser::DisplayAST()
{
    m_program->Display("-");
}

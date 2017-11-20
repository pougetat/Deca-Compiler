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
    MAIN ->
    |   EmptyMain
    |   Main[LIST_DECL_VAR LIST_INST]
*/

AbstractMain * SyntaxParser::ParseMain(int * cur_token_index)
{
    int old_token_index = *cur_token_index;
    if (MatchEmptyMain(*cur_token_index))
    {
        *cur_token_index = old_token_index;
        return ParseEmptyMain(cur_token_index);
    }

    *cur_token_index = old_token_index;

    if (MatchNonEmptyMain(*cur_token_index))
    {
        *cur_token_index = old_token_index;
        return ParseNonEmptyMain(cur_token_index);
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

bool SyntaxParser::MatchNonEmptyMain(int cur_token_index)
{
    return MatchToken(TOKEN_OBRACE, cur_token_index);
}

NonEmptyMain * SyntaxParser::ParseNonEmptyMain(int * cur_token_index)
{
    MatchToken(TOKEN_OBRACE, *cur_token_index);
    ConsumeToken(cur_token_index);

    int old_token_index = *cur_token_index;
    while (MatchDeclVar(*cur_token_index)) {
        DeclVar * decl_var = ParseDeclVar(cur_token_index);
    }

    if (!MatchToken(TOKEN_CBRACE, *cur_token_index))
    {
        throw runtime_error("Expected '}'");
    }
    ConsumeToken(cur_token_index);

    return new NonEmptyMain();

}

/*
    DECL_VAR ->
    |   DeclVar[IDENTIFIER IDENTIFIER INITIALIZATION]
*/

bool SyntaxParser::MatchDeclVar(int cur_token_index)
{
    return MatchIdent(cur_token_index) && MatchIdent(cur_token_index+1);
}

DeclVar * SyntaxParser::ParseDeclVar(int * cur_token_index)
{
    
}

bool SyntaxParser::MatchInst(int cur_token_index)
{
}

AbstractInst * SyntaxParser::ParseInst(int * cur_token_index)
{
}

bool SyntaxParser::MatchIdent(int cur_token_index)
{
    return MatchToken(TOKEN_IDENT, cur_token_index);
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

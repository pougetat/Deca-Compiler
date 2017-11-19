#include "SyntaxParser.h"

SyntaxParser::SyntaxParser(vector<Token> tokens)
{
    m_tokens = tokens;
    m_program = Program();
}

Program SyntaxParser::CreateAST()
{
    int cur_token_index = 0;
    m_program.main = ParseMain(&cur_token_index);
}

AbstractMain * SyntaxParser::ParseMain(int * cur_token_index)
{
    if (MatchEmptyMain(*cur_token_index))
    {
        return ParseEmptyMain(cur_token_index);
    }
    else if (MatchNonEmptyMain(*cur_token_index))
    {
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

    if (!MatchToken(TOKEN_CBRACE, *cur_token_index))
    {
        throw runtime_error("Expected '}'");
    }
    ConsumeToken(cur_token_index);

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

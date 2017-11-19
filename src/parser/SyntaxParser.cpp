#include "SyntaxParser.h"

SyntaxParser::SyntaxParser(vector<Token> tokens)
{
    m_tokens = tokens;
    m_program = Program();
}

Program SyntaxParser::CreateAST()
{
    int cur_token_index = 0;
    Token cur_token = m_tokens.at(cur_token_index);
    cur_token_index++;

    // Parsing rules
    AbstractMain main;
    ParseMain(&cur_token_index, &main);

    // setting up Program Node
    m_program.main = main;

}

bool SyntaxParser::ParseMain(int * cur_token_index, AbstractMain * main)
{
    if (!ParseEmptyMain(cur_token_index, main))
    {
        if (!ParseNonEmptyMain(cur_token_index, main))
        {
            throw runtime_error("Expected EMPTY MAIN or NON EMPTY MAIN");
        }
    }
}

bool SyntaxParser::ParseEmptyMain(int * cur_token_index, AbstractMain * main)
{
    if (m_tokens.at(*cur_token_index).m_token_type != TOKEN_EOF)
    {
        return false;
    }
    *main = EmptyMain();
    (*cur_token_index)++;
}

bool SyntaxParser::ParseNonEmptyMain(int * cur_token_index, AbstractMain * main)
{
    if (m_tokens.at(*cur_token_index).m_token_type != TOKEN_OBRACE)
    {
        return false;
    }
    (*cur_token_index)++;

    AbstractInst inst;
    bool is_inst = ParseInst(cur_token_index, &inst);
}

bool SyntaxParser::ParseInst(int * cur_token_index, AbstractInst * inst)
{
    return false;
}

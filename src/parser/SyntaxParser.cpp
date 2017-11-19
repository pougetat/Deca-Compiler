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

    vector<DeclClass> list_decl_class;
    AbstractMain abstract_main;

    //cout << cur_token.m_token_string << endl;
    if (cur_token.m_token_type == TOKEN_CLASS) {
        list_decl_class = ParseListDeclClass(&cur_token_index);
    }
    if (cur_token.m_token_type == TOKEN_OBRACE) {
        abstract_main = ParseMain(&cur_token_index);
    }

    m_program.list_decl_class = list_decl_class;
    m_program.main = abstract_main;

}

vector<DeclClass> SyntaxParser::ParseListDeclClass(int * cur_token_index)
{
    cout << "ParseListDeclClass" << endl;
}

AbstractMain SyntaxParser::ParseMain(int * cur_token_index)
{
    cout << "ParseMain" << endl;

    Token cur_token = m_tokens.at(*cur_token_index);
    AbstractMain main;

    if (cur_token.m_token_type == TOKEN_CBRACE)
    {
        main = EmptyMain();
        return main;
    }
}
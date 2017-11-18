#include "token.h"

Token::Token(){};

Token::Token(TokenType token_type, string token_string) 
{
    m_token_type = token_type;
    m_token_string = token_string;
};
#include "Print.h"

Print::Print(TokenType token_type)
{
    m_token_type = token_type;
}

void Print::Display(string tab)
{
    cout << tab << "-->[PRINT]" << endl;
}
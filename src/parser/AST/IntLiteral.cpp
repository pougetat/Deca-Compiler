#include "IntLiteral.h"

IntLiteral::IntLiteral(int value)
{
    m_value = value;
}

void IntLiteral::Display(string tab)
{
    cout << tab << ">" << "[INT_LITERAL] VALUE : " << m_value << endl;
}
#include "BooleanLiteral.h"

BooleanLiteral::BooleanLiteral(bool value)
{
    m_value = value;
}

void BooleanLiteral::Display(string tab)
{
    cout << tab << ">" << "[BOOLEAN_LITERAL] VALUE : " << m_value << endl;
}
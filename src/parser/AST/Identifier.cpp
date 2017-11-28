#include "Identifier.h"

Identifier::Identifier(string symbol)
{
    m_symbol = symbol;
}

AbstractExpr * Identifier::Clone()
{
    return new Identifier(m_symbol);
}

void Identifier::Display(string tab)
{
    cout << tab << ">" << "[IDENTIFIER] VALUE : " << m_symbol << endl;
}
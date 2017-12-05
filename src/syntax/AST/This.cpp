#include "This.h"

This::This(bool value)
{
    m_value = value;
}

AbstractExpr * This::Clone()
{
    return new This(m_value);
}

void This::Display(string tab)
{
    cout << tab << ">" << "[THIS] VALUE : " << m_value << endl;
}
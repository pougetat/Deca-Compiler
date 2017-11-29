#include "Equals.h"

Equals::Equals(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Equals::Clone()
{
    return new Equals(m_expr1, m_expr2);
}

void Equals::Display(string tab)
{
    cout << tab << ">" << "[EQUALS]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
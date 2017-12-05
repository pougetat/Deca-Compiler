#include "Or.h"

Or::Or(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Or::Clone()
{
    return new Or(m_expr1, m_expr2);
}

void Or::Display(string tab)
{
    cout << tab << ">" << "[OR]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
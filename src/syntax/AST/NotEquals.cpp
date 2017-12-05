#include "NotEquals.h"

NotEquals::NotEquals(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * NotEquals::Clone()
{
    return new NotEquals(m_expr1, m_expr2);
}

void NotEquals::Display(string tab)
{
    cout << tab << ">" << "[NOT EQUALS]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
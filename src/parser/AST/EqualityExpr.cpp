#include "EqualityExpr.h"

EqualityExpr::EqualityExpr(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * EqualityExpr::Clone()
{
    return new EqualityExpr(m_expr1, m_expr2);
}

void EqualityExpr::Display(string tab)
{
    cout << tab << ">" << "[EQUALITY EXPR]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
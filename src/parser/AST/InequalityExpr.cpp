#include "InequalityExpr.h"

InequalityExpr::InequalityExpr(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * InequalityExpr::Clone()
{
    return new InequalityExpr(m_expr1, m_expr2);
}

void InequalityExpr::Display(string tab)
{
    cout << tab << ">" << "[INEQUALITY EXPR]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
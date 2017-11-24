#include "OrExpr.h"

OrExpr::OrExpr(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

void OrExpr::Display(string tab)
{
    cout << tab << ">" << "[OR EXPR]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
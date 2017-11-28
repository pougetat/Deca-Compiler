#include "AndExpr.h"

AndExpr::AndExpr(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * AndExpr::Clone()
{
    return new AndExpr(m_expr1, m_expr2);
}

void AndExpr::Display(string tab)
{
    cout << tab << ">" << "[AND]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
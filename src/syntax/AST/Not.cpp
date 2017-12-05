#include "Not.h"

Not::Not(AbstractExpr * expr)
{
    m_expr = expr;
}

AbstractExpr * Not::Clone()
{
    return new Not(m_expr);
}

void Not::Display(string tab)
{
    cout << tab << ">" << "[NOT]" << endl;
    m_expr->Display(tab + "--");
}
#include "GreaterOrEqual.h"

GreaterOrEqual::GreaterOrEqual(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * GreaterOrEqual::Clone()
{
    return new GreaterOrEqual(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void GreaterOrEqual::Display(string tab)
{
    cout << tab << ">" << "[GREATER OR EQUAL]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
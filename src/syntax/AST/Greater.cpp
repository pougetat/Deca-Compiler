#include "Greater.h"

Greater::Greater(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Greater::Clone()
{
    return new Greater(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void Greater::Display(string tab)
{
    cout << tab << ">" << "[GREATER]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
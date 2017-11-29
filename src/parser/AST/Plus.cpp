#include "Plus.h"

Plus::Plus(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Plus::Clone()
{
    return new Plus(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void Plus::Display(string tab)
{
    cout << tab << ">" << "[PLUS]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
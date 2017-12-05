#include "Lower.h"

Lower::Lower(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Lower::Clone()
{
    return new Lower(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void Lower::Display(string tab)
{
    cout << tab << ">" << "[LOWER]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
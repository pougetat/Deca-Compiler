#include "And.h"

And::And(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * And::Clone()
{
    return new And(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void And::Display(string tab)
{
    cout << tab << ">" << "[AND]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
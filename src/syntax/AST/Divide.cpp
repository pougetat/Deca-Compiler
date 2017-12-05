#include "Divide.h"

Divide::Divide(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Divide::Clone()
{
    return new Divide(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void Divide::Display(string tab)
{
    cout << tab << ">" << "[DIVIDE]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
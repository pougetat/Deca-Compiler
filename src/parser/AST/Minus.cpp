#include "Minus.h"

Minus::Minus(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Minus::Clone()
{
    return new Minus(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void Minus::Display(string tab)
{
    cout << tab << ">" << "[MINUS]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
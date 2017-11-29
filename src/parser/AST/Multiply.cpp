#include "Multiply.h"

Multiply::Multiply(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Multiply::Clone()
{
    return new Multiply(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void Multiply::Display(string tab)
{
    cout << tab << ">" << "[MULTIPLY]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
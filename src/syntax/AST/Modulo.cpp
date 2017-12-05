#include "Modulo.h"

Modulo::Modulo(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * Modulo::Clone()
{
    return new Modulo(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void Modulo::Display(string tab)
{
    cout << tab << ">" << "[MODULO]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
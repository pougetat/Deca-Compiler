#include "LowerOrEqual.h"

LowerOrEqual::LowerOrEqual(AbstractExpr * e1, AbstractExpr * e2)
{
    m_expr1 = e1;
    m_expr2 = e2;
}

AbstractExpr * LowerOrEqual::Clone()
{
    return new LowerOrEqual(
        m_expr1->Clone(), 
        m_expr2->Clone()
    );
}

void LowerOrEqual::Display(string tab)
{
    cout << tab << ">" << "[LOWER OR EQUAL]" << endl;
    m_expr1->Display(tab + "--");
    m_expr2->Display(tab + "--");
}
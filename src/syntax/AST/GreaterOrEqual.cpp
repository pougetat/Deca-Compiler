#include "GreaterOrEqual.h"

GreaterOrEqual::GreaterOrEqual(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * GreaterOrEqual::Clone()
{
    return new GreaterOrEqual(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void GreaterOrEqual::Display(string tab)
{
    cout << tab << ">" << "[GREATER OR EQUAL]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}
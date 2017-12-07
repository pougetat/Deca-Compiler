#include "LowerOrEqual.h"

LowerOrEqual::LowerOrEqual(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * LowerOrEqual::Clone()
{
    return new LowerOrEqual(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void LowerOrEqual::Display(string tab)
{
    cout << tab << ">" << "[LOWER OR EQUAL]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}
#include "Greater.h"

Greater::Greater(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Greater::Clone()
{
    return new Greater(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Greater::Display(string tab)
{
    cout << tab << ">" << "[GREATER]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}
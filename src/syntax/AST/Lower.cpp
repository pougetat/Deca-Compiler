#include "Lower.h"

Lower::Lower(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Lower::Clone()
{
    return new Lower(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Lower::Display(string tab)
{
    cout << tab << ">" << "[LOWER]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}
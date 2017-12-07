#include "Or.h"

Or::Or(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Or::Clone()
{
    return new Or(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Or::Display(string tab)
{
    cout << tab << ">" << "[OR]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}
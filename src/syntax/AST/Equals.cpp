#include "Equals.h"

Equals::Equals(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Equals::Clone()
{
    return new Equals(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Equals::Display(string tab)
{
    cout << tab << ">" << "[EQUALS]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}
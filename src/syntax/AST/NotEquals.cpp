#include "NotEquals.h"

NotEquals::NotEquals(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * NotEquals::Clone()
{
    return new NotEquals(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void NotEquals::Display(string tab)
{
    cout << tab << ">" << "[NOT EQUALS]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}
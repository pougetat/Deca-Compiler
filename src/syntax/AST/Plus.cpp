#include "Plus.h"

Plus::Plus(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Plus::Clone()
{
    return new Plus(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Plus::Display(string tab)
{
    cout << tab << ">" << "[PLUS]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

bool Plus::IsPlus()
{
    return true;
}

bool Plus::IsMinus()
{
    return false;
}

bool Plus::IsMultiply()
{
    return false;
}

bool Plus::IsDivide()
{
    return false;
}

bool Plus::IsModulo()
{
    return false;
}
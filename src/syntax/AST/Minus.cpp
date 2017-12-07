#include "Minus.h"

Minus::Minus(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Minus::Clone()
{
    return new Minus(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Minus::Display(string tab)
{
    cout << tab << ">" << "[MINUS]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

bool Minus::IsPlus()
{
    return false;
}

bool Minus::IsMinus()
{
    return true;
}

bool Minus::IsMultiply()
{
    return false;
}

bool Minus::IsDivide()
{
    return false;
}

bool Minus::IsModulo()
{
    return false;
}
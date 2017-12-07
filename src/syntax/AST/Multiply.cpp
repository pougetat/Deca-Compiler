#include "Multiply.h"

Multiply::Multiply(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Multiply::Clone()
{
    return new Multiply(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Multiply::Display(string tab)
{
    cout << tab << ">" << "[MULTIPLY]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

bool Multiply::IsPlus()
{
    return false;
}

bool Multiply::IsMinus()
{
    return false;
}

bool Multiply::IsMultiply()
{
    return true;
}

bool Multiply::IsDivide()
{
    return false;
}

bool Multiply::IsModulo()
{
    return false;
}
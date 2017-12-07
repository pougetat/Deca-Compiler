#include "Modulo.h"

Modulo::Modulo(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Modulo::Clone()
{
    return new Modulo(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Modulo::Display(string tab)
{
    cout << tab << ">" << "[MODULO]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

bool Modulo::IsPlus()
{
    return false;
}

bool Modulo::IsMinus()
{
    return false;
}

bool Modulo::IsMultiply()
{
    return false;
}

bool Modulo::IsDivide()
{
    return false;
}

bool Modulo::IsModulo()
{
    return true;
}
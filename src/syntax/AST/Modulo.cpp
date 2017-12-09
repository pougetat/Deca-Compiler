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

AbstractType * Modulo::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * type_left_operand = m_left_operand->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );
    AbstractType * type_right_operand = m_right_operand->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );

    if (!type_left_operand->IsIntType() || !type_right_operand->IsIntType())
    {
        throw runtime_error("[MODULO OPERATION : INT OPERAND EXPECTED]");
    }

    return new IntType();
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
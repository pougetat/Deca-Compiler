#include "Assign.h"

Assign::Assign(AbstractExpr * expr, AbstractExpr * assign)
{
    m_left_operand = expr;
    m_right_operand = assign;
}

AbstractExpr * Assign::Clone()
{
    return new Assign(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Assign::Display(string tab)
{
    cout << tab << ">" << "[ASSIGN]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

AbstractType * Assign::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * lvalue_type = m_left_operand->VerifyLValue(
        env_types,
        env_exp,
        class_name
    );

    m_right_operand->VerifyRValue(
        env_types,
        env_exp,
        class_name,
        lvalue_type
    );
}
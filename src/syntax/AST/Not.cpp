#include "Not.h"

Not::Not(AbstractExpr * expr)
{
    m_operand = expr;
}

AbstractExpr * Not::Clone()
{
    return new Not(
        m_operand->Clone()
    );
}

void Not::Display(string tab)
{
    cout << tab << ">" << "[NOT]" << endl;
    m_operand->Display(tab + "--");
}

AbstractType * Not::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * type_operand = m_operand->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );

    if (type_operand->IsBooleanType())
    {
        return new BooleanType();
    }

    throw runtime_error("[NOT : BOOLEAN OPERAND EXPECTED]");
}
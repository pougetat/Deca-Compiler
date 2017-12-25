#include "Return.h"

Return::Return(AbstractExpr * return_expr)
{
    m_return_expr = return_expr;
}

void Return::Display(string tab)
{
    cout << tab << ">" << "[RETURN]" << endl;
    if (m_return_expr != NULL)
    {
        m_return_expr->Display(tab + "--");
    }
}

void Return::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * return_type)
{
    AbstractType * actual_return_type = new VoidType();
    
    if (m_return_expr != NULL)
    {
        actual_return_type = m_return_expr->VerifyExpr(
            env_types,
            env_exp,
            class_name
        );
    }

    if (!return_type->IsSameType(actual_return_type))
    {
        throw runtime_error(
            "[RETURN : EXPECTED " + return_type->Symbol() + " FOUND "
            + actual_return_type->Symbol() + "]"
        );
    }
}
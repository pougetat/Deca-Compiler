#include "Initialization.h"

Initialization::Initialization(AbstractExpr * expr)
{
    m_expr = expr;
}

void Initialization::Display(string tab)
{
    cout << tab << ">" << "[INITIALIZATION]" << endl;
    m_expr->Display(tab + "--");
}

void Initialization::VerifyInitialization(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * type)
{
    m_expr->VerifyRValue(
        env_types,
        env_exp,
        class_name,
        type
    );
}
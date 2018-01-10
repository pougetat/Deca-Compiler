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
    AbstractType * var_type)
{
    m_expr->VerifyRValue(
        env_types,
        env_exp,
        class_name,
        var_type
    );
}

void Initialization::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env,
    AbstractType * var_type)
{
    m_expr->CodeGenExpr(env_types, gen_env);
}
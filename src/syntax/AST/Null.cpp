#include "Null.h"

AbstractExpr * Null::Clone()
{
    return new Null();
}

void Null::Display(string tab)
{
    cout << tab << ">" << "[NULL]" << endl;
}

AbstractType * Null::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    m_expr_type = new NullType();
    return m_expr_type;
}

void Null::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << "    aconst_null" << endl;
}
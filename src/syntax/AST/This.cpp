#include "This.h"

This::This(bool value)
{
    m_value = value;
}

AbstractExpr * This::Clone()
{
    return new This(m_value);
}

void This::Display(string tab)
{
    cout << tab << ">" << "[THIS] VALUE : " << m_value << endl;
}

AbstractType * This::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    m_expr_type = env_types->GetType(*class_name);
    return m_expr_type;
}

void This::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << "    aload_0" << endl;
}
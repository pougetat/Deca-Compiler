#include "IntLiteral.h"

IntLiteral::IntLiteral(int value)
{
    m_value = value;
}

AbstractExpr * IntLiteral::Clone()
{
    return new IntLiteral(m_value);
}

void IntLiteral::Display(string tab)
{
    cout << tab << ">" << "[INT_LITERAL] VALUE : " << m_value << endl;
}

AbstractType * IntLiteral::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    m_expr_type = new IntType();
    return m_expr_type;
}

void IntLiteral::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << "    ; pushing literal on the stack" << endl;
    gen_env->output_file << "    bipush " << m_value << endl;
}
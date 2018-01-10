#include "ReadFloat.h"

AbstractExpr * ReadFloat::Clone()
{
    return new ReadFloat();
}

void ReadFloat::Display(string tab)
{
    cout << tab << ">[READFLOAT]" << endl;
}

AbstractType * ReadFloat::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    m_expr_type = new FloatType();
    return m_expr_type;
}


void ReadFloat::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file
        << "invokestatic java/lang/System.console()Ljava/io/Console;"
        << endl;
    gen_env->output_file
        << "invokevirtual java/io/Console.readLine()Ljava/lang/String;"
        << endl;
    gen_env->output_file
        << "invokestatic  java/lang/Float.parseFloat(Ljava/lang/String;)F"
        << endl;
}
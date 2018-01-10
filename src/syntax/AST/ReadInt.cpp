#include "ReadInt.h"

AbstractExpr * ReadInt::Clone()
{
    return new ReadInt();
}

void ReadInt::Display(string tab)
{
    cout << tab << ">[READINT]" << endl;
}

AbstractType * ReadInt::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    m_expr_type = new IntType();
    return m_expr_type;
}

void ReadInt::CodeGenExpr(
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
        << "invokestatic  java/lang/Integer.parseInt(Ljava/lang/String;)I"
        << endl;
}
#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(AbstractExpr * expr)
{
    m_operand = expr;
}

AbstractExpr * UnaryMinus::Clone()
{
    return new UnaryMinus(
        m_operand->Clone()
    );
}

void UnaryMinus::Display(string tab)
{
    cout << tab << ">" << "[UNARY MINUS]" << endl;
    m_operand->Display(tab + "--");
}

AbstractType * UnaryMinus::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * type_operand = m_operand->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );

    if (type_operand->IsFloatType())
    {
        return new FloatType();
    }
    if (type_operand->IsIntType())
    {
        return new IntType();
    }

    throw runtime_error("[UNARY MINUS : INT OR FLOAT OPERAND EXPECTED]");
}

void UnaryMinus::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << "    ; taking opposite of stack element" << endl;
    gen_env->output_file << "    bipush 0" << endl;
    m_operand->CodeGenExpr(env_types, gen_env);
    gen_env->output_file << "    isub" << endl;
}
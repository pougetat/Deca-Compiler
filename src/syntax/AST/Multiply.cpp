#include "Multiply.h"

Multiply::Multiply(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Multiply::Clone()
{
    return new Multiply(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Multiply::Display(string tab)
{
    cout << tab << ">" << "[MULTIPLY]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

void Multiply::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_left_operand->CodeGenExpr(env_types, gen_env);
    m_right_operand->CodeGenExpr(env_types, gen_env);
    
    gen_env->output_file << "    ; multiplying two stack elements" << endl;
    gen_env->output_file << "    imul" << endl;
}
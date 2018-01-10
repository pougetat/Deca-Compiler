#include "Minus.h"

Minus::Minus(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Minus::Clone()
{
    return new Minus(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Minus::Display(string tab)
{
    cout << tab << ">" << "[MINUS]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

void Minus::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_left_operand->CodeGenExpr(env_types, gen_env);
    m_right_operand->CodeGenExpr(env_types, gen_env);
    
    gen_env->output_file << "    isub" << endl;
}
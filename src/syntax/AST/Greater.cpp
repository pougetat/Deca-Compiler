#include "Greater.h"

Greater::Greater(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Greater::Clone()
{
    return new Greater(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Greater::Display(string tab)
{
    cout << tab << ">" << "[GREATER]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

void Greater::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_left_operand->CodeGenExpr(env_types, gen_env);
    m_right_operand->CodeGenExpr(env_types, gen_env);

    gen_env->output_file << "    ; comp of two stack elements" << endl;
    
    int label_num = gen_env->GetNewLabel();
    gen_env->output_file << "    if_icmpgt label" << label_num << ".true" << endl;
    gen_env->output_file << "    goto label" << label_num << ".false" << endl;
    gen_env->output_file << "    label" << label_num << ".true:" << endl;
    gen_env->output_file << "    bipush 1" << endl;
    gen_env->output_file << "    goto endlabel" << label_num << endl;
    gen_env->output_file << "    label" << label_num << ".false:" << endl;
    gen_env->output_file << "    bipush 0" << endl;
    gen_env->output_file << "    endlabel" << label_num << ":" << endl;
}
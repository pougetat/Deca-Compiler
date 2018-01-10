#include "Equals.h"

Equals::Equals(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Equals::Clone()
{
    return new Equals(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Equals::Display(string tab)
{
    cout << tab << ">" << "[EQUALS]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

void Equals::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_left_operand->CodeGenExpr(env_types, gen_env);
    m_right_operand->CodeGenExpr(env_types, gen_env);

    string branch_instruct = "";
    
    if (m_left_operand->m_expr_type->IsClassType())
    {
        branch_instruct = "if_acmpne";
    }
    if (m_left_operand->m_expr_type->IsIntType())
    {
        branch_instruct = "if_icmpne";
    }
    if (m_left_operand->m_expr_type->IsFloatType())
    {
        gen_env->output_file << "    fcmpl" << endl;
        return;
    }

    int label_num = gen_env->GetNewLabel();

    gen_env->output_file 
        << "    " 
        << branch_instruct << " label" << label_num << ".false" << endl;
    gen_env->output_file << "    goto label" << label_num << ".true" << endl;
    gen_env->output_file << "    label" << label_num << ".true:" << endl;
    gen_env->output_file << "    bipush 1" << endl;
    gen_env->output_file << "    goto endlabel" << label_num << endl;
    gen_env->output_file << "    label" << label_num << ".false:" << endl;
    gen_env->output_file << "    bipush 0" << endl;
    gen_env->output_file << "    endlabel" << label_num << ":" << endl;
}
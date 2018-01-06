#include "Not.h"

Not::Not(AbstractExpr * expr)
{
    m_operand = expr;
}

AbstractExpr * Not::Clone()
{
    return new Not(
        m_operand->Clone()
    );
}

void Not::Display(string tab)
{
    cout << tab << ">" << "[NOT]" << endl;
    m_operand->Display(tab + "--");
}

AbstractType * Not::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * type_operand = m_operand->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );

    if (type_operand->IsBooleanType())
    {
        m_expr_type = new BooleanType();
        return m_expr_type;
    }

    throw runtime_error("[NOT : BOOLEAN OPERAND EXPECTED]");
}

void Not::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_operand->CodeGenExpr(env_types, gen_env);

    gen_env->output_file << "    ; not of stack element" << endl;
    int label_num = gen_env->GetNewLabel();
    gen_env->output_file << "    ifeq label" << label_num << ".true" << endl;
    gen_env->output_file << "    goto label" << label_num << ".false" << endl;
    gen_env->output_file << "" << endl;
    gen_env->output_file << "    label" << label_num << ".true:" << endl;
    gen_env->output_file << "    bipush 1" << endl;
    gen_env->output_file << "    goto endlabel" << label_num << endl;
    gen_env->output_file << "" << endl;
    gen_env->output_file << "    label" << label_num << ".false:" << endl;
    gen_env->output_file << "    bipush 0" << endl;
    gen_env->output_file << "" << endl;
    gen_env->output_file << "    endlabel" << label_num << ":" << endl;
}
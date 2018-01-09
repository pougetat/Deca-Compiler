#include "Assign.h"

Assign::Assign(AbstractExpr * expr, AbstractExpr * assign)
{
    m_left_operand = expr;
    m_right_operand = assign;
}

AbstractExpr * Assign::Clone()
{
    return new Assign(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Assign::Display(string tab)
{
    cout << tab << ">" << "[ASSIGN]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

AbstractType * Assign::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * lvalue_type = m_left_operand->VerifyLValue(
        env_types,
        env_exp,
        class_name
    );

    m_right_operand->VerifyRValue(
        env_types,
        env_exp,
        class_name,
        lvalue_type
    );

    m_expr_type = lvalue_type;
    return m_expr_type;
}

void Assign::CodeGenInst(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_right_operand->CodeGenExpr(env_types, gen_env);

    gen_env->output_file << "    ; storing value in variable" << endl;

    if (m_left_operand->m_expr_type->IsIntType()
        || m_left_operand->m_expr_type->IsBooleanType())
    {
        gen_env->output_file 
            << "    istore " 
            << gen_env->GetMemoryLocation(
                    ((Identifier *) m_left_operand)->m_symbol
                )
            << endl;
    }
    if (m_left_operand->m_expr_type->IsFloatType())
    {
        gen_env->output_file 
            << "    fstore " 
            << gen_env->GetMemoryLocation(
                    ((Identifier *) m_left_operand)->m_symbol
                )
            << endl;
    }
    if (m_left_operand->m_expr_type->IsBooleanType())
    {

    }

}
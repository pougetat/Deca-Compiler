#include "Selection.h"

AbstractExpr * Selection::Clone()
{
    Selection * selection = new Selection();
    selection->m_identifier = new Identifier(m_identifier->m_symbol);
    selection->m_selection_expr = m_selection_expr->Clone();
    return selection;
}

void Selection::Display(string tab)
{
    cout << tab << ">" << "[SELECTION]" << endl;
    m_selection_expr->Display(tab + "--");
    m_identifier->Display(tab + "--");
}

AbstractType * Selection::VerifyLValue(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * class_type = m_selection_expr->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );

    if (!class_type->IsClassType())
    {
        throw runtime_error(
            "[SELECT : LVALUE SHOULD BE A CLASS TYPE]"
        );
    }

    EnvironmentExp * class_env_exp = env_types->GetClassEnvExp(
        ((ClassType *) class_type)->m_class_name
    );

    if (class_env_exp->ContainsSymbol(m_identifier->m_symbol))
    {
        m_expr_type = class_env_exp->GetExpDefinition(m_identifier->m_symbol)->GetType();
        return m_expr_type;
    }
    if (class_env_exp->SupContainsSymbol(m_identifier->m_symbol))
    {
        m_expr_type = class_env_exp->GetSupExpDefinition(m_identifier->m_symbol)->GetType();
        return m_expr_type;
    }
    throw runtime_error(
        "[IDENTIFIER : '" + m_identifier->m_symbol + "' IS NOT A FIELD]"
    );

}

void Selection::CodeGenLValue(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env,
    AbstractExpr * right_operand)
{
    // pushing the reference onto the stack
    m_selection_expr->CodeGenExpr(env_types, gen_env);
    
    // pushing the right operand expr onto the stack
    right_operand->CodeGenExpr(env_types, gen_env);

    ClassType * select_type = (ClassType *) m_selection_expr->m_expr_type;
    gen_env->output_file 
        << "    putfield "
        << select_type->m_class_name
        << "/"
        << m_identifier->m_symbol
        << " " << m_expr_type->JasminSymbol()
        << endl;
}

void Selection::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_selection_expr->CodeGenExpr(env_types, gen_env);
    ClassType * select_type = (ClassType *) m_selection_expr->m_expr_type;
    
    gen_env->output_file 
        << "    getfield "
        << select_type->m_class_name
        << "/"
        << m_identifier->m_symbol
        << " " << m_expr_type->JasminSymbol() << endl;
}
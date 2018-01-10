#include "Cast.h"

Cast::Cast(Identifier * cast_type, AbstractExpr * expr)
{
    m_cast_type = cast_type;
    m_expr = expr;
}

AbstractExpr * Cast::Clone()
{
    return new Cast(
        new Identifier(m_cast_type->m_symbol),
        m_expr->Clone()
    );
}

void Cast::Display(string tab)
{
    cout << tab << ">" << "[CAST]" << endl;
    m_cast_type->Display(tab + "--");
    m_expr->Display(tab + "--");
}

void Cast::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * return_type)
{}

AbstractType * Cast::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * type_operand =
        m_expr->VerifyExpr(env_types, env_exp, class_name);

    if (!env_types->TypeExists(m_cast_type->m_symbol))
    {
        throw runtime_error(
            "[CAST : UNKNOWN TYPE '" + m_cast_type->m_symbol + "']"
        );
    }

    AbstractType * type_cast =
        env_types->GetType(m_cast_type->m_symbol);

    if (!type_cast->IsIntType() && !type_cast->IsFloatType())
    {
        throw runtime_error(
            "[CAST : CANNOT CAST TO '" + m_cast_type->m_symbol + "']"
        );
    }
    if (!type_operand->IsIntType() && !type_operand->IsFloatType())
    {
        throw runtime_error(
            "[CAST : CANNOT CAST FROM '" + m_cast_type->m_symbol + "']"
        );
    }

    m_expr_type = type_cast;
    return m_expr_type;
}

void Cast::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    m_expr->CodeGenExpr(env_types, gen_env);
    
    if (m_expr->m_expr_type->IsIntType())
    {
        if (m_expr_type->IsFloatType())
        {
            gen_env->output_file << "    i2f" << endl;
        }
    }
    if (m_expr->m_expr_type->IsFloatType())
    {
        if (m_expr_type->IsIntType())
        {
            gen_env->output_file << "    f2i" << endl;
        }
    }
}
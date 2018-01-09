#include "Identifier.h"

Identifier::Identifier(string symbol)
{
    m_symbol = symbol;
}

AbstractExpr * Identifier::Clone()
{
    return new Identifier(m_symbol);
}

void Identifier::Display(string tab)
{
    cout << tab << ">" << "[IDENTIFIER] VALUE : " << m_symbol << endl;
}

AbstractType * Identifier::VerifyLValue(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    if (env_exp->ContainsSymbol(m_symbol))
    {
        m_expr_type = env_exp->GetExpDefinition(m_symbol)->GetType();
        return m_expr_type;
    }
    if (env_exp->SupContainsSymbol(m_symbol))
    {
        m_expr_type = env_exp->GetSupExpDefinition(m_symbol)->GetType();
        return m_expr_type;
    }

    throw runtime_error("[IDENTIFIER : '" + m_symbol + "' IS UNDEFINED]");
}

void Identifier::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << "    ; loading variable on the stack" << endl;

    if (m_expr_type->IsIntType() || m_expr_type->IsBooleanType())
    {
        gen_env->output_file 
            << "    iload " << gen_env->GetMemoryLocation(m_symbol)
            << endl;
    }
    if (m_expr_type->IsFloatType())
    {
        gen_env->output_file 
            << "    fload " << gen_env->GetMemoryLocation(m_symbol)
            << endl;
    }
    if (m_expr_type->IsClassType())
    {
        gen_env->output_file
            << "    aload " << gen_env->GetMemoryLocation(m_symbol)
            << endl;
    }
}
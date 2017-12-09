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
    return env_exp->GetDefinition(m_symbol)->GetType();
}
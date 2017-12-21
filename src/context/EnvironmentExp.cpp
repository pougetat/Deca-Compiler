#include "EnvironmentExp.h"

EnvironmentExp::EnvironmentExp()
{
    m_env_exp = new map<string, ExpDefinition *>();
    m_env_exp_sup = NULL;
}

void EnvironmentExp::SetParentEnvExp(EnvironmentExp * parent_env_exp)
{
    m_env_exp_sup = parent_env_exp; 
}

void EnvironmentExp::InsertExpDefinition(
    string exp_symbol,
    ExpDefinition * exp_def)
{
    if (m_env_exp->find(exp_symbol) != m_env_exp->end())
    {
        throw runtime_error(
            "[DECLARATION : '" + exp_symbol + "' ALREADY EXISTS]"
        );
    }

    m_env_exp->insert(
        pair<string, ExpDefinition*>(
            exp_symbol,
            exp_def
        )
    );
}

bool EnvironmentExp::ContainsSymbol(string exp_symbol)
{
    return (m_env_exp->find(exp_symbol) != m_env_exp->end());
}

bool EnvironmentExp::SupContainsSymbol(string exp_symbol)
{
    if (m_env_exp_sup == NULL)
    {
        return false;
    }

    return (
        m_env_exp_sup->ContainsSymbol(exp_symbol) ||
        m_env_exp_sup->SupContainsSymbol(exp_symbol)
    );
}

ExpDefinition * EnvironmentExp::GetExpDefinition(string exp_symbol)
{
    return m_env_exp->find(exp_symbol)->second;
}

ExpDefinition * EnvironmentExp::GetSupExpDefinition(string exp_symbol)
{
    if (SupContainsSymbol(exp_symbol))
    {
        return m_env_exp_sup->m_env_exp->find(exp_symbol)->second;
    }
    return m_env_exp_sup->GetSupExpDefinition(exp_symbol);
}
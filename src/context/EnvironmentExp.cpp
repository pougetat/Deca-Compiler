#include "EnvironmentExp.h"

EnvironmentExp::EnvironmentExp()
{
    m_env_exp = new map<string, ExpDefinition *>();
}

void EnvironmentExp::InsertExp(string exp_symbol, ExpDefinition * exp_def)
{
    if (m_env_exp->find(exp_symbol) != m_env_exp->end())
    {
        throw runtime_error("[DECLARATION : '" + exp_symbol + "' ALREADY EXISTS]");
    }

    m_env_exp->insert(
        pair<string, ExpDefinition*>(
            exp_symbol,
            exp_def
        )
    );
}

ExpDefinition * EnvironmentExp::GetDefinition(string exp_symbol)
{
    return m_env_exp->find(exp_symbol)->second;
}
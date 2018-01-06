#include "GeneratorEnvironment.h"

GeneratorEnvironment::GeneratorEnvironment(EnvironmentExp * env_exp)
{
    m_env_exp = env_exp;
}

void GeneratorEnvironment::IncrNumVars()
{
    m_num_vars++;
}

void GeneratorEnvironment::SetMemoryLocation(string var_symbol)
{
    m_env_exp
        ->GetExpDefinition(var_symbol)
        ->SetMemoryLocation(m_num_vars);
}

int GeneratorEnvironment::GetMemoryLocation(string var_symbol)
{
    return 
        m_env_exp->GetExpDefinition(var_symbol)->GetMemoryLocation();
}
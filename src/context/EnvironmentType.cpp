#include "EnvironmentType.h"

EnvironmentType::EnvironmentType()
{
    m_env_types->insert(
        pair<string, TypeDefinition>(
            "int",
            *(new TypeDefinition(
                new TypeTypeNature(),
                new IntType()
            ))
        )
    );
    m_env_types->insert(
        pair<string, TypeDefinition>(
            "float",
            *(new TypeDefinition(
                new TypeTypeNature(),
                new FloatType()
            ))
        )
    );
    m_env_types->insert(
        pair<string, TypeDefinition>(
            "boolean",
            *(new TypeDefinition(
                new TypeTypeNature(),
                new BooleanType()
            ))
        )
    );
}

bool EnvironmentType::TypeExists(string type_symbol)
{
    return m_env_types->find(type_symbol) == m_env_types->end();
}
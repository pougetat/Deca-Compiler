#include "EnvironmentType.h"

EnvironmentType::EnvironmentType()
{
    m_env_types = new map<string, TypeDefinition *>();

    m_env_types->insert(
        pair<string, TypeDefinition *>(
            "int",
            new TypeDefinition(
                new TypeTypeNature(),
                new IntType()
            )
        )
    );
    m_env_types->insert(
        pair<string, TypeDefinition *>(
            "float",
            new TypeDefinition(
                new TypeTypeNature(),
                new FloatType()
            )
        )
    );
    m_env_types->insert(
        pair<string, TypeDefinition *>(
            "boolean",
            new TypeDefinition(
                new TypeTypeNature(),
                new BooleanType()
            )
        )
    );
    m_env_types->insert(
        pair<string, TypeDefinition *>(
            "void",
            new TypeDefinition(
                new TypeTypeNature(),
                new VoidType()
            )
        )
    );
    m_env_types->insert(
        pair<string, TypeDefinition *>(
            "Object",
            new TypeDefinition(
                new ClassTypeNature(""),
                new ClassType("Object")
            )
        )
    );
}

bool EnvironmentType::TypeExists(string type_symbol)
{
    return m_env_types->find(type_symbol) != m_env_types->end();
}

TypeDefinition * EnvironmentType::GetTypeDefinition(string type_def_symbol)
{
    return m_env_types->find(type_def_symbol)->second;
}

AbstractType * EnvironmentType::GetType(string type_symbol)
{
    return GetTypeDefinition(type_symbol)->GetType();
}

void EnvironmentType::InsertType(string type_symbol, TypeDefinition * type_def)
{
    m_env_types->insert(
        pair<string, TypeDefinition *>(
            type_symbol,
            type_def
        )
    );
}

EnvironmentExp * EnvironmentType::GetClassEnvExp(string class_name)
{
    ClassTypeNature * class_type_nature = (ClassTypeNature *)
        m_env_types->find(class_name)->second->GetTypeNature();
    return class_type_nature->GetEnvExp();
}
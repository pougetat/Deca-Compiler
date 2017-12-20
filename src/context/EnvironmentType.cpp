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

void EnvironmentType::AddTypeToSignature(
    string class_name,
    string method_name,
    AbstractType * param_type)
{
    TypeDefinition * class_def = GetTypeDefinition(class_name);

    ClassTypeNature * class_type_nat = 
        (ClassTypeNature *) class_def->GetTypeNature();

    EnvironmentExp * class_env_exp = class_type_nat->GetEnvExp();

    ExpDefinition * method_def = class_env_exp->GetExpDefinition(method_name);

    MethodExpNature * method_exp_nature = 
        (MethodExpNature *) method_def->GetTypeNature();

    method_exp_nature->InsertSignatureType(param_type);
}
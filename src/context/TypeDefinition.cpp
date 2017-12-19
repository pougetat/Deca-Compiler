#include "TypeDefinition.h"

TypeDefinition::TypeDefinition(
    AbstractTypeNature * type_nature, 
    AbstractType * type)
{
    m_type_nature = type_nature;
    m_type = type;
}

AbstractType * TypeDefinition::GetType()
{
    return m_type;
}

AbstractTypeNature * TypeDefinition::GetTypeNature()
{
    return m_type_nature;
}
#include "TypeDefinition.h"

TypeDefinition::TypeDefinition(
    AbstractTypeNature * type_nature, 
    AbstractType * type)
{
    m_type_nature = type_nature;
    m_type = type;
}
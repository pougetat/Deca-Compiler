#include "ExpDefinition.h"

ExpDefinition::ExpDefinition(
    AbstractExpNature * exp_nature, 
    AbstractType * type)
{
    m_exp_nature = exp_nature;
    m_type = type;
}

AbstractType * ExpDefinition::GetType()
{
    return m_type;
}
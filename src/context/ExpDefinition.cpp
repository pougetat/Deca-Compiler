#include "ExpDefinition.h"

ExpDefinition::ExpDefinition(
    AbstractExpNature * exp_nature, 
    AbstractType * type)
{
    m_exp_nature = exp_nature;
    m_type = type;
    m_memory_location = -1;
}

void ExpDefinition::SetMemoryLocation(int memory_location)
{
    m_memory_location = memory_location;
}

AbstractType * ExpDefinition::GetType()
{
    return m_type;
}

AbstractExpNature * ExpDefinition::GetTypeNature()
{
    return m_exp_nature;
}

int ExpDefinition::GetMemoryLocation()
{
    return m_memory_location;
}
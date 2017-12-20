#include "ClassTypeNature.h"

ClassTypeNature::ClassTypeNature(string super_class_name)
{
    m_parent_class_name = super_class_name;
    m_class_env_exp = new EnvironmentExp();
}

EnvironmentExp * ClassTypeNature::GetEnvExp()
{
    return m_class_env_exp;
}

void ClassTypeNature::SetParentClass(string parent_class_symbol)
{
    m_parent_class_name = parent_class_symbol;
}
#include "ClassTypeNature.h"

ClassTypeNature::ClassTypeNature(string super_class_name)
{
    m_super_class_name = super_class_name;
    m_class_env_exp = new EnvironmentExp();
}
#include "MethodExpNature.h"

MethodExpNature::MethodExpNature()
{
    m_env_exp = new EnvironmentExp();
    m_signature = new vector<AbstractType *>();
}

void MethodExpNature::InsertSignatureType(AbstractType * type)
{
    m_signature->push_back(type);   
}

bool MethodExpNature::IsParamExpNature()
{
    return false;
}

bool MethodExpNature::IsVarExpNature()
{
    return false;
}

bool MethodExpNature::IsMethodExpNature()
{
    return true;
}

bool MethodExpNature::IsFieldExpNature()
{
    return false;
}
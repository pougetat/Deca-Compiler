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
#include "MethodExpNature.h"

MethodExpNature::MethodExpNature()
{
    m_method_env = new EnvironmentExp();
    m_signature = new vector<AbstractType *>();
}

EnvironmentExp * MethodExpNature::GetMethodEnv()
{
    return m_method_env;
}

vector<AbstractType *> * MethodExpNature::GetMethodSignature()
{
    return m_signature;
}

void MethodExpNature::InsertSignatureType(AbstractType * type)
{
    m_signature->push_back(type);   
}

bool MethodExpNature::HasSameSignature(MethodExpNature * other_method_exp_nature)
{
    if (m_signature->size() != other_method_exp_nature->GetMethodSignature()->size())
    {
        return false;
    }

    for (AbstractType * sig_type : *m_signature)
    {
        if (!sig_type->IsSameType(
                other_method_exp_nature->GetMethodSignature()->at(0)))
        {
            return false;
        }
    }
    
    return true;
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
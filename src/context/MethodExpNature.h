#ifndef METHOD_EXP_NATURE_H
#define METHOD_EXP_NATURE_H

#include "EnvironmentExp.h"
#include <vector>

using namespace std;

class MethodExpNature : public AbstractExpNature
{

    public:

        EnvironmentExp * m_method_env;

        vector<AbstractType *> * m_signature;

        MethodExpNature(string englobing_class);

        EnvironmentExp * GetMethodEnv();

        vector<AbstractType *> * GetMethodSignature();

        void InsertSignatureType(AbstractType * type);

        bool HasSameSignature(MethodExpNature * other_method_exp_nature);

        bool IsParamExpNature();
        
        bool IsVarExpNature();
        
        bool IsMethodExpNature();
        
        bool IsFieldExpNature();
};

#endif
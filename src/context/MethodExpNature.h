#ifndef METHOD_EXP_NATURE_H
#define METHOD_EXP_NATURE_H

#include "EnvironmentExp.h"
#include <vector>

using namespace std;

class MethodExpNature : public AbstractExpNature
{

    public:

        EnvironmentExp * m_env_exp;

        vector<AbstractType *> * m_signature;

        MethodExpNature();

        void InsertSignatureType(AbstractType * type);

};

#endif
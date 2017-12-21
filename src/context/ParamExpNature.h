#ifndef PARAM_EXP_NATURE_H
#define PARAM_EXP_NATURE_H

#include "EnvironmentExp.h"

class ParamExpNature : public AbstractExpNature
{
    public:
        virtual bool IsParamExpNature();
        virtual bool IsVarExpNature();
        virtual bool IsMethodExpNature();
        virtual bool IsFieldExpNature();
};

#endif
#ifndef VAR_EXP_NATURE_H
#define VAR_EXP_NATURE_H

#include "AbstractExpNature.h"

class VarExpNature : public AbstractExpNature
{
    public:
        virtual bool IsParamExpNature();
        virtual bool IsVarExpNature();
        virtual bool IsMethodExpNature();
        virtual bool IsFieldExpNature();
};

#endif
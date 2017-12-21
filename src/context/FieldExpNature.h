#ifndef FIELD_EXP_NATURE
#define FIELD_EXP_NATURE

#include "AbstractExpNature.h"

class FieldExpNature : public AbstractExpNature
{
    public:
        virtual bool IsParamExpNature();
        virtual bool IsVarExpNature();
        virtual bool IsMethodExpNature();
        virtual bool IsFieldExpNature();
};

#endif
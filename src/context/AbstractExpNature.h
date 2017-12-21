#ifndef ABSTRACT_EXP_NATURE_H
#define ABSTRACT_EXP_NATURE_H

class AbstractExpNature
{
    public:
        virtual bool IsParamExpNature() = 0;
        virtual bool IsVarExpNature() = 0;
        virtual bool IsMethodExpNature() = 0;
        virtual bool IsFieldExpNature() = 0;
};

#endif
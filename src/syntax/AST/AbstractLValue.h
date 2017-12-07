#ifndef ABSTRACT_LVALUE_EXPR
#define ABSTRACT_LVALUE_EXPR

#include "AbstractExpr.h"

class AbstractLValue : public AbstractExpr
{
    public:
        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name
        );
};

#endif
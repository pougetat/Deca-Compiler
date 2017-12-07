#ifndef ABSTRACT_UNARY_EXPR
#define ABSTRACT_UNARY_EXPR

#include "AbstractExpr.h"

class AbstractUnaryExpr : public AbstractExpr
{
    public:
        AbstractType * VerifyExpr(
                EnvironmentType * env_types,
                EnvironmentExp * env_exp,
                string class_name
        );
};

#endif
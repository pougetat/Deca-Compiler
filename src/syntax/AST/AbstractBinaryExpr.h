#ifndef ABSTRACT_BINARY_EXPR
#define ABSTRACT_BINARY_EXPR

#include "AbstractExpr.h"

class AbstractBinaryExpr : public AbstractExpr
{
    public:
        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name);
};

#endif
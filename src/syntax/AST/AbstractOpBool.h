#ifndef ABSTRACT_OP_BOOL_H
#define ABSTRACT_OP_BOOL_H

#include "AbstractBinaryExpr.h"

class AbstractOpBool : public AbstractBinaryExpr
{
    public:

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
};

#endif
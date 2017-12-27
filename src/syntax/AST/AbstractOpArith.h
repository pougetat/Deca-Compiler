#ifndef ABSTRACT_OP_ARITH_H
#define ABSTRACT_OP_ARITH_H

#include "AbstractBinaryExpr.h"

class AbstractOpArith : public AbstractBinaryExpr
{
    public:

        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
};

#endif
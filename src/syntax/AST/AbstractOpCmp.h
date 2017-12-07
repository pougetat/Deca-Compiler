#ifndef ABSTRACT_OP_CMP_H
#define ABSTRACT_OP_CMP_H

#include "AbstractBinaryExpr.h"

class AbstractOpCmp : public AbstractBinaryExpr
{
    public:
        
        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name
        );
};

#endif
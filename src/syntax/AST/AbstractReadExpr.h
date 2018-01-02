#ifndef ABSTRACT_READ_EXPR_H
#define ABSTRACT_READ_EXPR_H

#include "AbstractExpr.h"

class AbstractReadExpr : public AbstractExpr
{
    public:
    
        virtual void Display(string tab) = 0;
        
        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );

        virtual void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
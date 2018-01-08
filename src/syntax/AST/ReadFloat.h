#ifndef READFLOAT_H
#define READFLOAT_H

#include "AbstractReadExpr.h"

class ReadFloat : public AbstractReadExpr
{
    public:
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
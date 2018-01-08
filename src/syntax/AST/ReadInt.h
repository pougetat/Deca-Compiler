#ifndef READINT_H
#define READINT_H

#include <iostream>
#include "AbstractReadExpr.h"

using namespace std;

class ReadInt : public AbstractReadExpr
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
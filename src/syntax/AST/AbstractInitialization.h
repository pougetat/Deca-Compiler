#ifndef ABSTRACT_INITIALIZATION_H
#define ABSTRACT_INITIALIZATION_H

#include <iostream>
#include "AbstractExpr.h"

using namespace std;

class AbstractInitialization
{
    public:

        virtual void Display(string tab) = 0;

        virtual void VerifyInitialization(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * type
        ) = 0;

        virtual void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env,
            AbstractType * var_type
        ) = 0;
};

#endif
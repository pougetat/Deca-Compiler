#ifndef NULL_H
#define NULL_H

#include "AbstractLiteral.h"
#include "../../context/NullType.h"

class Null : public AbstractLiteral
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
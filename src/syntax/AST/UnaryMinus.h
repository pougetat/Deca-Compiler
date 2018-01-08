#ifndef UNARY_MINUS_H
#define UNARY_MINUS_H

#include "AbstractUnaryExpr.h"

class UnaryMinus : public AbstractUnaryExpr
{
    public:

        UnaryMinus(AbstractExpr * expr);
        
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
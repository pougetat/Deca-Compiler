#ifndef ABSTRACT_LVALUE_EXPR
#define ABSTRACT_LVALUE_EXPR

#include "AbstractExpr.h"

class AbstractLValue : public AbstractExpr
{
    public:

        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name            
        );

        virtual AbstractType * VerifyLValue(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name            
        );

        virtual void CodeGenLValue(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env,
            AbstractExpr * right_operand
        );

        virtual void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
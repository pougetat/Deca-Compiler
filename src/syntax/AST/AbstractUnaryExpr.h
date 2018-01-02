#ifndef ABSTRACT_UNARY_EXPR
#define ABSTRACT_UNARY_EXPR

#include "AbstractExpr.h"

class AbstractUnaryExpr : public AbstractExpr
{
    public:

        AbstractExpr * m_operand;

        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        ) = 0;

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
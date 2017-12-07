#ifndef ABSTRACT_BINARY_EXPR
#define ABSTRACT_BINARY_EXPR

#include "AbstractExpr.h"

class AbstractBinaryExpr : public AbstractExpr
{
    public:

        AbstractExpr * m_left_operand;
        AbstractExpr * m_right_operand;

        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name
        );
};

#endif
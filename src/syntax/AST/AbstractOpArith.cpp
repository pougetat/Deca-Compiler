#include "AbstractOpArith.h"

AbstractType * AbstractOpArith::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name)
{
    AbstractType * type_left_operand = m_left_operand->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );
    AbstractType * type_right_operand = m_right_operand->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );

    return NULL;
}
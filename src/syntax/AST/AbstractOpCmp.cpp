#include "AbstractOpCmp.h"

AbstractType * AbstractOpCmp::VerifyExpr(
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

    if (!(type_left_operand->IsFloatType() || type_left_operand->IsIntType())
        || !(type_right_operand->IsFloatType() || type_right_operand->IsIntType()))
    {
        throw runtime_error(
            "[COMP OPERATION : INT OR FLOAT OPERAND EXPECTED]"
        );
    }

    if (type_left_operand->IsFloatType() || type_right_operand->IsFloatType())
    {
        return new FloatType();
    }

    return new IntType();
}
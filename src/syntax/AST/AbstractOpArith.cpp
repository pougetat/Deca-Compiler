#include "AbstractOpArith.h"

AbstractType * AbstractOpArith::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
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

    if (!type_left_operand->IsIntType() && !type_left_operand->IsFloatType())
    {
        throw runtime_error("[ARITH OPERATION : INT OR FLOAT OPERAND EXPECTED]");
    }
    if (!type_right_operand->IsIntType() && !type_right_operand->IsFloatType())
    {
        throw runtime_error("[ARITH OPERATION : INT OR FLOAT OPERAND EXPECTED]");
    }

    if (type_left_operand->IsFloatType())
    {
        m_expr_type = new FloatType();
        return new FloatType();
    }
    if (type_left_operand->IsIntType())
    {
        m_expr_type = type_right_operand;
        return type_right_operand;
    }
}
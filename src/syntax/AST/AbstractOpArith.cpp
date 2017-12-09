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

    if (type_left_operand->IsFloatType())
    {
        if (type_right_operand->IsFloatType() || type_right_operand->IsIntType())
        {
            return new FloatType();
        }
        throw runtime_error("[ARITH OPERATION : INT OR FLOAT OPERAND EXPECTED]");
    }
    if (type_left_operand->IsIntType())
    {
        if (type_right_operand->IsFloatType())
        {
            return new FloatType();
        }
        if (type_right_operand->IsIntType())
        {
            return new IntType();
        }
        throw runtime_error("[ARITH OPERATION : INT OR FLOAT OPERAND EXPECTED]");
    }

    throw runtime_error("[ARITH OPERATION : INT OR FLOAT OPERAND EXPECTED]");
}
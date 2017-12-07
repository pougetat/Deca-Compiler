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

    if (IsModulo())
    {
        cout << "hello" << endl;
        if (!type_left_operand->IsIntType() || !type_right_operand->IsIntType())
        {
            cout << "hey" << endl;
            throw runtime_error("[MODULO OPERATION : INT OPERAND EXPECTED");
        }
    }

    if (type_left_operand->IsFloatType() || type_right_operand->IsFloatType())
    {
        return new FloatType();
    }
    if (type_left_operand->IsIntType() && type_right_operand->IsIntType())
    {
        return new IntType();
    }

    throw runtime_error("[ARITH OPERATION : INT OR FLOAT OPERAND EXPECTED]");
}
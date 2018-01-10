#include "AbstractOpCmp.h"

AbstractType * AbstractOpCmp::VerifyExpr(
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

    if (!(type_left_operand->IsSameType(type_right_operand)))
    {
        throw runtime_error(
            "[COMP OPERATIN : OPERANDS CANNOT BE OF DIFFERENT TYPES"
        );
    }
    if (!type_left_operand->IsFloatType() 
        && !type_left_operand->IsIntType()
        && !type_left_operand->IsClassType())
    {
        throw runtime_error(
            "[COMP OPERATION : INT OR FLOAT OPERAND EXPECTED]"
        );
    }

    m_expr_type = new BooleanType();
    return m_expr_type;
}
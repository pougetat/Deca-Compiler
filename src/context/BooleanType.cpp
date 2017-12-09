#include "BooleanType.h"

bool BooleanType::IsBooleanType()
{
    return true;
}

bool BooleanType::IsFloatType()
{
    return false;
}

bool BooleanType::IsIntType()
{
    return false;
}

bool BooleanType::IsStringType()
{
    return false;
}

bool BooleanType::IsVoidType()
{
    return false;
}

bool BooleanType::IsSameType(AbstractType * other_type)
{
    return other_type->IsBooleanType();
}
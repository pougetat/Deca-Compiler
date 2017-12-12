#include "VoidType.h"

bool VoidType::IsBooleanType()
{
    return false;
}

bool VoidType::IsFloatType()
{
    return false;
}

bool VoidType::IsIntType()
{
    return false;
}

bool VoidType::IsStringType()
{
    return false;
}

bool VoidType::IsVoidType()
{
    return true;
}

bool VoidType::IsClassType()
{
    return false;
}

bool VoidType::IsSameType(AbstractType * other_type)
{
    return other_type->IsVoidType();
}
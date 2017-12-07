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
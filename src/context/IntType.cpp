#include "IntType.h"

bool IntType::IsBooleanType()
{
    return false;
}

bool IntType::IsFloatType()
{
    return false;
}

bool IntType::IsIntType()
{
    return true;
}

bool IntType::IsStringType()
{
    return false;
}

bool IntType::IsVoidType()
{
    return false;
}
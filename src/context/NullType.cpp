#include "NullType.h"

bool NullType::IsBooleanType()
{
    return false;
}

bool NullType::IsFloatType()
{
    return false;
}

bool NullType::IsIntType()
{
    return true;
}

bool NullType::IsStringType()
{
    return false;
}

bool NullType::IsVoidType()
{
    return false;
}

bool NullType::IsClassType()
{
    return false;
}

bool NullType::IsNullType()
{
    return true;
}

bool NullType::IsSameType(AbstractType * other_type)
{
    return false;
}

string NullType::Symbol()
{
    return string("null");
}
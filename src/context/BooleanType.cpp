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

bool BooleanType::IsClassType()
{
    return false;
}

bool BooleanType::IsNullType()
{
    return false;
}

bool BooleanType::IsSameType(AbstractType * other_type)
{
    return other_type->IsBooleanType();
}

string BooleanType::Symbol()
{
    return string("boolean");
}

string BooleanType::JasminSymbol()
{
    return string("Z");
}
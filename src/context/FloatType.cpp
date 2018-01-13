#include "FloatType.h"

bool FloatType::IsBooleanType()
{
    return false;
}

bool FloatType::IsFloatType()
{
    return true;
}

bool FloatType::IsIntType()
{
    return false;
}

bool FloatType::IsStringType()
{
    return false;
}

bool FloatType::IsVoidType()
{
    return false;
}

bool FloatType::IsClassType()
{
    return false;
}

bool FloatType::IsNullType()
{
    return false;
}

bool FloatType::IsSameType(AbstractType * other_type)
{
    return other_type->IsFloatType();
}

string FloatType::Symbol()
{
    return string("float");
}

string FloatType::JasminSymbol()
{
    return string("F");
}
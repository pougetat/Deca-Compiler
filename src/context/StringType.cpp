#include "StringType.h"

bool StringType::IsBooleanType()
{
    return false;
}

bool StringType::IsFloatType()
{
    return false;
}

bool StringType::IsIntType()
{
    return false;
}

bool StringType::IsStringType()
{
    return true;
}

bool StringType::IsVoidType()
{
    return false;
}

bool StringType::IsClassType()
{
    return false;
}

bool StringType::IsNullType()
{
    return false;
}

bool StringType::IsSameType(AbstractType * other_type)
{
    return other_type->IsStringType();
}

string StringType::Symbol()
{
    return string("string");
}

string StringType::JasminSymbol()
{
    return string("Ljava/lang/String;");
}
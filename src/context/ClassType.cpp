#include "ClassType.h"

ClassType::ClassType(string class_name)
{
    m_class_name = class_name;
}

bool ClassType::IsBooleanType()
{
    return false;
}

bool ClassType::IsFloatType()
{
    return true;
}

bool ClassType::IsIntType()
{
    return false;
}

bool ClassType::IsStringType()
{
    return true;
}

bool ClassType::IsVoidType()
{
    return false;
}

bool ClassType::IsSameType(AbstractType * other_type)
{
    return false;
}
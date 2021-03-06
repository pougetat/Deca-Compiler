#include "ClassType.h"
#include <iostream>

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
    return false;
}

bool ClassType::IsIntType()
{
    return false;
}

bool ClassType::IsStringType()
{
    return false;
}

bool ClassType::IsVoidType()
{
    return false;
}

bool ClassType::IsClassType()
{
    return true;
}

bool ClassType::IsNullType()
{
    return false;
}

bool ClassType::IsSameType(AbstractType * other_type)
{
    return 
        (other_type->IsClassType() && 
            ((ClassType *) other_type)->m_class_name == m_class_name)
        || other_type->IsNullType();
}

string ClassType::Symbol()
{
    return string("class");
}

string ClassType::JasminSymbol()
{
    return "L" + m_class_name + ";";
}
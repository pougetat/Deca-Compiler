#ifndef CLASS_TYPE_H
#define CLASS_TYPE_H

#include "AbstractType.h"
#include <string>

using namespace std;

class ClassType : public AbstractType
{
    public:

        string m_class_name;

        ClassType(string class_name);

        bool IsBooleanType();
        bool IsFloatType();
        bool IsIntType();
        bool IsStringType();
        bool IsVoidType();
        bool IsClassType();
        bool IsSameType(AbstractType * other_type);
};

#endif
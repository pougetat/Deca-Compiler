#ifndef CLASS_TYPE_H
#define CLASS_TYPE_H

#include "AbstractType.h"

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

        bool IsNullType();
        
        bool IsSameType(AbstractType * other_type);

        string Symbol();
};

#endif
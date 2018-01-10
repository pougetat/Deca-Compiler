#ifndef FLOAT_TYPE_H
#define FLOAT_TYPE_H

#include "AbstractType.h"

class FloatType : public AbstractType
{
    public:
        
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
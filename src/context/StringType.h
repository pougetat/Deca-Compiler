#ifndef STRING_TYPE_H
#define STRING_TYPE_H

#include "AbstractType.h"

class StringType : public AbstractType
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

        string JasminSymbol();
};

#endif
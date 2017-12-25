#ifndef INT_TYPE_H
#define INT_TYPE_H

#include "AbstractType.h"

class IntType : public AbstractType
{
    public:
        bool IsBooleanType();
        bool IsFloatType();
        bool IsIntType();
        bool IsStringType();
        bool IsVoidType();
        bool IsClassType();
        bool IsSameType(AbstractType * other_type);

        string Symbol();
};

#endif
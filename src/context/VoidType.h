#ifndef VOID_TYPE_H
#define VOID_TYPE_H

#include "AbstractType.h"

class VoidType : public AbstractType
{
    public:
        bool IsBooleanType();
        bool IsFloatType();
        bool IsIntType();
        bool IsStringType();
        bool IsVoidType();
};

#endif
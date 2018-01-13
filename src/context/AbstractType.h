#ifndef ABSTRACT_TYPE_H
#define ABSTRACT_TYPE_H

#include <string>

using namespace std;

class AbstractType
{
    public:
        
        virtual bool IsBooleanType() = 0;
        
        virtual bool IsFloatType() = 0;
        
        virtual bool IsIntType() = 0;
        
        virtual bool IsStringType() = 0;
        
        virtual bool IsVoidType() = 0;
        
        virtual bool IsClassType() = 0;
        
        virtual bool IsNullType() = 0;
        
        virtual bool IsSameType(AbstractType * other_type) = 0;
        
        virtual string Symbol() = 0;

        virtual string JasminSymbol() = 0;
};

#endif
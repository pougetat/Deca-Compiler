#ifndef ABSTRACT_TYPE_H
#define ABSTRACT_TYPE_H

using namespace std;

class AbstractType
{
    public:
        virtual bool IsBooleanType() = 0;
        virtual bool IsFloatType() = 0;
        virtual bool IsIntType() = 0;
        virtual bool IsStringType() = 0;
        virtual bool IsVoidType() = 0;
        virtual bool IsSameType(AbstractType * other_type) = 0;
};

#endif
#ifndef READFLOAT_H
#define READFLOAT_H

#include "AbstractReadExpr.h"

class ReadFloat : public AbstractReadExpr
{
    public:
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
#ifndef NULL_H
#define NULL_H

#include "AbstractExpr.h"

class Null : public AbstractExpr
{
    public:

        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
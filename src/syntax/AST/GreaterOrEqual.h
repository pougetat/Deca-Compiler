#ifndef GREATER_OR_EQUAL_H
#define GREATER_OR_EQUAL_H

#include "AbstractOpIneq.h"

class GreaterOrEqual : public AbstractOpIneq
{
    public:

        GreaterOrEqual(AbstractExpr * expr1, AbstractExpr * expr2);

        AbstractExpr * Clone();
        
        void Display(string tab);
};

#endif
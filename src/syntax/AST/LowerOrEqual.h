#ifndef LOWER_OR_EQUAL_H
#define LOWER_OR_EQUAL_H

#include "AbstractOpIneq.h"

class LowerOrEqual : public AbstractOpIneq
{
    public:

        LowerOrEqual(AbstractExpr * expr1, AbstractExpr * expr2);

        AbstractExpr * Clone();
        
        void Display(string tab);
};

#endif
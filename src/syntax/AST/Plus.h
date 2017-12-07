#ifndef PLUS_H
#define PLUS_H

#include "AbstractOpArith.h"

class Plus : public AbstractOpArith
{
    public:

        Plus(AbstractExpr * expr1, AbstractExpr * expr2);
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        bool IsPlus();
        bool IsMinus();
        bool IsMultiply();
        bool IsDivide();
        bool IsModulo();
};

#endif
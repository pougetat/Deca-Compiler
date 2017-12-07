#ifndef MINUS_H
#define MINUS_H

#include "AbstractOpArith.h"

class Minus : public AbstractOpArith
{
    public:

        Minus(AbstractExpr * expr1, AbstractExpr * expr2);
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        bool IsPlus();
        bool IsMinus();
        bool IsMultiply();
        bool IsDivide();
        bool IsModulo();
};

#endif
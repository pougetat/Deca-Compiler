#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "AbstractOpArith.h"

class Multiply : public AbstractOpArith
{
    public:

        Multiply(AbstractExpr * expr1, AbstractExpr * expr2);
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        bool IsPlus();
        bool IsMinus();
        bool IsMultiply();
        bool IsDivide();
        bool IsModulo();
};

#endif
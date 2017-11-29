#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "AbstractOpArith.h"

class Multiply : public AbstractOpArith
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Multiply(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
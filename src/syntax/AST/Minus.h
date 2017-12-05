#ifndef MINUS_H
#define MINUS_H

#include "AbstractOpArith.h"

class Minus : public AbstractOpArith
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Minus(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
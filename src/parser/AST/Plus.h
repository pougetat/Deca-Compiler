#ifndef PLUS_H
#define PLUS_H

#include "AbstractOpArith.h"

class Plus : public AbstractOpArith
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Plus(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
#ifndef DIVIDE_H
#define DIVIDE_H

#include "AbstractOpArith.h"

class Divide : public AbstractOpArith
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Divide(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
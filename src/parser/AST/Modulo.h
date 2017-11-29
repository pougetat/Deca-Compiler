#ifndef MODULO_H
#define MODULO_H

#include "AbstractOpArith.h"

class Modulo : public AbstractOpArith
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Modulo(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
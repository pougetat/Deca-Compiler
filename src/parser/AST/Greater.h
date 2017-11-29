#ifndef GREATER_H
#define GREATER_H

#include "AbstractOpIneq.h"

class Greater : public AbstractOpIneq
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Greater(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
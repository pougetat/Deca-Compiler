#ifndef LOWER_H
#define LOWER_H

#include "AbstractOpIneq.h"

class Lower : public AbstractOpIneq
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Lower(AbstractExpr * expr1, AbstractExpr * expr2);

        AbstractExpr * Clone();
        
        void Display(string tab);
};

#endif
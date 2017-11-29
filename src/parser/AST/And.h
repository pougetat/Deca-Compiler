#ifndef AND_EXPR_H
#define AND_EXPR_H

#include "AbstractBinaryExpr.h"

class And : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        And(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
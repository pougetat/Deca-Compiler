#ifndef UNARY_MINUS_H
#define UNARY_MINUS_H

#include "AbstractUnaryExpr.h"

class UnaryMinus : public AbstractUnaryExpr
{
    public:
        
        AbstractExpr * m_expr;

        UnaryMinus(AbstractExpr * expr);
        void Display(string tab);
};

#endif
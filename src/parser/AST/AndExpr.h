#ifndef AND_EXPR_H
#define AND_EXPR_H

#include "AbstractBinaryExpr.h"

class AndExpr : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        AndExpr(AbstractExpr * expr1, AbstractExpr * expr2);
        void Display(string tab);
};

#endif
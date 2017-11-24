#ifndef AND_EXPR_H
#define AND_EXPR_H

#include "AbstractExpr.h"
#include "AbstractBinaryExpr.h"
#include <iostream>

using namespace std;

class AndExpr : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        AndExpr(AbstractExpr * expr1, AbstractExpr * expr2);
        void Display(string tab);
};

#endif
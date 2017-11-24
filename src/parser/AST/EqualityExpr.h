#ifndef EQUALITY_EXPR
#define EQUALITY_EXPR

#include "AbstractExpr.h"
#include "AbstractBinaryExpr.h"
#include <iostream>

using namespace std;

class EqualityExpr : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        EqualityExpr(AbstractExpr * expr1, AbstractExpr * expr2);
        void Display(string tab);
};

#endif
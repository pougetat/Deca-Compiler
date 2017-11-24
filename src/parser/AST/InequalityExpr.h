#ifndef INEQUALITY_EXPR
#define INEQUALITY_EXPR

#include "AbstractExpr.h"
#include "AbstractBinaryExpr.h"
#include <iostream>

using namespace std;

class InequalityExpr : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        InequalityExpr(AbstractExpr * expr1, AbstractExpr * expr2);
        void Display(string tab);
};

#endif
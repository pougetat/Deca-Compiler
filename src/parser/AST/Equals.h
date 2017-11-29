#ifndef EQUALS_EXPR
#define EQUALS_EXPR

#include "AbstractExpr.h"
#include "AbstractBinaryExpr.h"
#include <iostream>

using namespace std;

class Equals : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Equals(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
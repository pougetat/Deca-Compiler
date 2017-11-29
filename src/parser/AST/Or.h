#ifndef OR_H
#define OR_H

#include "AbstractExpr.h"
#include "AbstractBinaryExpr.h"
#include <iostream>

using namespace std;

class Or : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Or(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
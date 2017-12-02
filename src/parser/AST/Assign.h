#ifndef ASSIGN_H
#define ASSIGN_H

#include "AbstractBinaryExpr.h"

class Assign : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_lvalue;
        AbstractExpr * m_assign;

        Assign(AbstractExpr * lvalue, AbstractExpr * assign);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
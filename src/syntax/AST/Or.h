#ifndef OR_H
#define OR_H

#include "AbstractOpBool.h"

using namespace std;

class Or : public AbstractOpBool
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        Or(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
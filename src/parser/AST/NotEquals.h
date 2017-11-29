#ifndef NOT_EQUALS_EXPR
#define NOT_EQUALS_EXPR

#include "AbstractExpr.h"
#include "AbstractBinaryExpr.h"

class NotEquals : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_expr1;
        AbstractExpr * m_expr2;

        NotEquals(AbstractExpr * expr1, AbstractExpr * expr2);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
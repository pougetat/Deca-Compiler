#ifndef RETURN_H
#define RETURN_H

#include "AbstractInst.h"
#include "AbstractExpr.h"

using namespace std;

class Return : public AbstractInst
{
    public:

        AbstractExpr * m_return_expr;

        Return(AbstractExpr * return_expr);
        void Display(string tab);
};

#endif
#ifndef ABSTRACT_EXPR_H
#define ABSTRACT_EXPR_H

#include "AbstractInst.h"

class AbstractExpr : public AbstractInst
{
    public:
        virtual void Display(string tab) = 0;
};

#endif
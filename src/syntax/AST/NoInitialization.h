#ifndef NO_INITIALIZATION_H
#define NO_INITIALIZATION_H

#include "AbstractExpr.h"
#include "AbstractInitialization.h"

class NoInitialization : public AbstractInitialization
{
    public:
        
        AbstractExpr * m_expr;
        
        void Display(string tab);
};

#endif
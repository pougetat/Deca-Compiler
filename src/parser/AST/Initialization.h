#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "AbstractExpr.h"

class Initialization {

    public:
        
        AbstractExpr * m_expr;
        
        Initialization(AbstractExpr * expr);
        void Display(string tab);

};

#endif
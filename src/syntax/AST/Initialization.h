#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "AbstractInitialization.h"

class Initialization : public AbstractInitialization {

    public:
        
        AbstractExpr * m_expr;
        
        Initialization(AbstractExpr * expr);
        void Display(string tab);

};

#endif
#ifndef EQUALS_EXPR
#define EQUALS_EXPR

#include "AbstractExpr.h"
#include "AbstractBinaryExpr.h"
#include <iostream>

using namespace std;

class Equals : public AbstractBinaryExpr
{
    public:

        Equals(AbstractExpr * expr1, AbstractExpr * expr2);
        
        AbstractExpr * Clone();
        
        void Display(string tab);
};

#endif
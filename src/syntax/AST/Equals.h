#ifndef EQUALS_EXPR
#define EQUALS_EXPR

#include "AbstractOpExactCmp.h"

using namespace std;

class Equals : public AbstractOpExactCmp
{
    public:

        Equals(AbstractExpr * expr1, AbstractExpr * expr2);
        
        AbstractExpr * Clone();
        
        void Display(string tab);
};

#endif
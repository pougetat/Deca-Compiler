#ifndef INT_LITERAL_H
#define INT_LITERAL_H

#include "AbstractExpr.h"
#include <iostream>

using namespace std;

class IntLiteral : public AbstractExpr
{
    public:
        
        int m_value;

        IntLiteral(int value);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
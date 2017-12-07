#ifndef INT_LITERAL_H
#define INT_LITERAL_H

#include "AbstractLiteral.h"
#include <iostream>

using namespace std;

class IntLiteral : public AbstractLiteral
{
    public:
        
        int m_value;

        IntLiteral(int value);

        AbstractExpr * Clone();
        
        void Display(string tab);
};

#endif
#ifndef STRING_LITERAL_H
#define STRING_LITERAL_H

#include "AbstractExpr.h"
#include <iostream>

using namespace std;

class StringLiteral : public AbstractExpr
{
    public:
        
        string m_value;

        StringLiteral(string value);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
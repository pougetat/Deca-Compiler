#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <iostream>
#include "AbstractExpr.h"

using namespace std;

class Identifier : public AbstractExpr
{
    public:

        string m_symbol;

        Identifier(string symbol);
        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
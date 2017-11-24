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
        void Display(string tab);
};

#endif
#ifndef READINT_H
#define READINT_H

#include <iostream>
#include "AbstractReadExpr.h"

using namespace std;

class ReadInt : public AbstractReadExpr
{
    public:
        void Display(string tab);
};

#endif
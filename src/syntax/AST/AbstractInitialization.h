#ifndef ABSTRACT_INITIALIZATION_H
#define ABSTRACT_INITIALIZATION_H

#include <iostream>
#include "AbstractExpr.h"

using namespace std;

class AbstractInitialization
{
    public:
        virtual void Display(string tab) = 0;
};

#endif
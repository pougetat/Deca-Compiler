#ifndef THIS_H
#define THIS_H

#include "AbstractExpr.h"
#include <iostream>

using namespace std;

class This : public AbstractExpr
{
    public:
        
        bool m_value;

        This(bool value);
        void Display(string tab);
};

#endif
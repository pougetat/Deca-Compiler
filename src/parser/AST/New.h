#ifndef NEW_H
#define NEW_H

#include "AbstractExpr.h"
#include "Identifier.h"
#include <vector>

using namespace std;

class New : public AbstractExpr
{
    public:
 
        Identifier * m_class_name;

        New(Identifier * class_name);
        void Display(string tab);
};

#endif
#ifndef SELECTION_H
#define SELECTION_H

#include "AbstractLValue.h"
#include "Identifier.h"
#include <vector>

using namespace std;

class Selection : public AbstractLValue
{
    public:
 
        AbstractExpr * m_selection_expr;
        Identifier * m_identifier;

        AbstractExpr * Clone();
        void Display(string tab);
};

#endif
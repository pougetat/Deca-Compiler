#ifndef CAST_H
#define CAST_H

#include "AbstractExpr.h"
#include "Identifier.h"

class Cast : public AbstractExpr
{
    public:
 
        Identifier * m_cast_type;
        AbstractExpr * m_expr;

        Cast(Identifier * cast_type, AbstractExpr * expr);
        void Display(string tab);
};

#endif
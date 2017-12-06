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
        AbstractExpr * Clone();
        void Display(string tab);
        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name,
            AbstractType return_type
        );
};

#endif
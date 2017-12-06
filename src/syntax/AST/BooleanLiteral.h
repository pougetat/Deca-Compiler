#ifndef BOOLEAN_LITERAL_H
#define BOOLEAN_LITERAL_H

#include "AbstractExpr.h"

class BooleanLiteral : public AbstractExpr
{
    public:
        
        bool m_value;

        BooleanLiteral(bool value);
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
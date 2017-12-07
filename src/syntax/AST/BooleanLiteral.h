#ifndef BOOLEAN_LITERAL_H
#define BOOLEAN_LITERAL_H

#include "AbstractLiteral.h"

class BooleanLiteral : public AbstractLiteral
{
    public:
        
        bool m_value;

        // GRAMMAR PARSING RELATED RULES

        BooleanLiteral(bool value);
        AbstractExpr * Clone();
        void Display(string tab);

        // CONTEXT CHECKING RELATED RULES

        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name,
            AbstractType return_type
        );
};

#endif
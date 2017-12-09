#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include "AbstractLValue.h"

class Identifier : public AbstractLValue
{
    public:

        string m_symbol;

        Identifier(string symbol);
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyLValue(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
};

#endif
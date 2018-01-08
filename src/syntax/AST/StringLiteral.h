#ifndef STRING_LITERAL_H
#define STRING_LITERAL_H

#include "AbstractLiteral.h"
#include <iostream>

using namespace std;

class StringLiteral : public AbstractLiteral
{
    public:
        
        string m_value;

        StringLiteral(string value);

        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
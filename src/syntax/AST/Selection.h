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

        AbstractType * VerifyLValue(
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
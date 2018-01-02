#ifndef INSTANCEOF_H
#define INSTANCEOF_H

#include "AbstractExpr.h"
#include "Identifier.h"
#include <vector>

using namespace std;

class InstanceOf : public AbstractExpr
{
    public:
 
        AbstractExpr * m_expr;

        Identifier * m_instanceof_type;

        InstanceOf(
            AbstractExpr * expr, 
            Identifier * instanceof_type
        );

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
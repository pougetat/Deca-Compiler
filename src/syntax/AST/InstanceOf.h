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

        // GRAMMAR PARSING RELATED METHODS
        InstanceOf(
            AbstractExpr * expr, 
            Identifier * instanceof_type
        );
        AbstractExpr * Clone();
        void Display(string tab);

        // CONTEXT CHECKING RELATED METHODS
        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name
        );
};

#endif
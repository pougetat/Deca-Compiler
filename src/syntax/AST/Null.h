#ifndef NULL_H
#define NULL_H

#include "AbstractExpr.h"

class Null : public AbstractExpr
{
    public:

        // GRAMMAR PARSING RELATED METHODS

        AbstractExpr * Clone();
        void Display(string tab);

        // CONTEXT CHECKING RELATED METHODS

        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name
        );
};

#endif
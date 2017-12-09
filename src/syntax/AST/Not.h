#ifndef NOT_H
#define NOT_H

#include "AbstractUnaryExpr.h"

class Not : public AbstractUnaryExpr
{
    public:

        Not(AbstractExpr * expr);

        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
};

#endif
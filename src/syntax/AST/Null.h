#ifndef NULL_H
#define NULL_H

#include "AbstractExpr.h"

class Null : public AbstractExpr
{
    public:

        AbstractExpr * Clone();
        
        void Display(string tab);

        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
};

#endif
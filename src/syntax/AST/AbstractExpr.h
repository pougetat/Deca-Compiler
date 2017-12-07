#ifndef ABSTRACT_EXPR_H
#define ABSTRACT_EXPR_H

#include "AbstractInst.h"

class AbstractExpr : public AbstractInst
{
    public:
        
        virtual AbstractExpr * Clone() = 0;
        
        virtual void Display(string tab) = 0;

        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name,
            AbstractType * return_type
        );
        
        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name
        ) = 0;
};

#endif
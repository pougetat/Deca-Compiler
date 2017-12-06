#ifndef ASSIGN_H
#define ASSIGN_H

#include "AbstractBinaryExpr.h"

class Assign : public AbstractBinaryExpr
{
    public:
        
        AbstractExpr * m_lvalue;
        AbstractExpr * m_assign;

        Assign(AbstractExpr * lvalue, AbstractExpr * assign);
        AbstractExpr * Clone();
        void Display(string tab);
        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name,
            AbstractType return_type
        );
};

#endif
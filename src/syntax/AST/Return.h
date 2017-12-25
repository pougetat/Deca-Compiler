#ifndef RETURN_H
#define RETURN_H

#include "AbstractInst.h"
#include "AbstractExpr.h"

class Return : public AbstractInst
{
    public:

        AbstractExpr * m_return_expr;

        Return(AbstractExpr * return_expr);

        void Display(string tab);
        
        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * return_type
        );
};

#endif
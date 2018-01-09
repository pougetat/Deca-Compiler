#ifndef AND_EXPR_H
#define AND_EXPR_H

#include "AbstractOpBool.h"

class And : public AbstractOpBool
{
    public:

        And(AbstractExpr * expr1, AbstractExpr * expr2);

        And();
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
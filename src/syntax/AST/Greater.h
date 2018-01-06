#ifndef GREATER_H
#define GREATER_H

#include "AbstractOpIneq.h"

class Greater : public AbstractOpIneq
{
    public:

        Greater(AbstractExpr * expr1, AbstractExpr * expr2);

        AbstractExpr * Clone();
        
        void Display(string tab);

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
        
};

#endif
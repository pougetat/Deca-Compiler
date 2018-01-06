#ifndef LOWER_H
#define LOWER_H

#include "AbstractOpIneq.h"

class Lower : public AbstractOpIneq
{
    public:

        Lower(AbstractExpr * expr1, AbstractExpr * expr2);

        AbstractExpr * Clone();
        
        void Display(string tab);

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        ); 
};

#endif
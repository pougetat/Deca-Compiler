#ifndef DIVIDE_H
#define DIVIDE_H

#include "AbstractOpArith.h"

class Divide : public AbstractOpArith
{
    public:

        Divide(AbstractExpr * expr1, AbstractExpr * expr2);
        
        AbstractExpr * Clone();
        
        void Display(string tab);
        
        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
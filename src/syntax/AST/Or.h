#ifndef OR_H
#define OR_H

#include "AbstractOpBool.h"

class Or : public AbstractOpBool
{
    public:

        Or(AbstractExpr * expr1, AbstractExpr * expr2);

        Or();
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
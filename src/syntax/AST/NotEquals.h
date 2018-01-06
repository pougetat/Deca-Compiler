#ifndef NOT_EQUALS_EXPR
#define NOT_EQUALS_EXPR

#include "AbstractOpExactCmp.h"

class NotEquals : public AbstractOpExactCmp
{
    public:

        NotEquals(AbstractExpr * expr1, AbstractExpr * expr2);

        AbstractExpr * Clone();
        
        void Display(string tab);

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
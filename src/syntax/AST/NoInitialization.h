#ifndef NO_INITIALIZATION_H
#define NO_INITIALIZATION_H

#include "AbstractExpr.h"
#include "AbstractInitialization.h"

class NoInitialization : public AbstractInitialization
{
    public:
        
        AbstractExpr * m_expr;
        
        void Display(string tab);

        void VerifyInitialization(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * type
        );

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
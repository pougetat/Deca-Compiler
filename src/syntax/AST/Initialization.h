#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "AbstractInitialization.h"

class Initialization : public AbstractInitialization {

    public:
        
        AbstractExpr * m_expr;

        string var_symbol;
        
        Initialization(AbstractExpr * expr);
        
        void Display(string tab);

        virtual void VerifyInitialization(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * type
        );

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env,
            AbstractType * var_type
        );
};

#endif
#ifndef ASSIGN_H
#define ASSIGN_H

#include "AbstractBinaryExpr.h"
#include "Identifier.h"

class Assign : public AbstractBinaryExpr
{
    public:

        Assign(AbstractExpr * lvalue, AbstractExpr * assign);
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );

        void CodeGenInst(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
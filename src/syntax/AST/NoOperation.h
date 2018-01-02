#ifndef NO_OPERATION_H
#define NO_OPERATION_H

#include "AbstractInst.h"

class NoOperation : public AbstractInst
{
    public:

        void Display(string tab);
        
        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * return_type
        );

        void CodeGenInst(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
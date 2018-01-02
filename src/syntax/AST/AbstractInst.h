#ifndef ABSTRACT_INST_H
#define ABSTRACT_INST_H

#include <iostream>
#include <string>
#include <fstream>

#include "../../context/EnvironmentType.h"
#include "../../context/EnvironmentExp.h"
#include "../../context/AbstractType.h"
#include "../../generator/GeneratorEnvironment.h"

using namespace std;

class AbstractInst 
{
    public:

        virtual void Display(string tab) = 0;
        
        virtual void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * return_type
        ) = 0;

        virtual void CodeGenInst(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        ) = 0;
};

#endif
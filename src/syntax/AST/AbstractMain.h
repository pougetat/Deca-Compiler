#ifndef ABSTRACT_MAIN_H
#define ABSTRACT_MAIN_H

#include <iostream>
#include "../../context/EnvironmentType.h"
#include "../../context/EnvironmentExp.h"
#include "../../context/VoidType.h"
#include "../../generator/GeneratorEnvironment.h"

using namespace std;

class AbstractMain
{
    public:
        
        virtual void Display(string tab) = 0;
        
        virtual EnvironmentExp * VerifyMain(EnvironmentType * env_types) = 0;
        
        virtual void CodeGenMain(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        ) = 0;
};

#endif
#ifndef ABSTRACT_INST_H
#define ABSTRACT_INST_H

#include <iostream>
#include <string>
#include "../../context/EnvironmentType.h"
#include "../../context/EnvironmentExp.h"
#include "../../context/AbstractType.h"

using namespace std;

class AbstractInst 
{
    public:

        virtual void Display(string tab) = 0;
        
        virtual void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name,
            AbstractType * return_type
        ) = 0;
};

#endif
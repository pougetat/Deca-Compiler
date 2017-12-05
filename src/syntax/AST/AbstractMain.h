#ifndef ABSTRACT_MAIN_H
#define ABSTRACT_MAIN_H

#include <iostream>
#include "../../context/EnvironmentType.h"

using namespace std;

class AbstractMain
{
    public:
        virtual void Display(string tab) = 0;
        virtual void VerifyMain(EnvironmentType * env_types) = 0;

};

#endif
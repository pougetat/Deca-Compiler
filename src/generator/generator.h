#ifndef GENERATOR_H
#define GENERATOR_H

#include "../syntax/SyntaxParser.h"
#include "../context/EnvironmentType.h"
#include "GeneratorEnvironment.h"

class Generator
{
    public:

        void GenCode(
            Program * prog,
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
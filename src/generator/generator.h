#ifndef GENERATOR_H
#define GENERATOR_H

#include "../syntax/SyntaxParser.h"

class Generator
{
    public:
        void GenCode(Program * prog);
};

#endif
#ifndef CONTEXT_CHECKER_H
#define CONTEXT_CHECKER_H

#include "../syntax/SyntaxParser.h"
#include "EnvironmentType.h"

class ContextChecker
{
    public:
        void CheckContext(Program * program);
};

#endif
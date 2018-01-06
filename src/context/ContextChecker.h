#ifndef CONTEXT_CHECKER_H
#define CONTEXT_CHECKER_H

#include "../syntax/SyntaxParser.h"
#include "EnvironmentType.h"

class ContextChecker
{
    public:

        EnvironmentType * m_env_types_predef;

        EnvironmentExp * CheckContext(Program * program);
};

#endif
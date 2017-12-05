#include "ContextChecker.h"

void ContextChecker::CheckContext(Program * program)
{
    EnvironmentType * env_types = new EnvironmentType();
    program->VerifyProgramPass3(env_types);
}
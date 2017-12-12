#include "ContextChecker.h"

void ContextChecker::CheckContext(Program * program)
{
    // PASS 1
    EnvironmentType * env_types_predef = new EnvironmentType();
    program->VerifyClassHierarchy(env_types_predef);

    // PASS 3
    program->VerifyProgramPass3(env_types_predef);
}
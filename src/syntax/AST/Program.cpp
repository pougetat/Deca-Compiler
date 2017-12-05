#include "Program.h"

void Program::Display(string tab)
{
    m_main->Display(tab + "--");
}

void Program::VerifyProgramPass3(EnvironmentType * env_types)
{
    m_main->VerifyMain(env_types);
}
#include "Program.h"

void Program::Display(string tab)
{
    cout << tab << "-->" << "[PROGRAM]" << endl;
    cout << tab << "---->" << "[LIST DECL CLASS]" << endl;
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->Display(tab + "------");
    }
    
    m_main->Display(tab + "----");
}

void Program::VerifyClassHierarchy(EnvironmentType * env_types_predef)
{
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->VerifyClassHierarchy(env_types_predef);
    }
}

void Program::VerifyProgramPass3(EnvironmentType * env_types)
{
    m_main->VerifyMain(env_types);
}
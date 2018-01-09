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

void Program::VerifyClassNames(EnvironmentType * env_types)
{
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->VerifyClassName(env_types);
    }
}

void Program::VerifyClassHierarchy(EnvironmentType * env_types)
{
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->VerifyClassHierarchy(env_types);
    }
}

void Program::VerifyClassMF(EnvironmentType * env_types)
{
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->VerifyClassMF(env_types);
    }
}

void Program::VerifyClassMFHierarchy(EnvironmentType * env_types)
{
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->VerifyClassMFHierarchy(env_types);
    }
}

EnvironmentExp * Program::VerifyProgramPass3(EnvironmentType * env_types)
{
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->VerifyClassBody(env_types);
    }
    return m_main->VerifyMain(env_types);
}

void Program::GenCode(EnvironmentType * env_types, GeneratorEnvironment * gen_env)
{
    for (DeclClass * decl_class : *m_list_decl_class)
    {
        decl_class->CodeGenDeclClass(
            env_types,
            new GeneratorEnvironment(
                env_types->GetClassEnvExp(decl_class->m_class_name->m_symbol),
                new string(decl_class->m_class_name->m_symbol + ".j")
            )
        );
    }
    m_main->CodeGenMain(env_types, gen_env);
}
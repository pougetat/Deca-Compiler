#include "ContextChecker.h"

EnvironmentExp * ContextChecker::CheckContext(Program * program)
{
    m_env_types_predef = new EnvironmentType();
    /*
        PASS 1.1 :
            - add new type definitions to env_types_predef for each class
            without checking against existence of potential parent classes
    */
    program->VerifyClassNames(m_env_types_predef);

    /*
        PASS 1.2 :
            - check all potential parent classes of classes have been declared
            and change the parent classes of child classes to those parents
            instead of "Object"
    */
    program->VerifyClassHierarchy(m_env_types_predef);

    /*
        PASS 2.1 :
            - create the env exp of each class without checking against conflicts
            with a potential parent class
    */
    program->VerifyClassMF(m_env_types_predef);

    /*
        PASS 2.2 :
            - check that all methods appearing in a child class and which also
            appear in a parent class have the same signatures
            - check that if a field appears in a class and the identifier for the
            field appears in a parent class, then that identifier also refers to a
            field and not to a method
    */
    program->VerifyClassMFHierarchy(m_env_types_predef);

    /*
        PASS 3 :
            - check the blocks
            - check the instructions
            - check the expressions
            - check the initializations
    */
    return program->VerifyProgramPass3(m_env_types_predef);
}
#include "ContextChecker.h"

void ContextChecker::CheckContext(Program * program)
{
    EnvironmentType * env_types_predef = new EnvironmentType();
    /*
        PASS 1.1 :
            - add new type definitions to env_types_predef for each class
            without checking against existence of potential parent classes
    */
    program->VerifyClassNames(env_types_predef);

    /*
        PASS 1.2 :
            - check all potential parent classes of classes have been declared
            and change the parent classes of child classes to those parents
            instead of "Object"
    */
    program->VerifyClassHierarchy(env_types_predef);

    /*
        PASS 2.1 :
            - create the env exp of each class without checking against conflicts
            with a potential parent class
    */
    program->VerifyClassMF(env_types_predef);

    /*
        PASS 2.2 :
            - check that all methods appearing in a child class and which also
            appear in a parent class have the same signatures
            - check that if a field appears in a class and the identifier for the
            field appears in a parent class, then that identifier also refers to a
            field and not to a method
    */
    program->VerifyClassMFHierarchy(env_types_predef);

    /*
        PASS 3 :
            - check the blocks
            - check the instructions
            - check the expressions
            - check the initializations
    */
    program->VerifyProgramPass3(env_types_predef);
}
#include "NoInitialization.h"

void NoInitialization::Display(string tab)
{
    cout << tab << ">" << "[NO INITIALIZATION]" << endl;
}

void NoInitialization::VerifyInitialization(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * type)
{}

void NoInitialization::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << "    ; pushing 0 on the stack" << endl;
    gen_env->output_file << "    bipush 0" << endl;
}
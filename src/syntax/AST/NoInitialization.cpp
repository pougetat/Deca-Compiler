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
    GeneratorEnvironment * gen_env,
    AbstractType * var_type)
{
    if (var_type->IsClassType())
    {
        gen_env->output_file << "    aconst_null" << endl;
    }
    else
    {
        gen_env->output_file << "    ldc 0" << endl;
    }
}
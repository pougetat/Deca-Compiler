#include "AbstractReadExpr.h"

AbstractType * AbstractReadExpr::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    throw runtime_error("NOT IMPLEMENTED YET");
}

void AbstractReadExpr::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{}
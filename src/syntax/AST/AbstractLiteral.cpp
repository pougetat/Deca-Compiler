#include "AbstractLiteral.h"

AbstractType * AbstractLiteral::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    throw runtime_error("NOT IMPLEMENTED YET");
}

void AbstractLiteral::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    throw runtime_error("NOT YET IMPLEMENTED");
}
#include "AbstractBinaryExpr.h"

AbstractType * AbstractBinaryExpr::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    throw runtime_error("NOT YET IMPLEMENTED");
}

void AbstractBinaryExpr::CodeGenInst(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    throw runtime_error("NOT YET IMPLEMENTED");
}

void AbstractBinaryExpr::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    throw runtime_error("NOT YET IMPLEMENTED");
}
#include "AbstractExpr.h"

void AbstractExpr::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name,
    AbstractType * return_type)
{
    VerifyExpr(env_types, env_exp, class_name);
}

AbstractType * AbstractExpr::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name
)
{
    throw runtime_error("NOT IMPLEMENTED YET");
    return NULL;
}
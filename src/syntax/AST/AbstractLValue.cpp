#include "AbstractLValue.h"

AbstractType * AbstractLValue::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    return VerifyLValue(
        env_types,
        env_exp,
        class_name
    );
}

AbstractType * AbstractLValue::VerifyLValue(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    throw runtime_error("NOT IMPLEMENTED YET");
}

void AbstractLValue::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    throw runtime_error("NOT IMPLEMENTED YET");
}
#include "AbstractBinaryExpr.h"

AbstractType * AbstractBinaryExpr::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    throw runtime_error("NOT YET IMPLEMENTED");
}

void AbstractBinaryExpr::CodeGenInst(ofstream output_file)
{
    throw runtime_error("NOT YET IMPLEMENTED");
}
#include "Null.h"

// GRAMMAR PARSING RELATED METHODS

AbstractExpr * Null::Clone()
{
    return new Null();
}

void Null::Display(string tab)
{
    cout << tab << ">" << "[NULL]" << endl;
}

// CONTEXT CHECKING RELATED METHODS

AbstractType * Null::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    return new NullType();
}
#include "Null.h"

AbstractExpr * Null::Clone()
{
    return new Null();
}

void Null::Display(string tab)
{
    cout << tab << ">" << "[NULL]" << endl;
}

AbstractType * Null::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    return new NullType();
}
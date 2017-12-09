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
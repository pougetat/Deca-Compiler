#include "NoOperation.h"

void NoOperation::Display(string tab)
{
    cout << tab << ">" << "[NO OPERATION]" << endl;
}

void NoOperation::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * return_type)
{

}
#include "VarExpNature.h"

bool VarExpNature::IsParamExpNature()
{
    return false;
}

bool VarExpNature::IsVarExpNature()
{
    return true;
}

bool VarExpNature::IsMethodExpNature()
{
    return false;
}

bool VarExpNature::IsFieldExpNature()
{
    return false;
}
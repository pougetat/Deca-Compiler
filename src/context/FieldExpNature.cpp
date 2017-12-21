#include "FieldExpNature.h"

bool FieldExpNature::IsParamExpNature()
{
    return false;
}

bool FieldExpNature::IsVarExpNature()
{
    return false;
}

bool FieldExpNature::IsMethodExpNature()
{
    return false;
}

bool FieldExpNature::IsFieldExpNature()
{
    return true;
}
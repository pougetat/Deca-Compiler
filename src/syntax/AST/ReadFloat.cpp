#include "ReadFloat.h"

AbstractExpr * ReadFloat::Clone()
{
    return new ReadFloat();
}

void ReadFloat::Display(string tab)
{
    cout << tab << ">[READFLOAT]" << endl;
}
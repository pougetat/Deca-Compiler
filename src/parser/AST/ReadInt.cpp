#include "ReadInt.h"

AbstractExpr * ReadInt::Clone()
{
    return new ReadInt();
}

void ReadInt::Display(string tab)
{
    cout << tab << ">[READINT]" << endl;
}
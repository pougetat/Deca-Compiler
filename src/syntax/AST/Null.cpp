#include "Null.h"

AbstractExpr * Null::Clone()
{
    return new Null();
}

void Null::Display(string tab)
{
    cout << tab << ">" << "[NULL]" << endl;
}
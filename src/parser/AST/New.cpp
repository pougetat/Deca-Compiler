#include "New.h"

New::New(Identifier * class_name)
{
    m_class_name = class_name;
}

AbstractExpr * New::Clone()
{
    New * n = new New(
        new Identifier(m_class_name->m_symbol)
    );
    return n;
}

void New::Display(string tab)
{
    cout << tab << ">" << "[NEW]" << endl;
    m_class_name->Display(tab + "---");
}
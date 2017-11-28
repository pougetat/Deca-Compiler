#include "New.h"

New::New(Identifier * class_name)
{
    m_class_name = class_name;
}

void New::Display(string tab)
{
    cout << tab << ">" << "[NEW]" << endl;
    m_class_name->Display(tab + "---");
}
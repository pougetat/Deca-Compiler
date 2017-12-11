#include "DeclClass.h"

void DeclClass::Display(string tab)
{
    cout << tab << ">" << "[DECL CLASS]" << endl;
    m_class_name->Display(tab + "--");
}
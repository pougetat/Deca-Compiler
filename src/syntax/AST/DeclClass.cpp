#include "DeclClass.h"

void DeclClass::Display(string tab)
{
    cout << tab << ">" << "[DECL CLASS]" << endl;
    m_class_name->Display(tab + "--");
    if (m_parent_class_name != NULL)
    {
        m_parent_class_name->Display(tab + "--");
    }
}
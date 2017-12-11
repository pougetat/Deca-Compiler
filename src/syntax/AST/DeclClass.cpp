#include "DeclClass.h"

void DeclClass::Display(string tab)
{
    cout << tab << ">" << "[DECL CLASS]" << endl;
    
    m_class_name->Display(tab + "--");
    
    if (m_parent_class_name != NULL)
    {
        m_parent_class_name->Display(tab + "--");
    }

    for (DeclField * decl_field : *m_class_fields)
    {
        decl_field->Display(tab + "--");
    }

    for (DeclMethod * decl_method : *m_class_methods)
    {
        decl_method->Display(tab + "--");
    }

}
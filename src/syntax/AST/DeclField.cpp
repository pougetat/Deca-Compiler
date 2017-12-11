#include "DeclField.h"

void DeclField::Display(string tab)
{
    cout << tab << ">" << "[DECL FIELD]" << endl;
    
    if (m_field_visibility == VISIBILITY_PROTECTED)
    {
        cout << tab << "-->[VISIBILITY] VALUE : PROTECTED" << endl; 
    }
    else
    {
        cout << tab << "-->[VISIBILITY] VALUE : PRIVATE" << endl;
    }

    m_field_type->Display(tab + "--");
    m_field_name->Display(tab + "--");
    m_init->Display(tab + "--");
}
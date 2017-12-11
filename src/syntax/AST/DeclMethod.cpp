#include "DeclMethod.h"

void DeclMethod::Display(string tab)
{
    cout << tab << ">" << "[DECL METHOD]" << endl;

    m_method_return_type->Display(tab + "--");
    m_method_name->Display(tab + "--");
    
    cout << tab << "-->" << "[LIST PARAM]" << endl;
    for (DeclParam * decl_param : *m_list_param)
    {
        decl_param->Display(tab + "----");
    }

    m_method_body->Display(tab + "--");
}
#include "DeclParam.h"

void DeclParam::Display(string tab)
{
    cout << tab << ">" << "[DECL PARAM]" << endl;
    m_param_type->Display(tab + "--");
    m_param_name->Display(tab + "--");
}
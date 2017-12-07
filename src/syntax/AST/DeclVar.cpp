#include "DeclVar.h"

void DeclVar::Display(string tab)
{
    cout << tab << ">" << "[DECL VAR]" << endl;
    m_type->Display(tab + "--");
    m_symbol->Display(tab + "--");
    m_init->Display(tab + "--");
}

void DeclVar::VerifyDeclVar(
    EnvironmentType * env_types, 
    EnvironmentExp * env_exp_sup,
    EnvironmentExp * env_exp,
    string * class_name)
{
    if (!env_types->TypeExists(m_type->m_symbol))
    {
        throw runtime_error("UNKNOWN TYPE " + m_type->m_symbol);
    }
    AbstractType * type = env_types->GetType(m_type->m_symbol);
    if (type->IsVoidType())
    {
        throw runtime_error("VARIABLE CANNOT BE OF TYPE VOID");
    }

}
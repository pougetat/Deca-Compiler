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
        throw runtime_error("[DECL VAR : UNKNOWN TYPE '" + m_type->m_symbol + "']");
    }

    AbstractType * variable_type = env_types->GetType(m_type->m_symbol);
    
    if (variable_type->IsVoidType())
    {
        throw runtime_error("[DECL VAR : VOID IS INVALID TYPE]");
    }

    m_init->VerifyInitialization(
        env_types,
        env_exp,
        class_name,
        variable_type
    );

    env_exp->InsertExpDefinition(
        m_symbol->m_symbol,
        new ExpDefinition(
            new VarExpNature(),
            variable_type
        )
    );
}
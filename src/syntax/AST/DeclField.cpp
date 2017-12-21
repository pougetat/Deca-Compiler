#include "DeclField.h"

void DeclField::VerifyFieldNoInit(
    EnvironmentType * env_types,
    Identifier * class_name)
{
    if (!env_types->TypeExists(m_field_type->m_symbol))
    {
        throw runtime_error(
            "[DECL FIELD : UNKNOWN TYPE '" + m_field_type->m_symbol + "']"
        );
    }
    if (env_types->GetType(m_field_type->m_symbol)->IsVoidType())
    {
        throw runtime_error(
            "[DECL FIELD : VOID IS INVALID TYPE]"
        );
    }
    
    InsertFieldExpDefinition(env_types, class_name);
}

void DeclField::VerifyFieldHierarchy(
    EnvironmentType * env_types,
    Identifier * class_name)
{
    EnvironmentExp * class_env_exp = 
        env_types->GetClassEnvExp(class_name->m_symbol);

    if (class_env_exp->SupContainsSymbol(m_field_name->m_symbol))
    {
        ExpDefinition * sup_exp = 
            class_env_exp->GetSupExpDefinition(m_field_name->m_symbol);

        if (!sup_exp->GetTypeNature()->IsFieldExpNature())
        {
            throw runtime_error(
                "[DECL FIELD : PARENT IDENTIFIER SHOULD BE OF SAME TYPE]"
            );
        }
    }
}

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

///////////// PRIVATE METHODS /////////////

void DeclField::InsertFieldExpDefinition(
    EnvironmentType * env_types,
    Identifier * class_name)
{
    EnvironmentExp * class_env_exp = 
        env_types->GetClassEnvExp(class_name->m_symbol);

    class_env_exp->InsertExpDefinition(
        m_field_name->m_symbol,
        new ExpDefinition(
            new FieldExpNature(),
            env_types->GetType(m_field_type->m_symbol)
        )
    );
}
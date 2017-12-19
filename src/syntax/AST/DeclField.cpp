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

    FieldExpNature * field_exp = new FieldExpNature();
    
    env_types->InsertExp(
        class_name->m_symbol,
        m_field_name->m_symbol,
        new ExpDefinition(
            field_exp,
            env_types->GetType(m_field_type->m_symbol)
        )
    );
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
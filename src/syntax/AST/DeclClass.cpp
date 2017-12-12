#include "DeclClass.h"

void DeclClass::VerifyClassName(EnvironmentType * env_types)
{
    if (env_types->TypeExists(m_class_name->m_symbol))
    {
        throw runtime_error(
            "[DECL CLASS : CLASS '" + m_class_name->m_symbol + "' ALREADY EXISTS]"
        );
    }

    env_types->InsertType(
        m_class_name->m_symbol,
        new TypeDefinition(
            new ClassTypeNature(
                "Object"
            ),
            new ClassType(m_class_name->m_symbol)
        )
    );
}

void DeclClass::VerifyClassHierarchy(EnvironmentType * env_types)
{   
    if (m_parent_class_name != NULL)
    {
        if (!env_types->TypeExists(m_parent_class_name->m_symbol))
        {
            throw runtime_error(
                "[DECL CLASS : PARENT CLASS '" + m_parent_class_name->m_symbol
                + "' DOES NOT EXIST]"
            );
        }

        env_types->SetParentClass(
            m_class_name->m_symbol,
            m_parent_class_name->m_symbol
        );
    }
}

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
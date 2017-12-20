#include "DeclParam.h"

void DeclParam::VerifyDeclParam(
    EnvironmentType * env_types,
    Identifier * class_name,
    Identifier * method_name)
{
    if (!env_types->TypeExists(m_param_type->m_symbol))
    {
        throw runtime_error(
            "[PARAM TYPE : UNKNOWN TYPE '" + m_param_type->m_symbol + "']"
        );
    }
    if (env_types->GetType(m_param_type->m_symbol)->IsVoidType())
    {
        throw runtime_error(
            "[DECL PARAM : VOID IS INVALID TYPE]"
        );
    }

    env_types->AddTypeToSignature(
        class_name->m_symbol,
        method_name->m_symbol,
        env_types->GetType(m_param_type->m_symbol)
    );
}

void DeclParam::Display(string tab)
{
    cout << tab << ">" << "[DECL PARAM]" << endl;
    m_param_type->Display(tab + "--");
    m_param_name->Display(tab + "--");
}
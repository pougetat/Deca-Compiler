#include "DeclMethod.h"

void DeclMethod::VerifyMethodSignature(
    EnvironmentType * env_types,
    Identifier * class_name)
{
    if (!env_types->TypeExists(m_return_type->m_symbol))
    {
        throw runtime_error(
            "[RETURN TYPE : UNKNOWN TYPE '" + m_return_type->m_symbol + "']"
        );
    }

    InsertMethodExpDefinition(env_types, class_name);

    VerifyParamTypes(env_types, class_name);
}

void DeclMethod::Display(string tab)
{
    cout << tab << ">" << "[DECL METHOD]" << endl;

    m_return_type->Display(tab + "--");
    m_name->Display(tab + "--");
    
    cout << tab << "-->" << "[LIST PARAM]" << endl;
    for (DeclParam * decl_param : *m_params)
    {
        decl_param->Display(tab + "----");
    }

    m_body->Display(tab + "--");
}

///////////// PRIVATE METHODS /////////////

void DeclMethod::VerifyParamTypes(
    EnvironmentType * env_types,
    Identifier * class_name)
{
    for (DeclParam * param : *m_params)
    {
        param->VerifyDeclParam(env_types, class_name, m_name);
    }
}

void DeclMethod::InsertMethodExpDefinition(
    EnvironmentType * env_types,
    Identifier * class_name)
{
    EnvironmentExp * class_env_exp = 
    env_types->GetClassEnvExp(class_name->m_symbol);

    class_env_exp->InsertExpDefinition(
        m_name->m_symbol,
        new ExpDefinition(
            new MethodExpNature(),
            env_types->GetType(m_return_type->m_symbol)
        )
    );
}
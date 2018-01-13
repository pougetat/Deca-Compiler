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

void DeclField::VerifyFieldInit(
    EnvironmentType * env_types,
    Identifier * class_name)
{
    m_init->VerifyInitialization(
        env_types,
        env_types->GetClassEnvExp(class_name->m_symbol),
        &(class_name->m_symbol),
        env_types->GetType(m_field_type->m_symbol)
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

void DeclField::CodeGenDeclField(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    AbstractType * field_type = env_types->GetType(m_field_type->m_symbol);
    
    gen_env->output_file << ".field ";
    
    if (m_field_visibility == VISIBILITY_PRIVATE)
    {
        gen_env->output_file << "private ";
    }
    if (m_field_visibility == VISIBILITY_PROTECTED)
    {
        gen_env->output_file << "protected ";
    }
    
    gen_env->output_file << m_field_name->m_symbol;
    gen_env->output_file << " " << field_type->JasminSymbol() << endl;
}

void DeclField::CodeGenFieldInit(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env,
    string class_name)
{
    AbstractType * var_type = env_types->GetType(m_field_type->m_symbol);
    
    m_init->CodeGenExpr(env_types, gen_env, var_type);
    gen_env->output_file 
        << "    putfield " 
        << class_name << "/" << m_field_name->m_symbol
        << " " << var_type->JasminSymbol() << endl;
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
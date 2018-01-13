#include "DeclParam.h"

void DeclParam::VerifyDeclParam(
    EnvironmentType * env_types,
    Identifier * class_name,
    Identifier * method_name)
{
    if (!env_types->TypeExists(m_param_type->m_symbol))
    {
        throw runtime_error(
            "[DECL PARAM : UNKNOWN TYPE '" + m_param_type->m_symbol + "']"
        );
    }
    if (env_types->GetType(m_param_type->m_symbol)->IsVoidType())
    {
        throw runtime_error(
            "[DECL PARAM : VOID IS INVALID TYPE]"
        );
    }

    AddTypeToSignature(env_types, class_name, method_name);
}

void DeclParam::Display(string tab)
{
    cout << tab << ">" << "[DECL PARAM]" << endl;
    m_param_type->Display(tab + "--");
    m_param_name->Display(tab + "--");
}

void DeclParam::CodeGenDeclParam(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    AbstractType * param_type = env_types->GetType(m_param_type->m_symbol);
    gen_env->output_file << param_type->JasminSymbol();
}

///////////// PRIVATE METHODS /////////////

void DeclParam::AddTypeToSignature(
    EnvironmentType * env_types,
    Identifier * class_name,
    Identifier * method_name)
{
    TypeDefinition * class_def =
        env_types->GetTypeDefinition(class_name->m_symbol);

    ClassTypeNature * class_type_nat =
        (ClassTypeNature *) class_def->GetTypeNature();

    EnvironmentExp * class_env_exp = class_type_nat->GetEnvExp();

    ExpDefinition * method_def = 
        class_env_exp->GetExpDefinition(method_name->m_symbol);

    MethodExpNature * method_exp_nature = 
        (MethodExpNature *) method_def->GetTypeNature();

    method_exp_nature->InsertSignatureType(
        env_types->GetType(m_param_type->m_symbol)
    );
}
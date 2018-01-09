#include "DeclVar.h"

void DeclVar::VerifyDeclVar(
    EnvironmentType * env_types, 
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

void DeclVar::Display(string tab)
{
    cout << tab << ">" << "[DECL VAR]" << endl;
    m_type->Display(tab + "--");
    m_symbol->Display(tab + "--");
    m_init->Display(tab + "--");
}

void DeclVar::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->IncrNumVars();
    gen_env->SetMemoryLocation(m_symbol->m_symbol);

    m_init->CodeGenExpr(env_types, gen_env);
    gen_env->output_file << "    ; storing value in variable" << endl;

    if (env_types->GetType(m_type->m_symbol)->IsIntType()
        || env_types->GetType(m_type->m_symbol)->IsBooleanType())
    {
        gen_env->output_file 
            << "    istore " << gen_env->GetMemoryLocation(m_symbol->m_symbol)
            << endl;
    }
    if (env_types->GetType(m_type->m_symbol)->IsFloatType())
    {
        gen_env->output_file 
            << "    fstore " << gen_env->GetMemoryLocation(m_symbol->m_symbol)
            << endl;
    }
    if (env_types->GetType(m_type->m_symbol)->IsClassType())
    {
        gen_env->output_file
            << "    astore " << gen_env->GetMemoryLocation(m_symbol->m_symbol)
            << endl;
    }
}
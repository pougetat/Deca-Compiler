#include "GeneratorEnvironment.h"

GeneratorEnvironment::GeneratorEnvironment(
    EnvironmentExp * env_exp,
    string * jasmin_file)
{
    m_env_exp = env_exp;
    output_file = ofstream(*jasmin_file, ios::out | ios::app);
}

void GeneratorEnvironment::GenLoadFromMemory(
    EnvironmentType * env_types,
    string var_symbol)
{    
    ExpDefinition * var_exp = NULL;

    if (m_env_exp->ContainsSymbol(var_symbol))
    {
        var_exp = m_env_exp->GetExpDefinition(var_symbol);
    }
    else if (m_env_exp->SupContainsSymbol(var_symbol))
    {
        var_exp = m_env_exp->GetSupExpDefinition(var_symbol);
    }

    AbstractExpNature * var_exp_nature = var_exp->GetTypeNature();

    if (var_exp_nature->IsFieldExpNature())
    {
        GenLoadFieldFromMemory(env_types, var_symbol, var_exp);
    }
    if (var_exp_nature->IsVarExpNature())
    {
        GenLoadLocalFromMemory(env_types, var_symbol, var_exp);
    }
}

void GeneratorEnvironment::GenStoreInMemory(
    EnvironmentType * env_types,
    string var_symbol)
{
    if (m_env_exp->ContainsSymbol(var_symbol))
    {
        ExpDefinition * var_def = m_env_exp->GetExpDefinition(var_symbol);
        AbstractExpNature * var_exp_nature = var_def->GetTypeNature();
        
        if (var_exp_nature->IsVarExpNature())
        {
            GenStoreLocalInMemory(env_types, var_symbol);
        }
        if (var_exp_nature->IsFieldExpNature())
        {
            GenStoreFieldInMemory(env_types, var_symbol);
        }
    }
}

int GeneratorEnvironment::GetNewLabel()
{
    m_num_labels++;
    return m_num_labels;
}

///////////// PRIVATE METHODS /////////////

void GeneratorEnvironment::GenLoadLocalFromMemory(
    EnvironmentType * env_types,
    string var_symbol,
    ExpDefinition * var_exp)
{
    string load_instruct = "";
    AbstractType * var_type = var_exp->GetType();
    
    if (var_type->IsIntType() || var_type->IsBooleanType())
    {
        load_instruct = "iload";
    }
    if (var_type->IsFloatType())
    {
        load_instruct = "fload";
    }
    if (var_type->IsClassType())
    {
        load_instruct = "aload";
    }
    output_file
        << "    " << load_instruct << " " << GetLocalMemoryLocation(var_symbol)
        << endl;
}

void GeneratorEnvironment::GenLoadFieldFromMemory(
    EnvironmentType * env_types,
    string var_symbol,
    ExpDefinition * var_exp)
{
    AbstractType * var_type = var_exp->GetType();

    output_file << "    aload_0" << endl;
    output_file
        << "    getfield "
        << m_env_exp->m_englobing_class << "/" << var_symbol
        << " " << var_type->JasminSymbol()
        << endl;
}

void GeneratorEnvironment::GenStoreLocalInMemory(
    EnvironmentType * env_types,
    string var_symbol)
{
    if (GetLocalMemoryLocation(var_symbol) == -1)
    {
        SetLocalMemoryLocation(var_symbol);
    }

    string store_instruct = "";
    AbstractType * var_type = m_env_exp->GetExpDefinition(var_symbol)->GetType();

    if (var_type->IsIntType() || var_type->IsBooleanType())
    {
        store_instruct = "istore";
    }
    if (var_type->IsFloatType())
    {
        store_instruct = "fstore";
    }
    if (var_type->IsClassType())
    {
        store_instruct = "astore";
    }
    output_file
        << "    " << store_instruct << " " << GetLocalMemoryLocation(var_symbol)
        << endl;    
}

void GeneratorEnvironment::GenStoreFieldInMemory(
    EnvironmentType * env_types,
    string var_symbol)
{}

int GeneratorEnvironment::GetLocalMemoryLocation(string var_symbol)
{
    return
        m_env_exp->GetExpDefinition(var_symbol)->GetMemoryLocation();
}

void GeneratorEnvironment::SetLocalMemoryLocation(string var_symbol)
{
    m_num_vars++;
    m_env_exp
        ->GetExpDefinition(var_symbol)
        ->SetMemoryLocation(m_num_vars);
}
#include "New.h"

New::New(Identifier * class_name)
{
    m_class_name = class_name;
}

AbstractExpr * New::Clone()
{
    New * n = new New(
        new Identifier(m_class_name->m_symbol)
    );
    return n;
}

void New::Display(string tab)
{
    cout << tab << ">" << "[NEW]" << endl;
    m_class_name->Display(tab + "---");
}

AbstractType * New::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    if (!env_types->TypeExists(m_class_name->m_symbol))
    {
        throw runtime_error(
            "[DECL VAR : UNKNOWN TYPE '" + m_class_name->m_symbol + "']"
        );
    }

    AbstractType * variable_type = env_types->GetType(m_class_name->m_symbol);

    return variable_type;
}

void New::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << "    ; adding new reference to stack" << endl;
    gen_env->output_file << "    new " << m_class_name->m_symbol << endl;
    gen_env->output_file << "    ; creating dup of ref on stack" << endl;
    gen_env->output_file << "    dup" << endl;
    gen_env->output_file << "    ; calling constructor" << endl;
    gen_env->output_file 
        << "    invokespecial " 
        << m_class_name->m_symbol
        << "/<init>()V"
        << endl;
}
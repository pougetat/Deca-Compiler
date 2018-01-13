#include "MethodBody.h"

MethodBody::MethodBody(
    vector<DeclVar *> * list_decl_var,
    vector<AbstractInst *> * list_inst)
{
    m_list_decl_var = list_decl_var;
    m_list_inst = list_inst;
}

void MethodBody::VerifyMethodBody(
    EnvironmentType * env_types, 
    EnvironmentExp * env_exp_sup,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * return_type)
{
    for (DeclVar * declvar : *m_list_decl_var)
    {
        declvar->VerifyDeclVar(env_types, env_exp, class_name);
    }
    for (AbstractInst * inst: *m_list_inst)
    {
        inst->VerifyInst(env_types, env_exp, class_name, return_type);
    }
}

void MethodBody::Display(string tab)
{
    cout << tab << ">" << "[METHOD BODY]" << endl;
    cout << tab << "-->" << "[LIST DECL VAR]" << endl;
    for (DeclVar * decl_var : *m_list_decl_var)
    {
        decl_var->Display(tab + "----");
    }
    cout << tab << "-->" << "[LIST INST]" << endl;
    for (AbstractInst * inst : *m_list_inst)
    {
        inst->Display(tab + "----");
    }
}

void MethodBody::CodeGenMethodBody(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    for (DeclVar * decl_var : *m_list_decl_var)
    {
        decl_var->CodeGenExpr(env_types, gen_env);
    }
    for (AbstractInst * inst : *m_list_inst)
    {
        inst->CodeGenInst(env_types, gen_env);
    }
    gen_env->output_file << "    return" << endl;
}
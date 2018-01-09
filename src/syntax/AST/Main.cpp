#include "Main.h"

void Main::Display(string tab)
{
    cout << tab << ">" << "[NON EMPTY MAIN]" << endl;
    cout << tab << "-->" << "[LIST DECL VAR]" << endl;
    for (DeclVar * declVar : *m_list_decl_var)
    {
        declVar->Display(tab + "----");
    }
    cout << tab << "-->" << "[LIST INST]" << endl;
    for (AbstractInst * inst : *m_list_inst)
    {
        inst->Display(tab + "----");
    }
}

EnvironmentExp * Main::VerifyMain(EnvironmentType * env_types)
{
    m_env_main_exp = new EnvironmentExp();

    for (DeclVar * declvar : *m_list_decl_var)
    {
        declvar->VerifyDeclVar(env_types, m_env_main_exp, NULL);
    }
    for (AbstractInst * inst: *m_list_inst)
    {
        inst->VerifyInst(env_types, m_env_main_exp, new string(""), new VoidType());
    }

    return m_env_main_exp;
}

void Main::CodeGenMain(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    gen_env->output_file << ".class public Main" << endl;
    gen_env->output_file << ".super java/lang/Object" << endl;
    gen_env->output_file << "; default constructor" << endl;
    gen_env->output_file << ".method public <init>()V" << endl;
    gen_env->output_file << "    aload_0 ; push this" << endl;
    gen_env->output_file 
        << "    invokespecial java/lang/Object/<init>()V ; call super"
        << endl;
    gen_env->output_file << "    return" << endl;
    gen_env->output_file << ".end method" << endl;
    gen_env->output_file << ".method public static main([Ljava/lang/String;)V" << endl;
    gen_env->output_file << "    ; allocate stack size" << endl;
    gen_env->output_file << "    .limit stack 10" << endl;
    gen_env->output_file << "    .limit locals 10" << endl;

    for (DeclVar * decl_var : *m_list_decl_var)
    {
        decl_var->CodeGenExpr(env_types, gen_env);
    }
    for (AbstractInst * inst : *m_list_inst)
    {
        inst->CodeGenInst(env_types, gen_env);
    }

    gen_env->output_file << "    ; return main" << endl;
    gen_env->output_file << "    return" << endl;
    gen_env->output_file << ".end method" << endl;
}
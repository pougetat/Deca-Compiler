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

void Main::VerifyMain(EnvironmentType * env_types)
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
}

void Main::CodeGenMain(ofstream * output_file)
{
    *output_file << ".class public Main" << endl;
    *output_file << ".super java/lang/Object" << endl;
    *output_file << "; default constructor" << endl;
    *output_file << ".method public <init>()V" << endl;
    *output_file << "    aload_0 ; push this" << endl;
    *output_file << "    invokespecial java/lang/Object/<init>()V ; call super"
        << endl;
    *output_file << "    return" << endl;
    *output_file << ".end method" << endl;
    *output_file << ".method public static main([Ljava/lang/String;)V" << endl;
    *output_file << "    ; allocate stack size" << endl;
    *output_file << "    .limit stack 10" << endl;

    for (AbstractInst * inst : *m_list_inst)
    {
        inst->CodeGenInst(output_file);
    }

    *output_file << "    ; return main" << endl;
    *output_file << "    return" << endl;
    *output_file << ".end method" << endl;
}
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
        declvar->VerifyDeclVar(env_types, NULL, m_env_main_exp, NULL);
    }
    for (AbstractInst * inst: *m_list_inst)
    {
        inst->VerifyInst(env_types, m_env_main_exp, new string(""), new VoidType());
    }

}
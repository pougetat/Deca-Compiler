#include "Main.h"

void Main::Display(string tab)
{
    cout << tab << ">" << "[NON EMPTY MAIN]" << endl;
    cout << tab << "-->" << "[LIST DECL VAR]" << endl;
    for (DeclVar * declVar : *list_decl_var)
    {
        declVar->Display(tab + "----");
    }
    cout << tab << "-->" << "[LIST INST]" << endl;
    for (AbstractInst * inst : *list_inst)
    {
        inst->Display(tab + "----");
    }
}
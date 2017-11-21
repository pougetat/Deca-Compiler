#include "NonEmptyMain.h"

void NonEmptyMain::Display(string tab)
{
    cout << tab << ">" << "[NON EMPTY MAIN]" << endl;
    if ((*list_decl_var).size() > 0)
    {
        cout << tab << "-->" << "[LIST DECL VAR]" << endl;
        for (DeclVar declVar : *list_decl_var)
        {
            declVar.Display(tab + "----");
        }
    }
}
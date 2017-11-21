#ifndef NON_EMPTY_MAIN_H
#define NON_EMPTY_MAIN_H

#include "AbstractMain.h"
#include "AbstractInst.h"
#include "DeclVar.h"
#include <vector>
#include <iostream>

using namespace std;

class NonEmptyMain : public AbstractMain 
{
    public:

        vector<DeclVar> * list_decl_var;
        vector<AbstractInst> * list_inst;

        void Display(string tab);
};

#endif
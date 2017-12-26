#ifndef NON_EMPTY_MAIN_H
#define NON_EMPTY_MAIN_H

#include "AbstractMain.h"
#include "AbstractInst.h"
#include "DeclVar.h"

#include <vector>
#include <fstream>

using namespace std;

class Main : public AbstractMain 
{
    public:

        vector<DeclVar *> * m_list_decl_var;
        
        vector<AbstractInst *> * m_list_inst;

        EnvironmentExp * m_env_main_exp;

        void VerifyMain(EnvironmentType * env_types);

        void Display(string tab);

        void CodeGenMain(ofstream * output_file);
};

#endif
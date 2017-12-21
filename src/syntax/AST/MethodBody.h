#ifndef METHOD_BODY_H
#define METHOD_BODY_H

#include "DeclVar.h"
#include "AbstractInst.h"

#include <vector>

using namespace std;

class MethodBody
{
    public:

        vector<DeclVar *> * m_list_decl_var;
        
        vector<AbstractInst *> * m_list_inst;

        MethodBody(
            vector<DeclVar *> * list_decl_var,
            vector<AbstractInst *> * list_inst
        );

        void VerifyMethodBody(
            EnvironmentType * env_types, 
            EnvironmentExp * env_exp_sup,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * return_type
        );

        void Display(string tab);
};

#endif
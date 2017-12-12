#ifndef PROGRAM_H
#define PROGRAM_H

#include "DeclClass.h"
#include "AbstractMain.h"
#include "../../context/EnvironmentType.h"
#include <vector>

using namespace std;

class Program
{
    public:

        vector<DeclClass *> * m_list_decl_class;

        AbstractMain * m_main;

        void Display(string tab);
        
        void VerifyClassHierarchy(EnvironmentType * env_types_predef);

        void VerifyProgramPass3(EnvironmentType * env_type);
};

#endif
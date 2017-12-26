#ifndef PROGRAM_H
#define PROGRAM_H

#include "DeclClass.h"
#include "AbstractMain.h"
#include "../../context/EnvironmentType.h"

#include <vector>
#include <fstream>

using namespace std;

class Program
{
    public:
        vector<DeclClass *> * m_list_decl_class;

        AbstractMain * m_main;

        void Display(string tab);
        
        void VerifyClassNames(EnvironmentType * env_types);

        void VerifyClassHierarchy(EnvironmentType * env_types);

        void VerifyClassMF(EnvironmentType * env_types);

        void VerifyClassMFHierarchy(EnvironmentType * env_types);

        void VerifyProgramPass3(EnvironmentType * env_types);

        void GenCode();
};

#endif
#ifndef PROGRAM_H
#define PROGRAM_H

#include "DeclClass.h"
#include "AbstractMain.h"
#include <vector>

using namespace std;

class Program {

    public:
        vector<DeclClass> list_decl_class;
        AbstractMain main;

};

#endif
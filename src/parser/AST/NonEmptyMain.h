#ifndef NON_EMPTY_MAIN_H
#define NON_EMPTY_MAIN_H

#include "AbstractMain.h"
#include "AbstractInst.h"
#include <vector>

using namespace std;

class NonEmptyMain : public AbstractMain 
{
    public:

        vector<AbstractInst> list_inst;
};

#endif
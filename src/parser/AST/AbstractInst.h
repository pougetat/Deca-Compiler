#ifndef ABSTRACT_INST_H
#define ABSTRACT_INST_H

#include <iostream>

using namespace std;

class AbstractInst {

    public:

        virtual void Display(string tab) = 0;

};

#endif
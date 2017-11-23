#ifndef ABSTRACT_INST_H
#define ABSTRACT_INST_H

#include "AbstractTreeNode.h"
#include <iostream>

using namespace std;

class AbstractInst : public AbstractTreeNode {

    public:

        virtual void Display(string tab) = 0;

};

#endif
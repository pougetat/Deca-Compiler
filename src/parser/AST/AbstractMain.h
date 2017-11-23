#ifndef ABSTRACT_MAIN_H
#define ABSTRACT_MAIN_H

#include <ostream>
#include "AbstractTreeNode.h"

using namespace std;

class AbstractMain : public AbstractTreeNode
{
    public:

        virtual void Display(string tab);

};

#endif
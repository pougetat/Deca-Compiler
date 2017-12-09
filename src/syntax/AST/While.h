#ifndef WHILE_H
#define WHILE_H

#include "AbstractInst.h"
#include "AbstractExpr.h"
#include <vector>

using namespace std;

class While : public AbstractInst
{
    public:

        AbstractExpr * m_condition;
        vector<AbstractInst *> * m_insts;

        While(AbstractExpr * condition, vector<AbstractInst *> * insts);
        void Display(string tab);
        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * return_type
        );
};

#endif
#include "While.h"

While::While(AbstractExpr * condition, vector<AbstractInst *> * insts)
{
    m_condition = condition;
    m_insts = insts;
}

void While::Display(string tab)
{
    cout << tab << ">" << "[WHILE]" << endl;
    cout << tab << "-->" << "[CONDITION]" << endl;
    if (m_condition != NULL)
    {
        m_condition->Display(tab + "----");
    }
    cout << tab << "-->" << "[LIST INST]" << endl;
    if (m_insts->size() > 0)
    {
        for (AbstractInst * inst : *m_insts)
        {
            inst->Display(tab + "----");
        }
    }
}

void While::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    AbstractType * return_type)
{
    
}
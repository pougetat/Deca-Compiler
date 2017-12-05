#include "IfThenElse.h"

IfThenElse::IfThenElse(
    AbstractExpr * condition, 
    vector<AbstractInst *> * insts,
    vector<AbstractInst *> * else_insts)
{
    m_condition = condition;
    m_insts = insts;
    m_else_insts = else_insts;
}

void IfThenElse::Display(string tab)
{
    cout << tab << ">" << "[IF THEN ELSE]" << endl;
    cout << tab << "-->" << "[CONDITION]" << endl;
    if (m_condition != NULL)
    {
        m_condition->Display(tab + "----");
    }
    cout << tab << "-->" << "[LIST INST]" << endl;
    for (AbstractInst * inst : *m_insts)
    {
        inst->Display(tab + "----");
    }
    cout << tab << "-->" << "[ELSE]" << endl;
    for (AbstractInst * inst : *m_else_insts)
    {
        inst->Display(tab + "----");
    }
}
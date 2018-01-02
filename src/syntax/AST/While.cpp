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
    AbstractType * condition_type = m_condition->VerifyExpr(
        env_types,
        env_exp,
        class_name
    );

    if (!condition_type->IsBooleanType())
    {
        throw runtime_error("[WHILE : BOOLEAN CONDITION EXPECTED]");
    }

    for (AbstractInst * inst : *m_insts)
    {
        inst->VerifyInst(
            env_types,
            env_exp,
            class_name,
            return_type
        );
    }
}

void While::CodeGenInst(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{}
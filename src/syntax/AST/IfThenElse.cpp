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

void IfThenElse::VerifyInst(
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
        throw runtime_error("[IF THEN ELSE : BOOLEAN CONDITION EXPECTED]");
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
    for (AbstractInst * inst : *m_else_insts)
    {
        inst->VerifyInst(
            env_types,
            env_exp,
            class_name,
            return_type
        );
    }
}

void IfThenElse::CodeGenInst(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    int label_num = gen_env->GetNewLabel();

    m_condition->CodeGenExpr(env_types, gen_env);
    gen_env->output_file << "    ifeq label" << label_num << ".else" << endl;
    
    for (AbstractInst * inst : *m_insts)
    {
        inst->CodeGenInst(env_types, gen_env);
    }
    gen_env->output_file << "    goto label" << label_num << ".endif" << endl;
    gen_env->output_file << "    label" << label_num << ".else:" << endl;
    
    for (AbstractInst * inst : *m_else_insts)
    {
        inst->CodeGenInst(env_types, gen_env);
    }

    gen_env->output_file << "    label" << label_num << ".endif:" << endl;
}
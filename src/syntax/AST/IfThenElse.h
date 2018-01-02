#ifndef IF_THEN_ELSE_H
#define IF_THEN_ELSE_H

#include "AbstractInst.h"
#include "AbstractExpr.h"
#include <vector>

using namespace std;

class IfThenElse : public AbstractInst
{
    public:

        AbstractExpr * m_condition;
        
        vector<AbstractInst *> * m_insts;
        
        vector<AbstractInst *> * m_else_insts;

        IfThenElse(
            AbstractExpr * condition, 
            vector<AbstractInst *> * m_insts,
            vector<AbstractInst *> * m_else_insts
        );
        
        void Display(string tab);
        
        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * return_type
        );

        void CodeGenInst(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );
};

#endif
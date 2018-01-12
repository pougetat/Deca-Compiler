#ifndef METHOD_CALL_H
#define METHOD_CALL_H

#include "AbstractExpr.h"
#include "Identifier.h"
#include "This.h"
#include <vector>

using namespace std;

class MethodCall : public AbstractExpr
{
    public:
 
        AbstractExpr * m_selection_expr;
        
        Identifier * m_method_identifier;
        
        vector<AbstractExpr *> * m_method_args;

        MethodCall(
            Identifier * method_name, 
            vector<AbstractExpr *> * method_args
        );

        MethodCall(
            AbstractExpr * selection_expr, 
            Identifier * method_name, 
            vector<AbstractExpr *> * method_args
        );

        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );

        void CodeGenExpr(
            EnvironmentType * env_types,
            GeneratorEnvironment * gen_env
        );

    private:

        ExpDefinition * VerifyClassHasMethod(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
        void VerifyMethodParams(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            vector<AbstractType *> * method_exp_nature
        );
};

#endif
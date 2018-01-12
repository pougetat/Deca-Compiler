#include "MethodCall.h"

MethodCall::MethodCall(
    AbstractExpr * selection_expr,
    Identifier * method_name, 
    vector<AbstractExpr *> * method_args)
{
    if (selection_expr == NULL)
    {
        m_selection_expr = new This(true);
    }
    else
    {
        m_selection_expr = selection_expr;
    }
    m_method_identifier = method_name;
    m_method_args = method_args;
}

AbstractExpr * MethodCall::Clone()
{
    vector<AbstractExpr *> * method_args;
    for (AbstractExpr * expr : *m_method_args)
    {
        method_args->push_back(expr->Clone());
    }

    MethodCall * method_call = new MethodCall(
        m_selection_expr->Clone(),
        new Identifier(m_method_identifier->m_symbol),
        method_args
    );

    return method_call;
}

void MethodCall::Display(string tab)
{
    cout << tab << ">" << "[METHOD CALL]" << endl;
    if (m_selection_expr != NULL)
    {
        m_selection_expr->Display(tab + "--");
    }
    m_method_identifier->Display(tab + "--");
    if (m_method_args->size() > 0)
    {
        cout << tab << "-->" << "[LIST EXPR]" << endl;
        for (AbstractExpr * arg : *m_method_args)
        {
            arg->Display(tab + "----");
        }
    }
}

AbstractType * MethodCall::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    ExpDefinition * method_exp = VerifyClassHasMethod(
        env_types,
        env_exp,
        class_name
    );

    VerifyMethodParams(
        env_types,
        env_exp,
        class_name,
        ((MethodExpNature *) method_exp->GetTypeNature())->GetMethodSignature()
    );

    return method_exp->GetType();
}

void MethodCall::CodeGenExpr(
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{}

// PRIVATE METHODS

ExpDefinition * MethodCall::VerifyClassHasMethod(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    AbstractType * selection_expr_type = 
        m_selection_expr->VerifyExpr(
            env_types,
            env_exp,
            class_name
        );

    string selection_class_name = 
        ((ClassType *) selection_expr_type)->m_class_name;

    EnvironmentExp * class_env_exp = 
        env_types->GetClassEnvExp(
            selection_class_name
        );

    if (!class_env_exp->ContainsSymbol(m_method_identifier->m_symbol))
    {
        throw runtime_error(
            "[METHOD CALL : '" + m_method_identifier->m_symbol + "' "
            + "does not belong to class '" +  selection_class_name + "']"
        );
    }

    return class_env_exp->GetExpDefinition(m_method_identifier->m_symbol);
}

void MethodCall::VerifyMethodParams(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name,
    vector<AbstractType *> * method_signature)
{
    if (method_signature->size() != m_method_args->size())
    {
        throw runtime_error(
            "[METHOD CALL : '"  + m_method_identifier->m_symbol + "' "
            + "mismatch between argument length and signature length]"
        );
    }

    for (int param_num = 0; param_num < method_signature->size(); param_num++)
    {
        AbstractType * arg_type = m_method_args->at(param_num)->VerifyExpr(
            env_types,
            env_exp,
            class_name
        );
        AbstractType * expected_type = method_signature->at(param_num);

        if (!arg_type->IsSameType(expected_type))
        {
            throw runtime_error(
                "[METHOD CALL : '" + m_method_identifier->m_symbol + "' : "
                + "expected param of type '" + expected_type->Symbol()
                + "' but found type '" + arg_type->Symbol() + "']"
            );
        }   
    }
}
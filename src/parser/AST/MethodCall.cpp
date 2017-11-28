#include "MethodCall.h"

MethodCall::MethodCall(
    Identifier * method_name, 
    vector<AbstractExpr *> * method_args
)
{
    m_selection_expr = NULL;
    m_method_identifier = method_name;
    m_method_args = method_args;
}

MethodCall::MethodCall(
    AbstractExpr * selection_expr,
    Identifier * method_name, 
    vector<AbstractExpr *> * method_args
)
{
    m_selection_expr = selection_expr;
    m_method_identifier = method_name;
    m_method_args = method_args;
}

void MethodCall::Display(string tab)
{
    cout << tab << ">" << "[METHOD CALL]" << endl;
    if (m_selection_expr != NULL)
    {
        m_selection_expr->Display(tab + "----");
    }
    m_method_identifier->Display(tab + "---");
    if (m_method_args->size() > 0)
    {
        cout << tab << "-->" << "[LIST EXPR]" << endl;
        for (AbstractExpr * arg : *m_method_args)
        {
            arg->Display(tab + "----");
        }
    }
}
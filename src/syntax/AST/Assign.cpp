#include "Assign.h"

Assign::Assign(AbstractExpr * expr, AbstractExpr * assign)
{
    m_lvalue = expr;
    m_assign = assign;
}

AbstractExpr * Assign::Clone()
{
    return new Assign(
        m_lvalue->Clone(), 
        m_assign->Clone()
    );
}

void Assign::Display(string tab)
{
    cout << tab << ">" << "[ASSIGN]" << endl;
    m_lvalue->Display(tab + "--");
    m_assign->Display(tab + "--");
}

void Assign::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name,
    AbstractType return_type)
{

}
#include "Print.h"

Print::Print(TokenType token_type)
{
    m_token_type = token_type;
}

void Print::Display(string tab)
{
    cout << tab << ">[PRINT]"<< endl;
    for (AbstractExpr * expr : *m_list_args)
    {
        expr->Display(tab + "--");
    }
}

void Print::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name,
    AbstractType * return_type)
{
    
}
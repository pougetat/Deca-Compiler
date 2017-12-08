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
    for (AbstractExpr * expr : *m_list_args)
    {
        AbstractType * expr_type =
            expr->VerifyExpr(env_types, env_exp, class_name);
        if (!expr_type->IsFloatType() && !expr_type->IsIntType() 
            && !expr_type->IsStringType())
        {
            throw runtime_error(
                "[PRINT : FLOAT, INT, STRING OPERAND EXPECTED]"
            );
        }
    }
}
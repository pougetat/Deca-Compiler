#include "Divide.h"

Divide::Divide(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Divide::Clone()
{
    return new Divide(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Divide::Display(string tab)
{
    cout << tab << ">" << "[DIVIDE]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

void Divide::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name,
    AbstractType return_type)
{
    
}
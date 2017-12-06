#include "BooleanLiteral.h"

BooleanLiteral::BooleanLiteral(bool value)
{
    m_value = value;
}

AbstractExpr * BooleanLiteral::Clone()
{
    return new BooleanLiteral(m_value);
}

void BooleanLiteral::Display(string tab)
{
    cout << tab << ">" << "[BOOLEAN_LITERAL] VALUE : " << m_value << endl;
}

void BooleanLiteral::VerifyInst(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name,
    AbstractType return_type)
{

}
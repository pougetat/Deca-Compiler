#include "StringLiteral.h"

StringLiteral::StringLiteral(string value)
{
    m_value = value;
}

AbstractExpr * StringLiteral::Clone()
{
    return new StringLiteral(m_value);
}

void StringLiteral::Display(string tab)
{
    cout << tab << ">" << "[STRING LITERAL] VALUE : " << m_value << endl;
}

AbstractType * StringLiteral::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string class_name)
{
    return new StringType();
}
#include "IntLiteral.h"

IntLiteral::IntLiteral(int value)
{
    m_value = value;
}

AbstractExpr * IntLiteral::Clone()
{
    return new IntLiteral(m_value);
}

void IntLiteral::Display(string tab)
{
    cout << tab << ">" << "[INT_LITERAL] VALUE : " << m_value << endl;
}

AbstractType * IntLiteral::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    return new IntType();
}
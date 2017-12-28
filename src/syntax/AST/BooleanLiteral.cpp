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

AbstractType * BooleanLiteral::VerifyExpr(
    EnvironmentType * env_types,
    EnvironmentExp * env_exp,
    string * class_name)
{
    m_expr_type = new BooleanType();
    return new BooleanType();
}

void BooleanLiteral::CodeGenExpr(ofstream * output_file)
{
    *output_file
        << "    ; pushing true on the stack"
        << endl;

    if (m_value)
    {
        *output_file
            << "    iconst_1"
            << endl;
    }
    else
    {
        *output_file
            << "    iconst_0"
            << endl;
    }
}
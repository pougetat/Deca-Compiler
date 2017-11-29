#include "InstanceOf.h"

InstanceOf::InstanceOf(
    AbstractExpr * expr, 
    Identifier * instanceof_type
)
{
    m_expr = expr;
    m_instanceof_type = instanceof_type;
}

AbstractExpr * InstanceOf::Clone()
{
    return new InstanceOf(
        m_expr->Clone(),
        new Identifier(m_instanceof_type->m_symbol)
    );
}

void InstanceOf::Display(string tab)
{
    cout << tab << ">" << "[INSTANCEOF]" << endl;
    m_expr->Display(tab + "--");
    m_instanceof_type->Display(tab + "--");
}
#include "Cast.h"

Cast::Cast(Identifier * cast_type, AbstractExpr * expr)
{
    m_cast_type = cast_type;
    m_expr = expr;
}

void Cast::Display(string tab)
{
    cout << tab << ">" << "[CAST]" << endl;
    m_cast_type->Display(tab + "--");
    m_expr->Display(tab + "--");
}
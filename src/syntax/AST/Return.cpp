#include "Return.h"

Return::Return(AbstractExpr * return_expr)
{
    m_return_expr = return_expr;
}

void Return::Display(string tab)
{
    cout << tab << ">" << "[RETURN]" << endl;
    if (m_return_expr != NULL)
    {
        m_return_expr->Display(tab + "--");
    }
}
#include "Initialization.h"

Initialization::Initialization(AbstractExpr * expr)
{
    m_expr = expr;
}

void Initialization::Display(string tab)
{
    cout << tab << ">" << "[INITIALIZATION]" << endl;
    m_expr->Display(tab + "--");
}
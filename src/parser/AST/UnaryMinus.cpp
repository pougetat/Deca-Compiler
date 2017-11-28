#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(AbstractExpr * expr)
{
    m_expr = expr;
}

void UnaryMinus::Display(string tab)
{
    cout << tab << ">" << "[UNARY MINUS]" << endl;
    m_expr->Display(tab + "--");
}
#include "UnaryMinus.h"

UnaryMinus::UnaryMinus(AbstractExpr * expr)
{
    m_expr = expr;
}

AbstractExpr * UnaryMinus::Clone()
{
    return new UnaryMinus(m_expr);
}

void UnaryMinus::Display(string tab)
{
    cout << tab << ">" << "[UNARY MINUS]" << endl;
    m_expr->Display(tab + "--");
}
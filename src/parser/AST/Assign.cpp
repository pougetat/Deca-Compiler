#include "Assign.h"

Assign::Assign(AbstractExpr * expr, AbstractExpr * assign)
{
    m_lvalue = expr;
    m_assign = assign;
}

AbstractExpr * Assign::Clone()
{
    return new Assign(
        m_lvalue->Clone(), 
        m_assign->Clone()
    );
}

void Assign::Display(string tab)
{
    cout << tab << ">" << "[ASSIGN]" << endl;
    m_lvalue->Display(tab + "--");
    m_assign->Display(tab + "--");
}
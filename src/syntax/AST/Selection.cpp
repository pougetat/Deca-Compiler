#include "Selection.h"

AbstractExpr * Selection::Clone()
{
    Selection * selection = new Selection();
    selection->m_identifier = new Identifier(m_identifier->m_symbol);
    selection->m_selection_expr = m_selection_expr->Clone();
    return selection;
}

void Selection::Display(string tab)
{
    cout << tab << ">" << "[SELECTION]" << endl;
    m_selection_expr->Display(tab + "--");
    m_identifier->Display(tab + "--");
}
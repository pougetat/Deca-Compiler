#include "Plus.h"

Plus::Plus(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Plus::Clone()
{
    return new Plus(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Plus::Display(string tab)
{
    cout << tab << ">" << "[PLUS]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

void Plus::CodeGenExpr(ofstream * output_file)
{
    m_left_operand->CodeGenExpr(output_file);
    m_right_operand->CodeGenExpr(output_file);
    
    *output_file << "    ; adding two stack elements" << endl;
    *output_file << "    iadd " << endl;
}
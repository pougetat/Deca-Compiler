#include "Multiply.h"

Multiply::Multiply(AbstractExpr * e1, AbstractExpr * e2)
{
    m_left_operand = e1;
    m_right_operand = e2;
}

AbstractExpr * Multiply::Clone()
{
    return new Multiply(
        m_left_operand->Clone(), 
        m_right_operand->Clone()
    );
}

void Multiply::Display(string tab)
{
    cout << tab << ">" << "[MULTIPLY]" << endl;
    m_left_operand->Display(tab + "--");
    m_right_operand->Display(tab + "--");
}

void Multiply::CodeGenExpr(ofstream * output_file)
{
    m_left_operand->CodeGenExpr(output_file);
    m_right_operand->CodeGenExpr(output_file);
    
    *output_file << "    ; multiplying two stack elements" << endl;
    *output_file << "    imul" << endl;
}
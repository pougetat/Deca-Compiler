#include "This.h"

This::This(bool value)
{
    m_value = value;
}

void This::Display(string tab)
{
    cout << tab << ">" << "[THIS] VALUE : " << m_value << endl;
}
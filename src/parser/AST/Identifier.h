#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <iostream>

using namespace std;

class Identifier
{
    public:

        string m_symbol;

        Identifier(string symbol);
        void Display(string tab);
};

#endif
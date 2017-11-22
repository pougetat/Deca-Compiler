#ifndef PRINT_H
#define PRINT_H

#include <vector>
#include "AbstractExpr.h"
#include "AbstractInst.h"
#include "../../lexer/token.h"

using namespace std;

class Print : public AbstractInst {

    public:

        vector<AbstractExpr *> * list_expr;
        TokenType m_token_type;

        Print(TokenType token_type);
        void Display(string tab);

};

#endif
#ifndef PRINT_H
#define PRINT_H

#include <vector>
#include "AbstractExpr.h"
#include "AbstractInst.h"
#include "../../lexer/token.h"

using namespace std;

class Print : public AbstractInst {

    public:

        vector<AbstractExpr *> * m_list_args;
        TokenType m_token_type;

        Print(TokenType token_type);
        
        void Display(string tab);
        
        void VerifyInst(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name,
            AbstractType * return_type
        );
};

#endif
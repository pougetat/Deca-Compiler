#ifndef THIS_H
#define THIS_H

#include "AbstractExpr.h"
#include <iostream>

using namespace std;

class This : public AbstractExpr
{
    public:
        
        bool m_value;

        This(bool value);

        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string class_name
        );
};

#endif
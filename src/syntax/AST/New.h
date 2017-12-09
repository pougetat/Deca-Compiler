#ifndef NEW_H
#define NEW_H

#include "AbstractExpr.h"
#include "Identifier.h"
#include <vector>

using namespace std;

class New : public AbstractExpr
{
    public:
 
        Identifier * m_class_name;

        New(Identifier * class_name);

        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
};

#endif
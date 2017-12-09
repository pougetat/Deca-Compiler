#ifndef MODULO_H
#define MODULO_H

#include "AbstractOpArith.h"

class Modulo : public AbstractOpArith
{
    public:

        Modulo(AbstractExpr * expr1, AbstractExpr * expr2);
        
        AbstractExpr * Clone();
        
        void Display(string tab);

        AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );

        bool IsPlus();
        bool IsMinus();
        bool IsMultiply();
        bool IsDivide();
        bool IsModulo();
};

#endif
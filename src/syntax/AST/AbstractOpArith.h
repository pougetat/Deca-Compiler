#ifndef ABSTRACT_OP_ARITH_H
#define ABSTRACT_OP_ARITH_H

#include "AbstractBinaryExpr.h"

class AbstractOpArith : public AbstractBinaryExpr
{
    public:
	
		virtual bool IsPlus() = 0;
		virtual bool IsMinus() = 0;
		virtual bool IsMultiply() = 0;
		virtual bool IsDivide() = 0;
		virtual bool IsModulo() = 0;

        virtual AbstractType * VerifyExpr(
            EnvironmentType * env_types,
            EnvironmentExp * env_exp,
            string * class_name
        );
};

#endif
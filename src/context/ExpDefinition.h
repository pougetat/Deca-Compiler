#ifndef EXP_DEFINITION_H
#define EXP_DEFINITION_H

#include "AbstractDefinition.h"
#include "AbstractType.h"
#include "AbstractExpNature.h"

class ExpDefinition : public AbstractDefinition
{

    public:
        
        AbstractExpNature * m_exp_nature;
        
        AbstractType * m_type;
        
        ExpDefinition(AbstractExpNature * exp_nature, AbstractType * type);
        
        AbstractType * GetType();

        AbstractExpNature * GetTypeNature();


};

#endif
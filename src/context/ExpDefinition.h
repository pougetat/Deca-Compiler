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

        int m_memory_location;
        
        ExpDefinition(AbstractExpNature * exp_nature, AbstractType * type);
        
        void SetMemoryLocation(int memory_location);

        AbstractType * GetType();

        AbstractExpNature * GetTypeNature();

        int GetMemoryLocation();
};

#endif
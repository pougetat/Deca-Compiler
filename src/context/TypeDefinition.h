#ifndef TYPE_DEFINITION_H
#define TYPE_DEFINITION_H

#include "AbstractType.h"
#include "AbstractTypeNature.h"
#include "AbstractDefinition.h"

class TypeDefinition : public AbstractDefinition
{

    public:
        
        AbstractTypeNature * m_type_nature;
        
        AbstractType * m_type;
        
        TypeDefinition(AbstractTypeNature * type_nature, AbstractType * type);
        
        AbstractType * GetType();


};

#endif
#ifndef DECL_FIELD_H
#define DECL_FIELD_H

#include "Identifier.h"
#include "AbstractInitialization.h"

#include "../../context/EnvironmentType.h"
#include "../../context/FieldExpNature.h"

enum Visibility 
{
    VISIBILITY_PROTECTED,
    VISIBILITY_PRIVATE
};

class DeclField {

    public:

        Visibility m_field_visibility;
        
        Identifier * m_field_type;

        Identifier * m_field_name;

        AbstractInitialization * m_init;

        void VerifyFieldNoInit(
            EnvironmentType * env_types, 
            Identifier * class_name
        );

        void VerifyFieldHierarchy(
            EnvironmentType * env_types,
            Identifier * class_name
        );

        void VerifyFieldInit(
            EnvironmentType * env_types,
            Identifier * class_name
        );

        void Display(string tab);

    private:

        void InsertFieldExpDefinition(
            EnvironmentType * env_types,
            Identifier * class_name
        );
};

#endif
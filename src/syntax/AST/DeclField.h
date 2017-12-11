#ifndef DECL_FIELD_H
#define DECL_FIELD_H

#include <string>
#include <iostream>

#include "Identifier.h"
#include "AbstractInitialization.h"

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

        void Display(string tab);

};

#endif
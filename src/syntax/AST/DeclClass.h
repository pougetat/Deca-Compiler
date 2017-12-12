#ifndef DECL_CLASS_H
#define DECL_CLASS_H

#include "Identifier.h"
#include "DeclField.h"
#include "DeclMethod.h"

#include "../../context/ClassTypeNature.h"
#include "../../context/ClassType.h"

#include <vector>

class DeclClass {

    public:

        Identifier * m_class_name;
        
        Identifier * m_parent_class_name;
        
        vector<DeclField *> * m_class_fields;
        
        vector<DeclMethod *> * m_class_methods;

        void VerifyClassName(EnvironmentType * env_types);

        void VerifyClassHierarchy(EnvironmentType * env_types);

        void Display(string tab);

};

#endif
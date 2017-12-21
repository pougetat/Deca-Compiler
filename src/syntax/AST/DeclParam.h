#ifndef DECL_PARAM_H
#define DECL_PARAM_H

#include "Identifier.h"

class DeclParam
{
    public:
        
        Identifier * m_param_type;

        Identifier * m_param_name;

        void VerifyDeclParam(
            EnvironmentType * env_types,
            Identifier * class_name,
            Identifier * method_name
        );

        void Display(string tab);

    private:

        void AddTypeToSignature(
            EnvironmentType * env_types,
            Identifier * class_name,
            Identifier * method_name
        );
};

#endif
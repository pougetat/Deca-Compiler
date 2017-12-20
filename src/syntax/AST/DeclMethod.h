#ifndef DECL_METHOD_H
#define DECL_METHOD_H

#include <string>
#include <iostream>
#include <vector>

#include "Identifier.h"
#include "DeclParam.h"
#include "MethodBody.h"

#include "../../context/EnvironmentType.h"
#include "../../context/MethodExpNature.h"

using namespace std;

class DeclMethod {

    public:

        Identifier * m_return_type;
        
        Identifier * m_name;

        vector<DeclParam *> * m_params;

        MethodBody * m_body;

        void VerifyMethodSignature(
            EnvironmentType * env_types,
            Identifier * class_name
        );

        void Display(string tab);

    private:

        void VerifyParamTypes(
            EnvironmentType * env_types,
            Identifier * class_name
        );
};

#endif
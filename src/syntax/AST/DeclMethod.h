#ifndef DECL_METHOD_H
#define DECL_METHOD_H

#include <string>
#include <iostream>
#include <vector>

#include "Identifier.h"
#include "DeclParam.h"
#include "MethodBody.h"

using namespace std;

class DeclMethod {

    public:

        Identifier * m_method_return_type;
        
        Identifier * m_method_name;

        vector<DeclParam *> * m_list_param;

        MethodBody * m_method_body;

        void Display(string tab);
};

#endif
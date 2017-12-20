#ifndef ENVIRONMENT_TYPE_H
#define ENVIRONMENT_TYPE_H

#include <map>
#include <string>
#include <iostream>

#include "TypeDefinition.h"
#include "ExpDefinition.h"

#include "TypeTypeNature.h"
#include "ClassTypeNature.h"

#include "MethodExpNature.h"

#include "AbstractType.h"
#include "IntType.h"
#include "FloatType.h"
#include "BooleanType.h"
#include "VoidType.h"
#include "StringType.h"
#include "ClassType.h"

using namespace std;

class EnvironmentType
{
    public:
        
        map<string, TypeDefinition*> * m_env_types;
        
        EnvironmentType();
        
        bool TypeExists(string type_symbol);
        
        TypeDefinition * GetTypeDefinition(string type_def_symbol);

        AbstractType * GetType(string type_symbol);

        void InsertType(string symbol, TypeDefinition * type_def);

        EnvironmentExp * GetClassEnvExp(string class_name);

        void AddTypeToSignature(
            string class_name,
            string method_name,
            AbstractType * type
        );

        void SetParentClass(string child_class, string parent_class);
};

#endif
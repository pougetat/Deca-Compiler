#ifndef ENVIRONMENT_TYPE_H
#define ENVIRONMENT_TYPE_H

#include <map>
#include <string>
#include <iostream>

#include "TypeDefinition.h"

#include "TypeTypeNature.h"
#include "ClassTypeNature.h"

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
        
        AbstractType * GetType(string type_symbol);

        void InsertType(string symbol, TypeDefinition * type_def);
};

#endif
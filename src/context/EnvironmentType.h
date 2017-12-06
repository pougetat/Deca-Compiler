#ifndef ENVIRONMENT_TYPE_H
#define ENVIRONMENT_TYPE_H

#include <map>
#include <string>

#include "TypeDefinition.h"

#include "TypeTypeNature.h"

#include "IntType.h"
#include "FloatType.h"
#include "BooleanType.h"

using namespace std;

class EnvironmentType
{
    public:
        map<string, TypeDefinition> * m_env_types;
        EnvironmentType();
        bool TypeExists(string type_symbol);
        
};

#endif
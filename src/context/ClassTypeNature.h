#ifndef CLASS_TYPE_NATURE_H
#define CLASS_TYPE_NATURE_H

#include "AbstractTypeNature.h"
#include "EnvironmentExp.h"

#include <string>

using namespace std;

class ClassTypeNature : public AbstractTypeNature
{
    public:
        
        string m_super_class_name;

        EnvironmentExp * m_class_env_exp;

        ClassTypeNature(string m_super_class_name);

        EnvironmentExp * GetEnvExp();
};

#endif
#ifndef CLASS_TYPE_NATURE_H
#define CLASS_TYPE_NATURE_H

#include "AbstractTypeNature.h"
#include "EnvironmentExp.h"

#include <string>

using namespace std;

class ClassTypeNature : public AbstractTypeNature
{
    public:
        
        string m_parent_class_name;

        EnvironmentExp * m_class_env_exp;

        ClassTypeNature(
            string super_class_name,
            string class_name
        );

        EnvironmentExp * GetEnvExp();

        void SetParentClass(
            string parent_class_symbol,
            EnvironmentExp * parent_class_env_exp
        );
};

#endif
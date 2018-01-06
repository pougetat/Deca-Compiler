#ifndef GENERATOR_ENVIRONMENT_H
#define GENERATOR_ENVIRONMENT_H

#include <fstream>
#include "../context/EnvironmentExp.h"

class GeneratorEnvironment
{
    public:
        
        int m_num_vars = 0;

        int m_num_labels = 0;

        ofstream output_file = ofstream("results.j");

        EnvironmentExp * m_env_exp;

        GeneratorEnvironment(EnvironmentExp * env_exp);

        void IncrNumVars();

        void SetMemoryLocation(string var_symbol);

        int GetMemoryLocation(string var_symbol);
};

#endif
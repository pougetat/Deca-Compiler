#ifndef GENERATOR_ENVIRONMENT_H
#define GENERATOR_ENVIRONMENT_H

#include <fstream>
#include "../context/EnvironmentExp.h"
#include "../context/EnvironmentType.h"

class GeneratorEnvironment
{
    public:

        ofstream output_file;

        EnvironmentExp * m_env_exp;

        GeneratorEnvironment(EnvironmentExp * env_exp, string * jasmin_file);

        void GenLoadFromMemory(
            EnvironmentType * env_types,
            string var_symbol
        );

        void GenStoreInMemory(
            EnvironmentType * env_types,
            string var_symbol
        );

        int GetNewLabel();

        void SetLocalMemoryLocation(string var_symbol);

    private:

        int m_num_vars = 0;

        int m_num_labels = 0;

        void GenLoadLocalFromMemory(
            EnvironmentType * env_types,
            string var_symbol,
            ExpDefinition * var_exp
        );

        void GenLoadFieldFromMemory(
            EnvironmentType * env_types,
            string var_symbol,
            ExpDefinition * var_exp
        );

        void GenStoreLocalInMemory(
            EnvironmentType * env_types,
            string var_symbol
        );

        void GenStoreFieldInMemory(
            EnvironmentType * env_types,
            string var_symbol
        );

        int GetLocalMemoryLocation(string var_symbol);
};

#endif
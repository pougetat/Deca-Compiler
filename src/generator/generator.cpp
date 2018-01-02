#include "Generator.h"

void Generator::GenCode(
    Program * prog,
    EnvironmentType * env_types,
    GeneratorEnvironment * gen_env)
{
    prog->GenCode(env_types, gen_env);
}
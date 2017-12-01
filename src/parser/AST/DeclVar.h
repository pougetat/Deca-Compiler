#ifndef DECL_VAR_H
#define DECL_VAR_H

#include "Identifier.h"
#include "AbstractInitialization.h"

class DeclVar {

    public:

        Identifier * m_type;
        Identifier * m_symbol;
        AbstractInitialization * m_init;

        void Display(string tab);


};

#endif
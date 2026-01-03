//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_TYPECORAPI_H
#define SERVEURCPP_TYPECORAPI_H

// INCLUSIONS

#include "tcp/gestionnaires/types/TypeCOR.h"

class TypeCORAPI : public TypeCOR
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    TypeCORAPI(TypeCOR* suivant)
        : TypeCOR(suivant)
    {}

    // GETTERS / SETTERS

    CodeTypeRequete getType() const override
    {
        return CodeTypeRequete::API;
    }

    // METHODES

    bool traitementConcret(const RequeteSocket* entree, string* sortie) const override;
};


#endif //SERVEURCPP_TYPECORAPI_H
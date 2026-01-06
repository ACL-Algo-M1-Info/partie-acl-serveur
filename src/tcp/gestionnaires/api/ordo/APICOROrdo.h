//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_APICORORDO_H
#define SERVEURCPP_APICORORDO_H

// INCLUSIONS

#include "tcp/gestionnaires/api/APICOR.h"

class APICOROrdo : public APICOR
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    APICOROrdo(APICOR* suivant)
        : APICOR(suivant)
    {}

    // GETTER / SETTER

    string getAPICommande() const override
    {
        return "ordo";
    }

    int getNombreArguments() const override
    {
        return 2; // [m, [..., pi, ...]]
    }

    // METHODES

    bool traitementConcret(const RequeteAPI* entree, string* sortie) const override;
};


#endif //SERVEURCPP_APICORORDO_H
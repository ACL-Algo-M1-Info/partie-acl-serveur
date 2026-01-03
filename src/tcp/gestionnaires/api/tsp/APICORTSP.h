//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_APICORTSP_H
#define SERVEURCPP_APICORTSP_H

// INCLUSIONS

#include "tcp/gestionnaires/api/APICOR.h"

class APICORTSP : public APICOR
{
public:

    // CONSTRUCTEUR / DESTRUCTEUR

    APICORTSP(APICOR* suivant)
        : APICOR(suivant)
    {}

    // GETTER / SETTER

    string getAPICommande() const override
    {
        return "tsp";
    }

    int getNombreArguments() const override
    {
        return -1;
    }

    // METHODES

    bool traitementConcret(const RequeteAPI* entree, string* sortie) const override;
};


#endif //SERVEURCPP_APICORTSP_H
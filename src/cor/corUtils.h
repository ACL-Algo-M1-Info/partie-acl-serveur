//
// Created by remik on 03/01/2026.
//

#ifndef SERVEURCPP_CORUTILS_H
#define SERVEURCPP_CORUTILS_H

// INCLUSIONS

#include "outils/Singleton/SingletonTemplate.h"

#include "tcp/gestionnaires/api/APICOR.h"
#include "tcp/gestionnaires/api/ordo/APICOROrdo.h"
#include "tcp/gestionnaires/api/tsp/APICORTSP.h"

#include "tcp/gestionnaires/types/TypeCOR.h"
#include "tcp/gestionnaires/types/api/TypeCORAPI.h"
#include "tcp/gestionnaires/types/message/TypeCORMessage.h"

class CORUtils : public SingletonTemplate<CORUtils>
{
    // BINDINGS

    /** Binding singleton. */
    friend class SingletonTemplate<CORUtils>;

public:

    // VARIABLES

    /** COR pour les types réseau. */
    const TypeCOR* typeCorRacine;

    /** COR pour les commandes API. */
    const APICOR* apiCorRacine;

private:

    // CONSTRUCTEUR / DESTRUCTEUR

    /** Constructeur privé. */
    CORUtils()
    {
        typeCorRacine = creerCORTypes();
        apiCorRacine = creerCORAPI();
    }

    ~CORUtils()
    {
        delete typeCorRacine;
        delete apiCorRacine;
    }

    // METHODES

    /**
     * Créé le maillon pour les types.
     * @return La chaîne
     */
    TypeCOR* creerCORTypes() const
    {
        TypeCOR* msg = new TypeCORMessage(nullptr);
        TypeCOR* api = new TypeCORAPI(msg);

        return api;
    }

    /**
     * Créé le maillon pour les commandes API.
     * @return La chaîne
     */
    APICOR* creerCORAPI() const
    {
        APICOR* ordo = new APICOROrdo(nullptr);
        APICOR* tsp = new APICORTSP(ordo);

        return tsp;
    }
};


#endif //SERVEURCPP_CORUTILS_H
//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_VILLESDB_H
#define SERVEURCPP_VILLESDB_H

// INCLUSIONS

#include <vector>
#include <string>

#include "db/db.h"
#include "outils/Singleton/SingletonTemplate.h"
#include "types/chargeursGeneriques/ChargeurGeneriqueJson.h"
#include "types/tsp/coordonnee/Coordonnee.h"

class VillesDb : public Db<string, Coordonnee>, public SingletonTemplate<VillesDb>
{
    // BINDINGS

    /** Binding singleton. */
    friend class SingletonTemplate<VillesDb>;

public:

    // CONSTANTES

    /** Emplacement des fichiers JSON. */
    inline static const string JSON_DIR = "../data/13_fichiers_JSON";

    // METHODES

protected:
    void _recupererDonnees() override;
};

#endif //SERVEURCPP_VILLESDB_H
//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_VILLESDB_H
#define SERVEURCPP_VILLESDB_H

// INCLUSIONS

#include "db/db.h"
#include "types/tsp/coordonnee/Coordonnee.h"

// NAMESPACES



class VillesDb : public Db<string, Coordonnee>
{
public:

    // METHODES
    void recupererDonnees() override
    {
        // TODO faire le chargement des villes depuis le json. Stocker les coordonnées dans la map avec le nom comme clé !
    }
};


#endif //SERVEURCPP_VILLESDB_H
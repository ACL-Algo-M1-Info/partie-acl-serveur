//
// Created by remik on 06/01/2026.
//

// INCLUSIONS

#include "routesDb.h"

void RoutesDb::_recupererDonnees()
{
    // TODO faire le chargement des routes depuis le json. Stocker les routes dans la map avec l'association A_B comme clé !
}

bool RoutesDb::get(const string& villeA, const string& villeB, Route& sortie)
{
    if (Db::get(formatter(villeA, villeB), sortie))
        return true;

    if (Db::get(formatter(villeB, villeA), sortie))
        return true;

    return false;
}
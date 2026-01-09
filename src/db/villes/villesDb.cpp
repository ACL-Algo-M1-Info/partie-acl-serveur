//
// Created by remik on 06/01/2026.
//

// INCLUSIONS

#include "villesDb.h"

void VillesDb::_recupererDonnees()
{
    // Chargement des villes sous forme de coordonnées. Sur toute la france.
    ChargeurGeneriqueJson<Coordonnee> chargeur = ChargeurGeneriqueJson<Coordonnee>();

    vector<Coordonnee> villes;
    chargeur.chargerDossier(JSON_DIR, villes);

    // Mapping sur la map.
    for (const Coordonnee& c : villes)
        _mappeur[c.ville] = c;
}
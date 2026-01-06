//
// Created by remik on 06/01/2026.
//

// INCLUSIONS

#include "villesDb.h"

void VillesDb::recupererDonnees()
{
    // Chargement des villes sous forme de coordonnées. Sur toute la france.
    ChargeurGeneriqueJson<Coordonnee> chargeur = ChargeurGeneriqueJson<Coordonnee>();

    vector<Coordonnee> villes;
    chargeur.chargerDossier(JSON_DIR, villes);

    cout << "Chargé " << villes.size() << " villes" << endl;

    // Mapping sur la map.
    for (const Coordonnee& c : villes)
        mappeur[c.ville] = c;
}
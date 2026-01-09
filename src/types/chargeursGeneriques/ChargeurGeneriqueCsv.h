//
// Created by remik on 09/01/2026.
//

#ifndef SERVEURCPP_CHARGEURGENERIQUECSV_H
#define SERVEURCPP_CHARGEURGENERIQUECSV_H

// INCLUSIONS

#include <sstream>

#include "Chargeur.h"
#include "utils/utils.h"

class ChargeurGeneriqueCsv : public Chargeur<vector<string>>
{
public:

    // VARIABLES

    /** Séparateur. */
    char separateur;

    // CONSTRUCTEUR / DESTRUCTEUR

    ChargeurGeneriqueCsv(char separateur)
        : separateur(separateur)
    {}

    // METHODES

    void chargerFichier(ifstream& fichier, vector<vector<string>>& resultat) const
    {
        string ligne;

        while (getline(fichier, ligne))
        {
            resultat.emplace_back();
            vector<string>& cellules = resultat.back();

            stringstream ss(ligne);
            string cellule;

            // Récupère chaque cellule.
            while (getline(ss, cellule, separateur))
            {
                Utils::trim(cellule);
                cellules.push_back(cellule);
            }
        }
    }
};


#endif //SERVEURCPP_CHARGEURGENERIQUECSV_H
//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURCOORDONNETEXTE_H
#define SERVEURCPP_CHARGEURCOORDONNETEXTE_H
#include "ChargeurTexteTemplate.h"
#include "types/tsp/coordonnee/Coordonnee.h"

class ChargeurCoordonneeTexte : public ChargeurTexteTemplate<double, Coordonnee>
{
   protected:
    Coordonnee creerElement(const string& ligne) override
    {
        // Supposons format : NomVille; latitude; longitude
        stringstream ss(ligne);
        string champ;
        getline(ss, champ, ';');
        string nomVille = champ;
        getline(ss, champ, ';');
        double latitude = stod(champ);
        getline(ss, champ, ';');
        double longitude = stod(champ);

        return Coordonnee(nomVille, latitude, longitude);
    }
};

#endif  // SERVEURCPP_CHARGEURCOORDONNETEXTE_H

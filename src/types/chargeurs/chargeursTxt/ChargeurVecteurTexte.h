//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURVECTEURTEXTE_H
#define SERVEURCPP_CHARGEURVECTEURTEXTE_H
#include "ChargeurTexteTemplate.h"
#include "types/vecteur/Vecteur2D.h"

class ChargeurVecteurTexte : public ChargeurTexteTemplate<double, Vecteur2D>
{
   protected:
    Vecteur2D creerElement(const string& ligne) override
    {
        // Supposons format : NomVille; latitude; longitude
        stringstream ss(ligne);
        string champ;
        getline(ss, champ, ';');  // Pour ignorer la ville
        getline(ss, champ, ';');
        double x = stod(champ);
        getline(ss, champ, ';');
        double y = stod(champ);
        return Vecteur2D(x, y);
    }
};

#endif  // SERVEURCPP_CHARGEURVECTEURTEXTE_H

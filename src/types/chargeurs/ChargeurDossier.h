//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURDOSSIER_H
#define SERVEURCPP_CHARGEURDOSSIER_H
#include <filesystem>

#include "Chargeur.h"

template <class S, class T>
class ChargeurDossier : public Chargeur<S, T>
{
   private:
    Chargeur<S, T>* chargeur;

   public:
    ChargeurDossier(Chargeur<S, T>* chargeur) : chargeur(chargeur) {}

    void charger(const string& chemin, Graphe<S, T>& graphe) override
    {
        for (filesystem::directory_iterator it(chemin); it != filesystem::directory_iterator(); ++it)
        {
            chargeur->charger(it->path().string(), graphe);
        }
    }
};

#endif  // SERVEURCPP_CHARGEURDOSSIER_H

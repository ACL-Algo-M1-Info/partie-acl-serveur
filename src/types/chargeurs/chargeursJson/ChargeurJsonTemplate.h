//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURJSONTEMPLATE_H
#define SERVEURCPP_CHARGEURJSONTEMPLATE_H
#include <fstream>

#include "../../graphe/Graphe.h"
#include "types/chargeurs/Chargeur.h"
#include "utils/json.h"
using json = nlohmann::json;

template <class S, class T>
class ChargeurJsonTemplate:public Chargeur<S,T>
{
   public:
    void charger(const string& nomFichier, Graphe<S, T>& graphe) override
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            cerr << "Erreur ouverture fichier " << nomFichier << endl;
            return;
        }
        json donnees;
        fichier >> donnees;

        for (int i = 0; i < donnees.size(); i++)
        {
            T valeurSommet = creerElement(donnees[i]);
            graphe.creeSommet(valeurSommet);
        }
    }

   protected:
    virtual T creerElement(const json& ligne) = 0;
};

#endif  // SERVEURCPP_CHARGEURJSONTEMPLATE_H

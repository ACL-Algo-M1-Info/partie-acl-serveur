//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_CHARGEURTEXTETEMPLATE_H
#define SERVEURCPP_CHARGEURTEXTETEMPLATE_H
#include <fstream>

#include "../../graphe/Graphe.h"
#include "types/chargeurs/Chargeur.h"
template <class S, class T>
class ChargeurTexteTemplate:public Chargeur<S,T>
{
   public:
    void charger(const string &nomFichier,  Graphe<S, T> &graphe) override
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            cerr << "Erreur ouverture fichier " << nomFichier << endl;
            return;
        }
        string ligne;
        while (getline(fichier, ligne))
        {
            T valeurSommet = creerElement(ligne);
            graphe.creeSommet(valeurSommet);
        }
    }

   protected:
    virtual T creerElement(const string &ligne) = 0;
};

#endif  // SERVEURCPP_CHARGEURTEXTETEMPLATE_H

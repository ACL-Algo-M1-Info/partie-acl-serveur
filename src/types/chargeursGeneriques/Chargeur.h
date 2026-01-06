//
// Created by MEGACHEESEKEBAB on 06/01/2026.
//

#ifndef SERVEURCPP_CHARGEUR_H
#define SERVEURCPP_CHARGEUR_H
#include <fstream>
#include <iostream>
#include <string>


using namespace std;
template <class T>
class Chargeur
{
   public:
    virtual ~Chargeur() = default;
    T charger(const string& chemin) const
    {
        ifstream fichier(chemin);
        if (!fichier.is_open())
        {
            cerr << "Fichier pas ouvert" << endl;
            exit(1);
        }
        return chargerFichier(fichier);
    }

    virtual T chargerFichier(ifstream& fichier) const = 0;
};

#endif  // SERVEURCPP_CHARGEUR_H

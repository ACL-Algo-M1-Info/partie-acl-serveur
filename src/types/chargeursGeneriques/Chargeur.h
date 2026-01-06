//
// Created by MEGACHEESEKEBAB on 06/01/2026.
//

#ifndef SERVEURCPP_CHARGEUR_H
#define SERVEURCPP_CHARGEUR_H
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
template <class T>
class Chargeur
{
   public:
    virtual ~Chargeur() = default;
    void charger(const string& chemin, vector<T>& resultat) const
    {
        ifstream fichier(chemin);
        if (!fichier.is_open())
        {
            cerr << "Fichier pas ouvert" << endl;
            exit(1);
        }
        chargerFichier(fichier, resultat);
    }

    void chargerDossier(const string& chemin, vector<T>& resultat) const
    {

        for (filesystem::directory_iterator it(chemin); it != filesystem::directory_iterator(); ++it)
        {
            cout << "on va charger " << it->path().string() << endl;
            vector<T> add;
            charger(it->path().string(), add);
            resultat.insert(resultat.end(),add.begin(),add.end());
        }
    }
    virtual void chargerFichier(ifstream& fichier, vector<T>& resultat) const = 0;
};

#endif  // SERVEURCPP_CHARGEUR_H

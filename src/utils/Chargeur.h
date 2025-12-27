//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

#ifndef SERVEURCPP_CHARGEUR_H
#define SERVEURCPP_CHARGEUR_H
#include <fstream>
#include <iostream>
#include <string>

#include "graphe/Graphe.h"
#include "json.h"
#include "types/coordonnee/Coordonnee.h"
using json = nlohmann::json;

using namespace std;
class Chargeur
{
   public:
    /**
     * Etant donné un nom de fichier au format Json et un graphe d'arête qui contient une info de type double
     * et de sommet qui contient une coordonnée au format : <NomVille, <latitude, longitude>>
     * Charge dans graphe chacunes des villes du fichier en tant que Coordonnée puis le place dans un sommet
     * Ne se charge pas de créer les arêtes.
     * TODO trouver comment rendre les chargeurs plus généraux.
     * @param nomFichier
     * @param graphe
     */
    static void chargerGrapheJson(const string& nomFichier, Graphe<double, Coordonnee<string, double>>& graphe)
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            cerr << "Erreur fichier pas ouvert" << endl;
            exit(1);
        }

        json donnees;
        fichier >> donnees;
        cout << "Il y a en tout " << donnees.size() << " donnees dans le fichier " << nomFichier << endl;

        for (int i = 0; i < donnees.size(); i++)
        {
            string ville = donnees[i]["ville"];
            double latitude = donnees[i]["latitude"];
            double longitude = donnees[i]["longitude"];
            // cout << "ville = " << ville << ", longitude = " << longitude << ", latitude = " << latitude << endl;
            Coordonnee<string, double> coordonnee(ville, latitude, longitude);
            Sommet<Coordonnee<string, double>>* sommet = graphe.creeSommet(coordonnee);
        }

    }

    static Graphe<double, Coordonnee<string, double>> chargerDossierJson(const string& nomDossier)
    {
        Graphe<double, Coordonnee<string, double>> graphe;
        cout << "Les villes du dossier " << nomDossier << " vont etre chargees dans un graphe" << endl;
        for (filesystem::directory_iterator it(nomDossier); it != filesystem::directory_iterator(); ++it)
        {
            // cout << "Les villes du fichier suivant vont etre chargees : " << endl << *it << endl;
            chargerGrapheJson(it->path().string(), graphe);
        }
        return graphe;
    }

    static Graphe<double, Coordonnee<string, double>> chargerFichierJson(const string& nomFichier)
    {
        cout << "Les villes du fichier " << nomFichier << " vont etre chargees dans un graphe" << endl;
        Graphe<double, Coordonnee<string, double>> graphe;
        chargerGrapheJson(nomFichier, graphe);
        return graphe;
    }
};

#endif  // SERVEURCPP_CHARGEUR_H

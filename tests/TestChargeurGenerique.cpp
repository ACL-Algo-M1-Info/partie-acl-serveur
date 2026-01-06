//
// Created by MEGACHEESEKEBAB on 06/01/2026.
//

#include "types/chargeursGeneriques/ChargeurGeneriqueJson.h"
#include "types/coordonnee/Coordonnee.h"
#include "types/graphe/Graphe.h"
#include "utils/utils.h"
int main()
{
    ChargeurGeneriqueJson<Coordonnee> chargeur_generique_json;
    vector<Coordonnee> mesCoordonnees;
    chargeur_generique_json.charger("../data/fichiersJson/Meurthe-Et-Moselle.json", mesCoordonnees);

    for (int i = 0; i < mesCoordonnees.size(); i++)
    {
        cout << mesCoordonnees[i] << endl;
    }

    Graphe<double, Coordonnee> graphe;
    graphe.remplirGraphe(mesCoordonnees);
    cout << graphe << endl;
    DistanceEuclidienneCoordonnee distance_euclidienne_coordonnee;

    Graphe<double, Coordonnee> france;
    vector<Coordonnee> res;
    chargeur_generique_json.chargerDossier("../data/13_fichiers_JSON", res);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
    france.remplirGraphe(res);
    cout << "nb sommet " << PElement<Sommet<Coordonnee>>::taille(france.lSommets);
    DistanceGeodesiqueCoordonnee distance_geodesique_coordonnee;
    cout << "taille res = " << res.size() << endl;
    Graphe<double, Coordonnee>* tournee = Utils::resoudreTSPComplet(france, distance_geodesique_coordonnee);
    double total = tournee->sommePoids();
    cout << " somme total = " << total << endl;
    cout << *tournee << endl;

    PElement<Arete<double, Coordonnee>>* listeArete = tournee->lAretes;
    while (listeArete != nullptr)
    {
        Arete<double, Coordonnee>* arete = listeArete->v;
        double valeurArete = arete->v;
        Sommet<Coordonnee>* debut = arete->debut;
        Sommet<Coordonnee>* fin = arete->fin;
        Coordonnee c = debut->v;
        string nomVille = c.ville;
        listeArete = listeArete->s;
    }
    return 0;
}
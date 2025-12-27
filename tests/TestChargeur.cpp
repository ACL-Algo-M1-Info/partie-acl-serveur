#include "utils/Chargeur.h"
//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

void testChargerDossierJson()
{
    Graphe<double, Coordonnee<string, double>> graphe = Chargeur::chargerDossierJson("../src/data/13_fichiers_JSON");
    cout << graphe << endl;
}

void testChargerFichierJson()
{
    Graphe<double, Coordonnee<string, double>> graphe = Chargeur::chargerFichierJson("../src/data/fichiersJson/Meurthe-Et-Moselle.json");
    cout << graphe << endl;
    DistanceEuclidienneCoordonnee distance_euclidienne;
    graphe.rendreComplet(distance_euclidienne);
    cout << "Graphe apres avoir ete rendu complet : " << endl << graphe;
}
int main()
{
    testChargerDossierJson();
    testChargerFichierJson();
    return 0;
}
#include "utils/Chargeur.h"
//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

void testChargerDossierJson()
{
    Graphe<double, Coordonnee<string, double>> graphe = Chargeur::chargerJsonDossier("../src/data/13_fichiers_JSON");
    cout << graphe << endl;
}

int main()
{
    testChargerDossierJson();
    return 0;
}
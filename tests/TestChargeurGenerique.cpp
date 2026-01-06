//
// Created by MEGACHEESEKEBAB on 06/01/2026.
//

#include "types/chargeursGeneriques/ChargeurGeneriqueJson.h"
#include "types/coordonnee/Coordonnee.h"
#include "types/graphe/Graphe.h"
int main()
{
    ChargeurGeneriqueJson<vector<Coordonnee>> chargeur_generique_json;
    vector<Coordonnee> mesCoordonnees = chargeur_generique_json.charger("../data/fichiersJson/Meurthe-Et-Moselle.json");
    for (int i = 0; i < mesCoordonnees.size(); i++)
    {
        cout << mesCoordonnees[i] << endl;
    }
    Graphe<double, Coordonnee> graphe;
    graphe.remplirGraphe(mesCoordonnees);
    cout << graphe << endl;
    return 0;
}
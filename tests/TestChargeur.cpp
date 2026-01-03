#include "utils/Chargeur.h"
#include "utils/utils.h"
//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

int main()
{
    {
        cout << "**************************** Test charger dossier Json *******************************" << endl;
        Graphe<double, Coordonnee> graphe = Chargeur::chargerDossierJson("../data/13_fichiers_JSON");
        cout << graphe << endl;
    }
    {
        cout << "**************************** Test charger fichier json *******************************" << endl;
        Graphe<double, Coordonnee> graphe = Chargeur::chargerFichierJson("../data/fichiersJson/Meurthe-Et-Moselle.json");
        cout << graphe << endl;
        DistanceEuclidienneCoordonnee distance_euclidienne;
        graphe.rendreComplet(distance_euclidienne);
        cout << "Graphe apres avoir ete rendu complet : " << endl << graphe;
    }
    {
        cout << "**************************** Test charger fichier grand est json + distance geodesique *******************************" << endl;
        Graphe<double, Coordonnee> graphe = Chargeur::chargerFichierJson("../data/13_fichiers_JSON/GrandEst.json");
        cout << graphe << endl;
        DistanceGeodesiqueCoordonnee distance_geodesique_coordonnee;
        Graphe<double, Coordonnee>* trajet = Utils::resoudreTSPComplet(graphe, distance_geodesique_coordonnee);
        cout << *trajet << endl;
        double total = trajet->sommePoids();
        cout << "longueur chemin trouve = " << total << endl;
    }
    return 0;
}
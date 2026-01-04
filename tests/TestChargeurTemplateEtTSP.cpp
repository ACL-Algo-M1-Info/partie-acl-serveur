#include "types/chargeurs/ChargeurDossier.h"
#include "types/chargeurs/chargeursJson/ChargeurCoordonneeJson.h"
#include "types/chargeurs/chargeursJson/ChargeurVecteurJson.h"
#include "utils/utils.h"
//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//
void afficheSucces(const string &nom) { cout << "Les test de " << nom << " se sont bien deroules !" << endl; }
int main()
{
    {
        cout << "*********************************** TEST CHARGEMENT JSON COORDONNEE et TSP **************************************" << endl;
        ChargeurCoordonneeJson chargeur_coordonnee_json;
        Graphe<double, Coordonnee> graphe;
        chargeur_coordonnee_json.charger("../data/13_fichiers_JSON/GrandEst.json", graphe);
        // cout << graphe << endl;
        DistanceGeodesiqueCoordonnee distance_geodesique_coordonnee;
        graphe.rendreComplet(distance_geodesique_coordonnee);
        // cout << graphe << endl;
        // Graphe<double,Coordonnee> * acpm = graphe.kruskal();
        // PElement<Sommet<Coordonnee>> * tournee = acpm->TSP();
        // Graphe<double,Coordonnee>*tourneeUltime =graphe.construireGrapheTournee(tournee);
        // cout << tourneeUltime->sommePoids() << endl;

        Graphe<double, Coordonnee> *tournee = Utils::resoudreTSPComplet(graphe, distance_geodesique_coordonnee);
        double total = tournee->sommePoids();
        assert(1364.80 <= total && total <= 1364.82);
        afficheSucces("TEST CHARGEMENT JSON COORDONNEE et TSP");
    }
    {
        cout << "*********************************** TEST CHARGEMENT JSON VECTEUR2D et TSP **************************************" << endl;
        ChargeurVecteurJson chargeur_vecteur_json;
        Graphe<double, Vecteur2D> graphe;
        chargeur_vecteur_json.charger("../data/13_fichiers_JSON/GrandEst.json", graphe);
        DistanceEuclidienneVecteur2D distance_euclidienne_vecteur_2d;
        Graphe<double, Vecteur2D> *tournee = Utils::resoudreTSPComplet(graphe, distance_euclidienne_vecteur_2d);
        // cout << *tournee << endl;
        double total = tournee->sommePoids();
        // cout << total;
        assert(14.6 <= total && total <= 14.7);
        afficheSucces("TEST CHARGEMENT JSON VECTEUR2D et TSP");
    }
    {
        cout << "*********************************** TEST CHARGEMENT DOSSIER JSON COORDONNEE et TSP EN FAIT TOUTE LA FRANCE "
                "!!**************************************"
             << endl;
        ChargeurCoordonneeJson chargeur_coordonnee_json;
        ChargeurDossier<double, Coordonnee> chargeur_dossier(&chargeur_coordonnee_json);
        Graphe<double, Coordonnee> graphe;
        chargeur_dossier.charger("../data/13_fichiers_JSON", graphe);
        DistanceGeodesiqueCoordonnee distance_geodesique_coordonnee;
        Graphe<double, Coordonnee> *tournee = Utils::resoudreTSPComplet(graphe, distance_geodesique_coordonnee);
        // cout << *tournee << endl;
        double total = tournee->sommePoids();
        cout << "total = " << total << endl;
        afficheSucces("TEST CHARGEMENT DOSSIER JSON COORDONNEE et TSP");
    }
}
//
// Created by MEGACHEESEKEBAB on 11/01/2026.
//
#include <assert.h>

#include "../src/types/graphe/Graphe.h"
#include "types/tsp/coordonnee/Coordonnee.h"
#include "utils/utils.h"
int main()
{
    cout << "************************** test TSP ***************************" << endl;
    /* Instance page wikipedia cycle = ACBDA poids = 7*/
    Graphe<int, Coordonnee> graphe;
    Sommet<Coordonnee>* sA = graphe.creeSommet(Coordonnee("Metz", 0, 10));
    DistanceGeodesiqueCoordonnee distance_geodesique_coordonnee;
    Graphe<int, Coordonnee>* tournee = Utils::resoudreTSPComplet(graphe, distance_geodesique_coordonnee);
    cout << *tournee << endl;
}
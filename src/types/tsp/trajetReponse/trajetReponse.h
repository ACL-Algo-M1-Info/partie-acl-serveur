//
// Created by remik on 07/01/2026.
//

#ifndef SERVEURCPP_TRAJETREPONSE_H
#define SERVEURCPP_TRAJETREPONSE_H

// INCLUSIONS

#include <vector>

#include "types/tsp/coordonnee/Coordonnee.h"
#include "types/tsp/route/route.h"
#include "utils/json.h"

// NAMESPACES

using namespace std;

/**
 * Objet de réponses de trajet utilisé pour faire des envois réseau.
 */
class TrajetReponse
{
public:

    // VARIABLES

    /** Distance totale. */
    double distanceTotale;

    /** Vecteur des objets ville. */
    vector<Coordonnee> villes;

    /** Vectuer des objets route. */
    vector<Route> routes;

    // CONSTRUCTEUR / DESTRUCTEUR

    TrajetReponse() = default;

    TrajetReponse(double distanceTotale, const vector<Coordonnee>& villes, const vector<Route>& routes)
        : distanceTotale(distanceTotale), villes(villes), routes(routes)
    {}

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(TrajetReponse, distanceTotale, villes, routes)
};


#endif //SERVEURCPP_TRAJETREPONSE_H
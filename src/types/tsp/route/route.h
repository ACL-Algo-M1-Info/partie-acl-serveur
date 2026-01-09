//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_ROUTE_H
#define SERVEURCPP_ROUTE_H

// INCLUSIONS

#include "types/tsp/typeRoute.h"
#include "types/tsp/coordonnee/Coordonnee.h"
#include "utils/json.h"

class Route
{
public:
    // VARIABLES

    /** Distance de la route. */
    double distance;

    /** Type de route. */
    TypeRoute type;

    /** Ville A liée. */
    string villeA;

    /** Ville B liée. */
    string villeB;

    // CONSTRUCTEUR / DESTRUCTEUR

    /** Pour la librairie JSON. */
    Route() = default;

    /** Constructeur avec données. */
    Route(double distance, TypeRoute type, const string& villeA, const string& villeB)
        : distance(distance), type(type), villeA(villeA), villeB(villeB)
    {}

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Route, distance, type, villeA, villeB)
};


#endif //SERVEURCPP_ROUTE_H
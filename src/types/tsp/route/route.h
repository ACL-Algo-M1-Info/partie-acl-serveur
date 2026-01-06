//
// Created by remik on 06/01/2026.
//

#ifndef SERVEURCPP_ROUTE_H
#define SERVEURCPP_ROUTE_H

// INCLUSIONS

#include "types/tsp/typeRoute.h"
#include "utils/json.h"

class Route
{
public:
    // VARIABLES

    /** Distance de la route. */
    double distance;

    /** Type de route. */
    TypeRoute type;

    // CONSTRUCTEUR / DESTRUCTEUR

    /** Pour la librairie JSON. */
    Route() = default;

    /** Constructeur avec données. */
    Route(double distance, TypeRoute type)
        : distance(distance), type(type)
    {}

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Route, distance, type)
};


#endif //SERVEURCPP_ROUTE_H
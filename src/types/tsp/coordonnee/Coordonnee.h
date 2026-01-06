//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

#ifndef SERVEURCPP_COORDONNEE_H
#define SERVEURCPP_COORDONNEE_H

// INCLUSIONS

#include <iostream>
#include <sstream>
#include <string>

#include "utils/json.h"

// NAMESPACES

using namespace std;

class Coordonnee
{
   public:
    string ville;
    double latitude, longitude;

    Coordonnee() = default;
    Coordonnee(const string& ville, const double& latitude, const double& longitude) : ville(ville), latitude(latitude), longitude(longitude) {}

    operator string() const
    {
        ostringstream o;
        o << "Coordonnee [ ville = " << ville << ", latitude = " << latitude << ", longitude = " << longitude << " ]";
        return o.str();
    }

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Coordonnee, ville, latitude, longitude)
};

ostream& operator<<(ostream& o, const Coordonnee& coordonnee)
{
    return o << (string)coordonnee;
}

#endif  // SERVEURCPP_COORDONNEE_H

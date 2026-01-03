//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

#ifndef SERVEURCPP_COORDONNEE_H
#define SERVEURCPP_COORDONNEE_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Coordonnee
{
   public:
    string ville;
    double latitude, longitude;

    Coordonnee(const string& ville, const double& latitude, const double& longitude) : ville(ville), latitude(latitude), longitude(longitude) {}

    operator string() const
    {
        ostringstream o;
        o << "Coordonnee [ ville = " << ville << ", latitude = " << latitude << ", longitude = " << longitude << " ]";
        return o.str();
    }

};

ostream& operator<<(ostream& o, const Coordonnee& coordonnee)
{
    return o << (string)coordonnee;
}

#endif  // SERVEURCPP_COORDONNEE_H

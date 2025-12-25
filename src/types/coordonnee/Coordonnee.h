//
// Created by MEGACHEESEKEBAB on 24/12/2025.
//

#ifndef SERVEURCPP_COORDONNEE_H
#define SERVEURCPP_COORDONNEE_H
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

template <class X, class Y>
class Coordonnee
{
   public:
    X ville;
    Y latitude, longitude;

    Coordonnee(const X& ville, const Y& latitude, const Y& longitude) : ville(ville), latitude(latitude), longitude(longitude) {}

    /**
     * Sous hypothèse que la classe X et Y ont redéfinis l'opérateur<< :-)
     */
    operator string() const
    {
        ostringstream o;
        o << "Coordonnee [ ville = " << ville << ", latitude = " << latitude << ", longitude = " << longitude  << " ]";
        return o.str();
    }
};

template <class X, class Y>
ostream& operator<<(ostream& o, const Coordonnee<X, Y> coordonnee)
{
    return o << (string)coordonnee;
}

#endif  // SERVEURCPP_COORDONNEE_H

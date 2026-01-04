//
// Created by MEGACHEESEKEBAB on 04/01/2026.
//

#ifndef SERVEURCPP_VECTEUR2D_H
#define SERVEURCPP_VECTEUR2D_H
#include <sstream>
#include <string>
using namespace std;
class Vecteur2D
{
   public:
    double x;
    double y;

    Vecteur2D(const double& x, const double& y) : x(x), y(y) {}

    operator string() const
    {
        ostringstream o;
        o << "Vecteur [ x = " << x << ", y = " << y << " ]";
        return o.str();
    }

    friend ostream& operator<<(ostream& o, const Vecteur2D& v) { return o << (string)v; }
};

#endif  // SERVEURCPP_VECTEUR2D_H

//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_FORMEUTILS_H
#define SERVEURCPP_FORMEUTILS_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/**
 * ******************************************************************
 * ******************************************************************
 * POUR TESTER COPIE3
 */
class Forme
{
protected:
    string couleur;

public:
    Forme(const string& couleur) : couleur(couleur) {}
    virtual ~Forme() {}
    virtual Forme* copie() const = 0;
    virtual operator string() const = 0;
    virtual bool operator<=(const Forme& f) const = 0;

    friend ostream& operator<<(ostream& o, const Forme& f)
    {
        return o << (string)f;
    }

    const string& getCouleur() const { return couleur; }
};

class Cercle : public Forme
{
public:
    double rayon;
    Cercle(const string& s, const double& r) : Forme(s), rayon(r) {}
    bool operator<=(const Forme& f) const override
    {
        return couleur <= f.getCouleur();
    }
    Forme* copie() const override { return new Cercle(couleur, rayon); }
    operator string() const
    {
        ostringstream o;
        o << "Cercle ( " << couleur << " : rayon = " << rayon << " ) ";
        return o.str();
    }
};

class Segment : public Forme
{
public:
    double a, b;
    Segment(const string& s, const double& a, const double& b)
        : Forme(s), a(a), b(b)
    {
    }
    bool operator<=(const Forme& f) const override
    {
        return couleur <= f.getCouleur();
    }
    Forme* copie() const override { return new Segment(couleur, a, b); }

    operator string() const
    {
        ostringstream o;
        o << "Segment ( " << couleur << " : a = " << a << ", b = " << b
          << " ) ";
        return o.str();
    }
};
/**
 * ******************************************************************
 * ******************************************************************
 *
 */

#endif  // SERVEURCPP_FORMEUTILS_H

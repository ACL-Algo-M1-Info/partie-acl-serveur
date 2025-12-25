//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_FONCTEURUTILS_H
#define SERVEURCPP_FONCTEURUTILS_H
#include <cmath>

#include "../Formes/FormeUtils.h"
#include "graphe/Arete.h"
#include "graphe/Sommet.h"
class CritereCouleur
{
   public:
    string couleurRecherchee;
    CritereCouleur(const string& couleurRecherchee) : couleurRecherchee(couleurRecherchee) {}

    bool operator()(const Forme* f) const { return couleurRecherchee == f->getCouleur(); }
};

template <class S, class T>
class CritereLiaison
{
    const Sommet<T>* s1;
    const Sommet<T>* s2;

   public:
    CritereLiaison(const Sommet<T>* s1, const Sommet<T>* s2) : s1(s1), s2(s2) {}

    bool operator()(const Arete<S, T>* a) const { return a->estEgal(s1, s2); }
};

template <class T>
class CritereSommetAvecPaire
{
    const Sommet<T>* ancienSommetCherche;

   public:
    CritereSommetAvecPaire(const Sommet<T>* ancienSommetCherche) : ancienSommetCherche(ancienSommetCherche) {}

    bool operator()(pair<Sommet<T>*, Sommet<T>*>* paire) const { return paire->first == ancienSommetCherche; }
};

class DistanceEuclidienne
{
   public:
    template <class T>
    double operator()(const T& a, const T& b) const
    {
        double s = a.latitude - b.latitude;
        double r = a.longitude - b.longitude;
        return sqrt(s * s + r * r);
    }
};

#endif  // SERVEURCPP_FONCTEURUTILS_H

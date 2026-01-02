//
// Created by MEGACHEESEKEBAB on 23/12/2025.
//

#ifndef SERVEURCPP_FONCTEURUTILS_H
#define SERVEURCPP_FONCTEURUTILS_H
#include <cmath>

#include "../Formes/FormeUtils.h"
#include "../types/graphe/Arete.h"
#include "../types/graphe/Sommet.h"
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

/**
 * Foncteur pour calculer la distance euclidienne entre deux coordonnées
 * (fausse pour calculer des coordonnées GPS)
 */
class DistanceEuclidienneCoordonnee
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

/**
 * Foncteur pour comparer si un entier est inférieur à un autre
 */
class EntierInferieur
{
public:
    double operator()(const int& i, const int& j) const
    {
        if (i < j)
            return true;
        return false;
    }
};

/**
 * Foncteur pour comparer si un entier est supérieur à un autre
 */
class EntierSuperieur
{
public:
    double operator()(const int& i, const int& j) const
    {
        if (i > j)
            return true;
        return false;
    }
};


#endif  // SERVEURCPP_FONCTEURUTILS_H

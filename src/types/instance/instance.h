//
// Created by maxen on 22/12/2025.
//

#pragma once


// INCLUSIONS

#include <string>

// USINGS

using namespace std;

// CLASSES

class Instance
{
public:

    // VARIABLES

    /** Nombre de tâches */
    int n;

    /** Nombre de machines */
    int m;

    /** Tableau de quantités des tâches */
    int* p;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Créer une nouvelle instance
     *
     * @param n le nombre de tâches
     * @param m le nombre de mâchines
     * @param p la durée opératoire des tâches
     */
    Instance(const int& n, const  int& m, int* p);

    /**
     * Supprime une instance.
     */
    ~Instance() {}

    /**
     * Clone une instance
     *
     * @param source  l'instance à cloner
     */
    Instance(const Instance& source);

    // FONCTIONS

    int obtenirPmax() const;

    // SURCHARGES

    explicit operator string() const;

    bool operator==(const Instance& instance) const;

};

inline ostream& operator<<(ostream& os, const Instance& instance)
{
    return (os << (string)instance);
}

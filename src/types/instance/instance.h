//
// Created by maxen on 22/12/2025.
//

#pragma once

#include <string>

#include "types/camion/camion.h"

// INCLUSIONS

#include <sstream>

// USINGS

using namespace std;

// CLASSES

class Instance
{
public:

    // VARIABLES

    int n;

    int m;

    int* quantites;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Créer une nouvelle instance
     *
     * @param n le nombre de tâches
     * @param m le nombre de mâchines
     * @param quantites la durée opératoire des tâches
     */
    Instance(const int& n, const  int& m, int* quantites): n(n), m(m), quantites(quantites) {}

    /**
     * Supprime une instance.
     */
    ~Instance();

    /**
     * Clone une instance
     *
     * @param source  l'instance à cloner
     */
    Instance(const Instance& source);

    // FONCTIONS


    // SURCHARGES

    explicit operator string() const;

    bool operator==(const Instance& i) const;

};

inline ostream& operator<<(ostream& os, const Instance& instance)
{
    return (os << (string)instance);
}

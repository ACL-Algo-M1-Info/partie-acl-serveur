//
// Created by maxen on 22/12/2025.
//

#pragma once

// INCLUSIONS

#include <string>
#include <vector>

#include "types/instance/instance.h"

// USINGS

using namespace std;

// CLASSES

class Instance;

class Camion
{
public:

    // VARIABLES

    /** Tableau ordonné des IDs des tâches placées sur cette machine */
    vector<int> tabId;

    /** Cmax local sur la machine */
    int cmax;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Créé un nouveau camion vide
     */
    Camion(): cmax(0) {}

    /**
     * Supprime un camion
     */
    ~Camion() {}

    /**
     * Clone un camion depuis une source
     *
     * @param source le camion duquel puiser les informations
     */
    Camion(const Camion& source): tabId(source.tabId), cmax(source.cmax) {}

    // FONCTIONS

    /**
     * Ajoute une tâche à l'ordonnancement en fin de position.
     * @param i Indice de la tâche à ajouter
     * @param quantite Durée opératoire de la tâche à ajouter
     */
    void ajouterTache(const int& i, const int& quantite);

    /**
     * Ajoute une tâche à l'ordonnancement en fin de position.
     * @param i Tâche à rajouter dans le camion
     * @param instance Instance depuis laquelle piocher les informations
     */
    void ajouterTacheParInstance(const int& i, const Instance& instance);

    // SURCHARGES

    explicit operator string() const;

    bool operator==(const Camion& c) const;
};

inline ostream& operator<<(ostream& os, const Camion& camion)
{
    return(os << (string)camion);
}

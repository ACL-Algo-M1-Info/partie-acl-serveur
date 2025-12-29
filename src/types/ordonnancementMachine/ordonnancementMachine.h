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

class OrdonnancementMachine
{
public:

    // VARIABLES

    /** Tableau ordonné des IDs des tâches placées sur cette machine */
    vector<int> tabId;

    /** Cmax local sur la machine */
    int cmax;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
     * Créé un nouveau ordonnancementMachine vide
     */
    OrdonnancementMachine(): cmax(0) {}

    /**
     * Supprime un ordonnancement
     */
    ~OrdonnancementMachine() {}

    /**
     * Clone un ordonnancementMachine depuis une source
     *
     * @param source le camion duquel puiser les informations
     */
    OrdonnancementMachine(const OrdonnancementMachine& source): tabId(source.tabId), cmax(source.cmax) {}

    // FONCTIONS

    /**
     * Ajoute une tâche à l'ordonnancement en fin de position.
     * @param i Indice de la tâche à ajouter
     * @param pi Durée opératoire de la tâche à ajouter
     */
    void ajouterTache(const int& i, const int& pi);

    /**
     * Ajoute une tâche à l'ordonnancement en fin de position.
     * @param i Tâche à rajouter dans le camion
     * @param instance Instance depuis laquelle piocher les informations
     */
    void ajouterTacheParInstance(const int& i, const Instance& instance);

    // SURCHARGES

    explicit operator string() const;

    bool operator==(const OrdonnancementMachine& c) const;
};

inline ostream& operator<<(ostream& os, const OrdonnancementMachine& camion)
{
    return(os << (string)camion);
}

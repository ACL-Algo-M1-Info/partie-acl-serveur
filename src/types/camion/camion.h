//
// Created by maxen on 22/12/2025.
//

#pragma once

// INCLUSIONS

#include <vector>
#include <string>

// USINGS

using namespace std;

// CLASSES

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
    ~Camion();

    /**
     * Clone un camion depuis une source
     *
     * @param source le camion duquel puiser les informations
     */
    Camion(const Camion& source);

    void ajouterTache(const int& i, const int& quantite);

    explicit operator string() const;
};

inline ostream& operator<<(ostream& os, const Camion& camion)
{
    return(os << (string)camion);
}

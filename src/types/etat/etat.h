//
// Created by maxen on 21/12/2025.
//

#pragma once

// INCLUSIONS

#include <iosfwd>
#include <ostream>

#include "../instance/instance.h"

// USINGS

using namespace std;


// CLASSES

class Etat
{
public:

    // VARIABLES

    /** Nombre de machines */
    int m;
    /** Durée opératoire + durée de latence max de l'état */
    int lmax;
    /** Tableau de camions */
    //TODO

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
    * Créer un nouvel état avec m machines
    *
    * @param m le nombre de machines
    * @return un nouvel état
    */
    Etat(const int& m): m(m), lmax(0) {}

    /**
    * Supprime un état.
    *
    */
    ~Etat();

    /**
     * Créer un nouvel état selon un état existant
     *
     * @param source  l'état depuis lequel on clone
     * @return un nouvel état
     */
    Etat(const Etat& source);

    /**
     * Ajoute une tâche sur une machine.
     *
     * @param k la machine sur laquelle on ajoute la tâche
     * @param i l'id de la tâche que l'on ajoute
     * @param pi la durée opératoire de la tâche i
     * @param qi la durée de latence de la tâche i
     */
    void ajouterTacheSurMachine(const int& k, const int& i, const int& pi, const int& qi);

    /**
     * Ajoute une tâche sur une machine depuis une instance.
     *
     * @param k la machine sur laquelle on ajoute la tâche
     * @param i l'id de la tâche que l'on ajoute
     * @param instance l'instance qui possède la tâche i
     */
    void ajouterTacheSurMachineParInstance(const Instance& i, const int& k, const int& i);

    explicit operator string() const;

    bool operator==(const Etat& source) const;
};

inline ostream& operator<<(ostream & os, const Etat& etat)
{
    return(os << (string)etat);
}


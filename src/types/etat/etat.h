//
// Created by maxen on 21/12/2025.
//

#pragma once

// INCLUSIONS

#include <iosfwd>
#include <vector>

#include "../instance/instance.h"
#include "../ordonnancementMachine/ordonnancementMachine.h"

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
    int cmax;
    /** Tableau d'ordonnancements machine */
    vector<OrdonnancementMachine> ordonnancements;

    // CONSTRUCTEUR / DESTRUCTEUR

    /**
    * Créer un nouvel état avec m machines
    *
    * @param m le nombre de machines
    * @return un nouvel état
    */
    Etat(const int& m): m(m), cmax(0), ordonnancements(vector<OrdonnancementMachine>(m)) {}

    /**
    * Supprime un état.
    *
    */
    ~Etat() {}

    /**
     * Créer un nouvel état selon un état existant
     *
     * @param source  l'état depuis lequel on clone
     * @return un nouvel état
     */
    Etat(const Etat& source) = default;

    // FONCTIONS

    /**
     * Ajoute une tâche sur une machine.
     *
     * @param k la machine sur laquelle on ajoute la tâche
     * @param i l'id de la tâche que l'on ajoute
     * @param quantite la durée opératoire de la tâche i
     */
    void ajouterTacheSurMachine(const int& k, const int& i, const int& quantite);

    /**
     * Ajoute une tâche sur une machine depuis une instance.
     *
     * @param k la machine sur laquelle on ajoute la tâche
     * @param i l'id de la tâche que l'on ajoute
     * @param instance l'instance qui possède la tâche i
     */
    void ajouterTacheSurMachineParInstance(const Instance& instance, const int& k, const int& i);

    /**
     * Retourne l'état minimisant le cmax de l'ensemble d'états passés en paramètres
     *
     * @param etats l'ensemble d'états
     * @return l'état avec le cmax minimum
     */
    static Etat getEtatWithMinCmax(const vector<Etat>& etats);

    // SURCHARGES

    explicit operator string() const;

    bool operator==(const Etat& e) const;
};

inline ostream& operator<<(ostream & os, const Etat& etat)
{
    return(os << (string)etat);
}


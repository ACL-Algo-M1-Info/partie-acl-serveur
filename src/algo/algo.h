//
// Created by maxen on 29/12/2025.
//

#pragma once

// INCLUSIONS

#include "types/instance/instance.h"
#include "types/etat/etat.h"

// CLASSES

class Algo
{
public:

    // VARIABLES

    /** Instance utilisée dans les algorithmes */
    Instance instance;

    // CONSTRUCTEUR / DESTRUCTEUR

    explicit Algo(const Instance& instance): instance(instance) {}

    ~Algo() {}

    // FONCTIONS

    /**
     * Algo exact
     * Génére toutes les combinaisons de placement possible d'ordonnancement pour une instance de n tâche et m machine
     * Retourne la solution avec le cmax minimal (ne retourne pas l'état qui donne ce cmax minimal)
     * @param instance
     * @return le cmax minimal
     */
    Etat algoProgrammationDynamique();
};

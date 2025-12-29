//
// Created by maxen on 22/12/2025.
//

#pragma once

// INCLUSIONS

#include <vector>

#include "types/instance/instance.h"

// USINGS

using namespace std;

// CLASSES

class Utils
{
public:

    // FONCTIONS

    /**
     * Retrouve l'entier maximal dans l'array. L'array ne doit pas être vide
     * @param n Taille de l'array > 0
     * @param a Array
     * @return L'entier max dans l'array
     */
    static int maxArrayInt(int n, const int* a);

    template<class COMPARAISON>
    static void triFusion(int i, int j, Instance& instance, int* tp, COMPARAISON comparaison);

    /**
     * Applique l'ordre de Jackson sur les qi d'une instance
     *
     * @param instance l'instance où l'on veut appliquer l'ordre
     */
    static void triJackson(Instance& instance);
};

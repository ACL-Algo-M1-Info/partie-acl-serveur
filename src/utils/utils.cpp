//
// Created by maxen on 22/12/2025.
//

// INCLUSIONS

#include "utils.h"

#include "foncteurs/FoncteurUtils.h"

// FONCTIONS

int Utils::maxArrayInt(int n, const int* a)
{
    int res = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > res)
            res = a[i];
    }

    return res;
}


template <class COMPARAISON>
void Utils::triFusion(int i, int j, Instance& instance, int* tp, COMPARAISON comparaison)
{
    if (j <= i) return;

    // Milieu du tableau
    int m = (i + j) / 2;

    // Tri de la moitié gauche
    triFusion(i, m, instance, tp, comparaison);
    // Tri de la moitié droite
    triFusion(m + 1, j, instance, tp, comparaison);

    // Pointeur du sous tableau gauche
    int pg = i;
    // Pointeur du sous tableau droite
    int pd = m + 1;

    // Compteur
    int c;

    // Remplissage de i à j pour le tableau fusionné
    for (c = i; c <= j; c++)
    {
        if (pg == m + 1)
        {
            tp[c] = instance.p[pd];
            pd++;
        }
        else if (pd == j + 1)
        {
            tp[c] = instance.p[pg];
            pg++;
        }
        else if (comparaison(instance.p[pg], instance.p[pd]))
        {
            tp[c] = instance.p[pg];
            pg++;
        }
        else
        {
            tp[c] = instance.p[pd];
            pd++;
        }
    }

    // Copie des éléments dans tab
    for (c = i; c <= j; c++)
    {
        instance.p[c] = tp[c];
    }
}

void Utils::triJackson(Instance& instance)
{
    int tp[instance.n];
    EntierSuperieur entSup = EntierSuperieur();
    triFusion(0, instance.n - 1, instance, tp, entSup);
}


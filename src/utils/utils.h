//
// Created by maxen on 22/12/2025.
//

#pragma once
#include <iostream>
#include <map>
using namespace std;
// INCLUSIONS

// CLASSES

class Utils
{
   public:
    /**
     * Retrouve l'entier maximal dans l'array. L'array ne doit pas être vide
     * @param n Taille de l'array > 0
     * @param a Array
     * @return L'entier max dans l'array
     */
    static int maxArrayInt(int n, const int* a);

    /**
     * Cherche parmis les parents de i, le plus lointain ancêtre de i (la racine)
     * Possible de le faire en récursif avec cas de base : i == parent[i]
     * @tparam T
     * @param i
     * @param parents
     * @return la racine de i
     */
    template <class T>
    static T trouveRacine(T i, map<T, T>& parents)
    {
        while (i != parents[i])
        {
            i = parents[i];
        }
        return i;
    }
    /**
     * Trouve les racines de a et b
     * Si les deux racines sont différentes, racineB devient le parent de racineA
     * @tparam T
     * @param a
     * @param b
     * @param parents
     */
    template <class T>
    static void unionEnsemble(T a, T b, map<T, T> &parents)
    {
        T racineA = trouveRacine(a, parents);
        T racineB = trouveRacine(b, parents);

        if (racineA != racineB)
        {
            cout << "Le parent de " << racineA << " devient " << racineB << endl;
            parents[racineA] = racineB;
        }
    }
    template <class T>
    static void afficheMap(const map<T, T>& maMap)
    {
        cout << "Map : " << endl;
        typename map<T, T>::const_iterator it;
        for (it = maMap.begin(); it != maMap.end(); ++it)
        {
            cout << "Element " << it->first << " a pour parent " << it->second << endl;
        }
    }
};
